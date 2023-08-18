/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioNetwork
*/

#include "AsioNetwork.hpp"
#include "Error.hpp"
#include <boost/bind.hpp>
#include "Window.hpp"

RType::AsioNetwork::AsioNetwork(Window &window) :
	_udp_socket(this->_io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)),
	_tcp_socket(this->_io_context),
	ANetwork(window)
{
}

RType::AsioNetwork::~AsioNetwork()
{
}

void RType::AsioNetwork::init(const std::string &ipv4, const unsigned short int &port)
{
	this->_ipv4 = ipv4;
	this->_port = port;
	try {
		this->_tcp_socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ipv4), port));
	} catch (std::exception &e) {
		throw Error(e.what());
	}
}

void RType::AsioNetwork::write(const uint8_t *buffer, const std::size_t &len)
{
	try {
		this->_tcp_socket.send(boost::asio::buffer(buffer, len));
	} catch (std::exception &e) {
		std::cerr << "write failed" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void RType::AsioNetwork::async_read()
{
	this->_receive_buffer.resize(sizeof(t_lobby));
	boost::asio::async_read(this->_tcp_socket, boost::asio::buffer(this->_receive_buffer), boost::asio::transfer_at_least(1), boost::bind(&RType::AsioNetwork::receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void RType::AsioNetwork::receiver(const boost::system::error_code &error, size_t bytes_transferred) noexcept
{
	if (error) {
		std::cerr << "Socket closed" << std::endl;
		return;
	}
	this->redirectMessage(this->_receive_buffer);
	this->_receive_buffer.clear();
	this->_receive_buffer.resize(sizeof(t_lobby));
	boost::asio::async_read(this->_tcp_socket, boost::asio::buffer(this->_receive_buffer), boost::asio::transfer_at_least(1), boost::bind(&RType::AsioNetwork::receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void RType::AsioNetwork::run()
{
	std::thread([this] {
		this->_io_context.run();
	})
		.detach();
	// this->setReady();
	// this->sendUDPmessage({4242, static_cast<player_enum>(this->_player_id), false, false, false, false, false});
}

void RType::AsioNetwork::stop()
{
	this->_io_context.stop();
}

unsigned short int RType::AsioNetwork::getUDPport() const noexcept
{
	return this->_udp_socket.local_endpoint().port();
}

void RType::AsioNetwork::startUDP()
{
	this->_receive_buffer.resize(sizeof(t_entity));
	this->_udp_socket.async_receive(boost::asio::buffer(this->_receive_buffer), boost::bind(&RType::AsioNetwork::UDP_receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void RType::AsioNetwork::UDP_receiver(const boost::system::error_code &error, const size_t &bytes_transferred)
{
	t_entity *entity_struct;
	entity_struct = reinterpret_cast<t_entity *>(this->_receive_buffer.data());

	this->handleUDPMessage(entity_struct);
	this->_receive_buffer.clear();
	this->_receive_buffer.resize(sizeof(t_entity));
	this->_udp_socket.async_receive(boost::asio::buffer(this->_receive_buffer), boost::bind(&RType::AsioNetwork::UDP_receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

inline const char *const BoolToString(bool b)
{
	return b ? "true" : "false";
}

void RType::AsioNetwork::sendUDPmessage(t_udp_client_message client_message)
{
	// std::cout << "ID: " << client_message.player << std::endl;
	// std::cout << "Up: " << BoolToString(client_message.up) << std::endl;
	// std::cout << "Down: " << BoolToString(client_message.down) << std::endl;
	// std::cout << "Left: " << BoolToString(client_message.left) << std::endl;
	// std::cout << "Right: " << BoolToString(client_message.right) << std::endl;
	// std::cout << "Action: " << BoolToString(client_message.action) << std::endl;
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&client_message);
	try {
		this->_udp_socket.send_to(boost::asio::buffer(
									  buffer, sizeof(t_udp_client_message)),
								  boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(this->_ipv4), this->_udp_port));
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
