/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AGameServer
*/

#include "AGameServer.hpp"
#include "Error.hpp"
#include <string.h>
#include <thread>

bool RType::AGameServer::allPlayerReady() const noexcept
{
	if (this->_lobby_struct.player_1.connected)
		if (!this->_lobby_struct.player_1.ready)
			return false;
	if (this->_lobby_struct.player_2.connected)
		if (!this->_lobby_struct.player_2.ready)
			return false;
	if (this->_lobby_struct.player_3.connected)
		if (!this->_lobby_struct.player_3.ready)
			return false;
	if (this->_lobby_struct.player_3.connected)
		if (!this->_lobby_struct.player_3.ready)
			return false;
	return true;
}

unsigned int RType::AGameServer::getClientNewId() noexcept
{
	unsigned int id = 1;
	bool loop = true;

	while (loop) {
		loop = false;
		for (auto &Elem : this->_clients) {
			if (Elem->getId() == id) {
				id++;
				loop = true;
			}
		}
	}
	return id;
}

void RType::AGameServer::setConnectedPlayer(const std::size_t &id, const bool &connected, const bool &ready) noexcept
{
	switch (id) {
		case 1:
			this->_lobby_struct.player_1.connected = connected;
			this->_lobby_struct.player_1.ready = ready;
			break;
		case 2:
			this->_lobby_struct.player_2.connected = connected;
			this->_lobby_struct.player_2.ready = ready;
			break;
		case 3:
			this->_lobby_struct.player_3.connected = connected;
			this->_lobby_struct.player_3.ready = ready;
			break;
		case 4:
			this->_lobby_struct.player_4.connected = connected;
			this->_lobby_struct.player_4.ready = ready;
			break;
		default:
			break;
	}
}

void RType::AGameServer::sendToAllClient(const uint8_t *buffer, const std::size_t &len) noexcept
{
	for (auto &Elem : this->_clients)
		Elem->send(buffer, len);
}

RType::AGameServer::AGameServer() :
	_gameEngine(*this)
{
	this->_game_id = this->_protected_game_id;
	// this->_gameEngine.init();
	// std::thread([this]() {
	// 	this->_gameEngine.run();
	// }).detach();
}

void RType::AGameServer::redirectReceivedMessage(AClient *client, std::vector<uint8_t> &message) noexcept
{
	// if all player are connected, retrieve players UDP port then return
	if (this->_udp) {
		t_lobby_udp *resp;
		resp = reinterpret_cast<t_lobby_udp *>(message.data());
		if (resp->magic_number != 4242)
			return;
		client->setUDP(resp->udp_port);
		for (auto &Elem : this->_clients)
			if (Elem->getUDP() == 0)
				return;
		// if all clients has sent there UDP port
		this->closeTCPsocket();
		this->startUDP();
		std::thread([this]() {
			this->_gameEngine.run(this->_clients.size());
		})
			.detach();
		return;
	}

	t_lobby_resp *resp;
	resp = reinterpret_cast<t_lobby_resp *>(message.data());
	if (resp->magic_number != 4242)
		return;

	this->setConnectedPlayer(client->getId(), true, resp->ready);

	// send new lobby to all players
	for (auto &Elem : this->_clients) {
		this->_lobby_struct.player_id = Elem->getId();
		uint8_t *buffer = reinterpret_cast<uint8_t *>(&this->_lobby_struct);
		Elem->send(buffer, sizeof(t_lobby));
	}

	// if all players are connected, send the special udp struct then going to udp mode
	if (this->allPlayerReady()) {
		this->_protected_game_id++;
		this->createNewGameInstance();
		t_lobby_udp lobby_udp_struct = {4242, this->getUDPport()};
		uint8_t *buffer = reinterpret_cast<uint8_t *>(&lobby_udp_struct);
		this->sendToAllClient(buffer, sizeof(t_lobby_udp));
		this->closeTCPaccept();
		this->_udp = true;
	}
}

void RType::AGameServer::addClient(AClient *client) noexcept
{
	this->_clients.push_back(client);

	std::cerr << "New connection from : " << client->getIpv4() << ":" << client->getPort() << " (" << this->_clients.size() << "/4)" << std::endl;

	client->setId(this->getClientNewId());
	this->setConnectedPlayer(client->getId(), true, false);
	uint8_t *buffer = reinterpret_cast<uint8_t *>(&this->_lobby_struct);

	// send new lobby to all players
	for (auto &Elem : this->_clients) {
		this->_lobby_struct.player_id = Elem->getId();
		uint8_t *buffer = reinterpret_cast<uint8_t *>(&this->_lobby_struct);
		Elem->send(buffer, sizeof(t_lobby));
	}
}

void RType::AGameServer::removeClient(AClient *client)
{
	// don't remove client if udp mode is actif
	if (this->_udp)
		return;

	this->setConnectedPlayer(client->getId(), false, false);

	std::cerr << "Lobby n°" << this->_game_id << " Removing client : " << client->getIpv4() << ":" << client->getPort() << std::endl;

	for (auto it = this->_clients.begin(); it != this->_clients.end(); it++) {
		if ((*it) == client) {
			this->_clients.erase(it);
			it = this->_clients.end() - 1;
		}
	}

	// send new lobby to all players
	for (auto &Elem : this->_clients) {
		this->_lobby_struct.player_id = Elem->getId();
		uint8_t *buffer = reinterpret_cast<uint8_t *>(&this->_lobby_struct);
		Elem->send(buffer, sizeof(t_lobby));
	}
}

std::string getBinaryDir();

void RType::AGameServer::AddLibToGameEngin(const std::string &libPath) noexcept
{
	try {
		this->_gameEngine.addLibrary(getBinaryDir() + "lib/" + libPath);
	} catch (Error &e) {
		std::cerr << e.what() << std::endl;
	}
}

void RType::AGameServer::RemoveLibToGameEngin(const std::string &libPath) noexcept
{
	try {
		this->_gameEngine.removeLibrary(getBinaryDir() + "lib/" + libPath);
	} catch (Error &e) {
		std::cerr << e.what() << std::endl;
	}
}