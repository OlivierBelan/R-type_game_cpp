/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioClient
*/

#pragma once

#include "AClient.hpp"
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "AGameServer.hpp"

namespace RType {
	class AsioClient : public boost::enable_shared_from_this<RType::AsioClient>, RType::AClient {
	public:
		AsioClient(boost::asio::io_service &io_service);
		~AsioClient();

	public:
		std::string getIpv4() const noexcept override;
		unsigned short getPort() const noexcept override;
		void send(const uint8_t *buffer, const std::size_t &len) noexcept override;

	public:
		static boost::shared_ptr<AsioClient> create(boost::asio::io_service &io_service) noexcept;
		boost::asio::ip::tcp::socket &socket() noexcept;
		void start(RType::AGameServer *server) noexcept;
		void receiver(const boost::system::error_code &error, size_t bytes_transferred) noexcept;

	private:
		boost::asio::ip::tcp::socket _socket;
		RType::AGameServer *_server;
		std::vector<std::uint8_t> _receive_buffer;
		std::string _ipv4 = "";
		unsigned short _port = 0;
	};
}; // namespace RType
