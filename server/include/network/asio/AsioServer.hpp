/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioServer
*/

#pragma once

#include "AServer.hpp"
#include "AsioGameServer.hpp"
#include <boost/asio.hpp>
#include <memory>

namespace RType {
	class AsioServer : public AServer {
	public:
		AsioServer();
		~AsioServer();

	public:
		virtual void run() noexcept override;
		virtual void stop() noexcept override;
		virtual void createGameInstance() noexcept override;

	private:
		boost::asio::io_service _io_service;
	};
}; // namespace RType
