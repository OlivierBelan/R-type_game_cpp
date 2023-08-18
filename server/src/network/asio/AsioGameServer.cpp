/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioGameServer
*/

#include "AsioGameServer.hpp"
#include "Error.hpp"
#include <boost/bind.hpp>

RType::AsioGameServer::AsioGameServer(boost::asio::io_service &io_service, RType::AServer *server) :
	_acceptor(io_service),
	_io_service(io_service),
	_udp_socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)),
	_server(server)
{
	this->_game_id = this->_protected_game_id;
}

RType::AsioGameServer::~AsioGameServer()
{
	this->_asioClients.clear();
}

void RType::AsioGameServer::start() noexcept
{
	this->bind(0);
	this->accept();
}

void RType::AsioGameServer::stop() noexcept
{
	this->_asioClients.clear();
}

void RType::AsioGameServer::bind(const unsigned short &port)
{
	try {
		this->_acceptor = boost::asio::ip::tcp::acceptor(this->_io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
	} catch (std::exception &e) {
		throw Error(e.what());
	}
	std::cout << "New Game Lobby, Listening on : " << this->_acceptor.local_endpoint().address().to_string() << ":" << this->_acceptor.local_endpoint().port() << std::endl;
}

void RType::AsioGameServer::accept() noexcept
{
	boost::shared_ptr<RType::AsioClient> new_connection = RType::AsioClient::create(this->_io_service);
	this->_acceptor.async_accept(new_connection->socket(), boost::bind(&RType::AsioGameServer::handleAccept, this, new_connection, boost::asio::placeholders::error));
}

void RType::AsioGameServer::handleAccept(boost::shared_ptr<AsioClient> new_connection, const boost::system::error_code &error) noexcept
{
	if (error) {
		std::cerr << error.message() << std::endl;
		return;
	}
	if (this->_asioClients.size() >= 4) {
		return this->accept();
	}
	this->_asioClients.push_back(new_connection);
	new_connection->start(this);
	this->accept();
}

void RType::AsioGameServer::removeClient(AClient *client)
{
	if (this->_udp)
		return;
	this->setConnectedPlayer(client->getId(), false, false);

	std::cerr << "Lobby n°" << this->_game_id << " Removing client : " << client->getIpv4() << ":" << client->getPort() << " (" << this->_clients.size() - 1 << "/4)" << std::endl;
	for (auto it = this->_clients.begin(); it != this->_clients.end(); it++) {
		if ((*it) == client) {
			this->_clients.erase(it);
			it = this->_clients.end() - 1;
		}
	}
	for (auto it = this->_asioClients.begin(); it != this->_asioClients.end(); it++) {
		if ((*it)->getIpv4() == client->getIpv4() && (*it)->getPort() == client->getPort()) {
			this->_asioClients.erase(it);
			it = this->_asioClients.end() - 1;
		}
	}
	for (auto &Elem : this->_clients) {
		this->_lobby_struct.player_id = Elem->getId();
		uint8_t *buffer = reinterpret_cast<uint8_t *>(&this->_lobby_struct);
		Elem->send(buffer, sizeof(t_lobby));
	}
}

void RType::AsioGameServer::createNewGameInstance() noexcept
{
	this->_server->createGameInstance();
}

unsigned short RType::AsioGameServer::getUDPport() const noexcept
{
	return this->_udp_socket.local_endpoint().port();
}

void RType::AsioGameServer::closeTCPaccept() noexcept
{
	this->_acceptor.close();
}

void RType::AsioGameServer::closeTCPsocket() noexcept
{
	for (auto &Elem : this->_asioClients)
		Elem->socket().close();
}

void RType::AsioGameServer::startUDP()
{
	this->_receive_buffer.resize(sizeof(t_udp_client_message));
	this->_udp_socket.async_receive(boost::asio::buffer(this->_receive_buffer), boost::bind(&RType::AsioGameServer::UDP_receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void RType::AsioGameServer::UDP_receiver(const boost::system::error_code &error, const size_t &bytes_transferred)
{
	t_udp_client_message *udp_message_struct;
	udp_message_struct = reinterpret_cast<t_udp_client_message *>(this->_receive_buffer.data());

	// redirect UDP message to the Game Engine
	this->_gameEngine.receiveMessage(udp_message_struct);

	this->_receive_buffer.clear();
	this->_receive_buffer.resize(sizeof(t_udp_client_message));	
	this->_udp_socket.async_receive(boost::asio::buffer(this->_receive_buffer), boost::bind(&RType::AsioGameServer::UDP_receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void RType::AsioGameServer::sendToAllClientUDP(const uint8_t *buffer, const std::size_t &len)
{
	for (auto &Elem : this->_clients) {
		try {
			this->_udp_socket.send_to(boost::asio::buffer(buffer, len),
									  boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(Elem->getIpv4()), Elem->getUDP()));
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
