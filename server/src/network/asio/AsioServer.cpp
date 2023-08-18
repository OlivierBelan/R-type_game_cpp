/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AsioServer
*/

#include "AsioServer.hpp"

RType::AsioServer::AsioServer()
{
}

RType::AsioServer::~AsioServer()
{
}

void RType::AsioServer::run() noexcept
{
	this->_io_service.run();
}

void RType::AsioServer::stop() noexcept
{
	this->_gameServer.clear();
	this->_io_service.stop();
}

void RType::AsioServer::createGameInstance() noexcept
{
	std::shared_ptr<RType::AsioGameServer> asio_game_server(new RType::AsioGameServer(this->_io_service, this));

	// init pre selected systems for new game instance
	for (auto &Elem : this->_selectedSystems) {
		asio_game_server->AddLibToGameEngin(Elem.second);
	}
	std::thread t([this, &asio_game_server] {
		asio_game_server->start();
	});
	this->_gameServer.push_back(asio_game_server);
	t.join();
}
