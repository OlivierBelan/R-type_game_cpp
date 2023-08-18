/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioGameServer
*/

#pragma once

#include "AGameServer.hpp"
#include "AServer.hpp"
#include "AsioClient.hpp"
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace RType {
	class AsioGameServer : public AGameServer {
	public:
		AsioGameServer(boost::asio::io_service &io_service, RType::AServer *server);
		~AsioGameServer();

	public:
		virtual void start() noexcept override;
		virtual void stop() noexcept override;
		virtual void bind(const unsigned short int &port) override;
		virtual void createNewGameInstance() noexcept override;
		void removeClient(AClient *client) override;
		virtual unsigned short int getUDPport() const noexcept override;
		virtual void closeTCPaccept() noexcept override;
		virtual void closeTCPsocket() noexcept override;
		virtual void startUDP() override;
		virtual void sendToAllClientUDP(const uint8_t *buffer, const std::size_t &len) override;

	public:
		void accept() noexcept;


	private:
		void handleAccept(boost::shared_ptr<AsioClient> new_connection, const boost::system::error_code &error) noexcept;
		void UDP_receiver(const boost::system::error_code &error, const size_t &bytes);


	private:
		unsigned int _game_id;
		RType::AServer *_server;
		std::vector<boost::shared_ptr<RType::AsioClient>> _asioClients;
		boost::asio::io_service &_io_service;
		std::vector<std::uint8_t> _receive_buffer;
		boost::asio::ip::tcp::acceptor _acceptor;
		boost::asio::ip::udp::socket _udp_socket;

	};
}; // namespace RType
