/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AGameServer
*/

#pragma once

#include "AClient.hpp"
#include <vector>
#include "GameEngine.hpp"

namespace RType {
	class AGameServer {
	public:
		AGameServer();
		virtual ~AGameServer() = default;

	public:
		void setConnectedPlayer(const std::size_t &id, const bool &connected, const bool &ready) noexcept;
		unsigned int getClientNewId() noexcept;
		void addClient(AClient *client) noexcept;
		void redirectReceivedMessage(AClient *client, std::vector<uint8_t> &message) noexcept;
		void sendToAllClient(const uint8_t *buffer, const std::size_t &len) noexcept;
		bool allPlayerReady() const noexcept;
		void AddLibToGameEngin(const std::string &libPath) noexcept;
		void RemoveLibToGameEngin(const std::string &libPath) noexcept;
		virtual void removeClient(AClient *client); // override this method if you need to handle your own clients BUT remove client from this class protected vector

	public:
		virtual void createNewGameInstance() noexcept = 0;
		virtual void start() noexcept = 0;
		virtual void stop() noexcept = 0;
		virtual void bind(const unsigned short int &port) = 0;
		virtual unsigned short int getUDPport() const noexcept = 0;
		virtual void closeTCPaccept() noexcept = 0;
		virtual void closeTCPsocket() noexcept = 0;
		virtual void startUDP() = 0;
		virtual void sendToAllClientUDP(const uint8_t *buffer, const std::size_t &len) = 0;

	protected:
		std::vector<AClient *> _clients;
		unsigned int _protected_game_id = 1;
		t_lobby _lobby_struct = {4242, 0, {false, false}, {false, false}, {false, false}, {false, false}};
		bool _udp = false;
		GameEngine _gameEngine;

	private:
		unsigned int _game_id;
		std::string _message;
	};
}; // namespace RType
