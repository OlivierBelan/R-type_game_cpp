/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioNetwork
*/

#pragma once

#include "ANetwork.hpp"
#include <boost/asio.hpp>
#include "IRenderWindow.hpp"

class Window;

namespace RType {
	class AsioNetwork : public ANetwork {
	public:
		AsioNetwork(Window &);
		~AsioNetwork();

	public:
		virtual void async_read() override;
		virtual void run() override;
		virtual void init(const std::string &ipv4, const unsigned short int &port) override;
		virtual void stop() override;
		virtual void sendUDPmessage(t_udp_client_message) override;
		virtual void write(const uint8_t *buffer, const std::size_t &len) override;
		virtual void startUDP() override;
		virtual unsigned short int getUDPport() const noexcept override;

	private:
		void receiver(const boost::system::error_code &error, size_t bytes_transferred) noexcept;
		void UDP_receiver(const boost::system::error_code &error, const size_t &bytes);

	private:
		std::string _ipv4;
		unsigned short _port;
		boost::asio::io_context _io_context;
		boost::asio::ip::tcp::socket _tcp_socket;
		boost::asio::ip::udp::socket _udp_socket;
		std::vector<std::uint8_t> _receive_buffer;
	};
}; // namespace RType
