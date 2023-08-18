/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioClient
*/

#include "AsioClient.hpp"
#include <boost/bind.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <iostream>

RType::AsioClient::AsioClient(boost::asio::io_service &io_service) :
	_socket(io_service)
{
}

RType::AsioClient::~AsioClient()
{
	this->_socket.close();
}

boost::shared_ptr<RType::AsioClient> RType::AsioClient::create(boost::asio::io_service &io_service) noexcept
{
	return boost::shared_ptr<AsioClient>(new RType::AsioClient(io_service));
}

boost::asio::ip::tcp::socket &RType::AsioClient::socket() noexcept
{
	return this->_socket;
}

void RType::AsioClient::send(const uint8_t *buffer, const std::size_t &len) noexcept
{
	try {
		this->_socket.send(boost::asio::buffer(buffer, len));
	} catch (std::exception &e) {
		std::cerr << this->getIpv4() << ":" << this->getPort() << " : " << e.what() << std::endl;
	}
}

void RType::AsioClient::start(RType::AGameServer *server) noexcept
{
	this->_server = server;
	this->_ipv4 = this->_socket.remote_endpoint().address().to_string();
	this->_port = this->_socket.remote_endpoint().port();
	this->_server->addClient(this);
	this->_receive_buffer.resize(sizeof(t_lobby_resp));
	boost::asio::async_read(this->_socket, boost::asio::buffer(this->_receive_buffer), boost::asio::transfer_at_least(1), boost::bind(&RType::AsioClient::receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void RType::AsioClient::receiver(const boost::system::error_code &error, size_t bytes_transferred) noexcept
{
	if (error) {
		this->_server->removeClient(this);
		return;
	}
	this->_server->redirectReceivedMessage(this, this->_receive_buffer);
	this->_receive_buffer.clear();
	this->_receive_buffer.resize(sizeof(t_lobby_resp));
	boost::asio::async_read(this->_socket, boost::asio::buffer(this->_receive_buffer), boost::asio::transfer_at_least(1), boost::bind(&RType::AsioClient::receiver, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

std::string RType::AsioClient::getIpv4() const noexcept
{
	return this->_ipv4;
}

unsigned short RType::AsioClient::getPort() const noexcept
{
	return this->_port;
}