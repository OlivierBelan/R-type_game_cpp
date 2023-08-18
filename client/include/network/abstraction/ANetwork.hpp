/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ANetwork
*/

#pragma once

#include "struct.h"
#include <iostream>
#include <vector>

class Window;

namespace RType {
	class ANetwork {
	public:
		ANetwork(Window &);
		~ANetwork();

	public:
		virtual void init(const std::string &ipv4, const unsigned short int &port) = 0;
		virtual void write(const uint8_t *buffer, const std::size_t &len) = 0;
		virtual void async_read() = 0;
		virtual void run() = 0;
		virtual void stop() = 0;
		virtual unsigned short int getUDPport() const noexcept = 0;
		virtual void startUDP() = 0;
		virtual void sendUDPmessage(t_udp_client_message) = 0;

	public:
		void handleUDPMessage(const t_entity *);
		void setReady();
		void redirectMessage(std::vector<std::uint8_t> &receive_buffer);
		bool allPlayerReady(t_lobby *lobby_struct) const noexcept;
		void sendUDPport() noexcept;
		int getPlayerId(void) const noexcept { return this->_player_id; }

		t_lobby getLobbyStatus(void) noexcept;
		bool getUpdate(void) const noexcept { return this->_update; }
		void setUpdate(bool update) noexcept { this->_update = update; }
		bool getLobbyReady(void) const noexcept { return this->_lobby_ready; }

	protected:
		bool _update;
		t_lobby _lobby_status;
		int _player_id = player_enum::PLAYER_1;
		bool _ready = false;
		bool _lobby_ready = false;
		unsigned short _udp_port;

	public:
		Window &_window;
	};
}; // namespace RType
