/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ANetwork
*/

#include "ANetwork.hpp"
#include "Window.hpp"

RType::ANetwork::ANetwork(Window &win) :
_window(win),
_update(false)
{
}

RType::ANetwork::~ANetwork()
{
}

bool RType::ANetwork::allPlayerReady(t_lobby *lobby_struct) const noexcept
{
	if (lobby_struct->player_1.connected)
		if (!lobby_struct->player_1.ready)
			return false;
	if (lobby_struct->player_2.connected)
		if (!lobby_struct->player_2.ready)
			return false;
	if (lobby_struct->player_3.connected)
		if (!lobby_struct->player_3.ready)
			return false;
	if (lobby_struct->player_3.connected)
		if (!lobby_struct->player_3.ready)
			return false;
	return true;
}

t_lobby RType::ANetwork::getLobbyStatus(void) noexcept
{
	return this->_lobby_status;
}

void RType::ANetwork::redirectMessage(std::vector<std::uint8_t> &receive_buffer)
{
	// if all players are ready, reading server UDP port
	if (this->_lobby_ready == true) {
		t_lobby_udp *lobby_udp_struct;
		lobby_udp_struct = reinterpret_cast<t_lobby_udp *>(receive_buffer.data());
		if (lobby_udp_struct->magic_number != 4242) {
			std::cerr << "Error while decodding received message" << std::endl;
			return;
		}
		this->_udp_port = lobby_udp_struct->udp_port;
		this->startUDP();
		return;
	}

	t_lobby *lobby_struct;
	lobby_struct = reinterpret_cast<t_lobby *>(receive_buffer.data());

	if (lobby_struct->magic_number != 4242)
		return;
	this->_player_id = lobby_struct->player_id;
	// UPDATE SFML GRAPHICAL INFORMATIONS ABOUT THE CONNECTED USERS HERE
	this->_lobby_status = *lobby_struct;
	this->_update = true;

	// if all players are ready, sending client UDP port to server
	if (this->allPlayerReady(lobby_struct)) {
		this->sendUDPport();
		this->_lobby_ready = true;
	}
}

void RType::ANetwork::sendUDPport() noexcept
{
	t_lobby_udp lobby_udp_struct = {4242, this->getUDPport()};
	const uint8_t *buffer = reinterpret_cast<const uint8_t *>(&lobby_udp_struct);
	this->write(buffer, sizeof(t_lobby_udp));
}

void RType::ANetwork::handleUDPMessage(const t_entity *entity_struct)
{
	if (entity_struct->magic_number != 4242)
		return;
	this->_window.handleNewEntity(*entity_struct);
	// std::cout << "HANDLE SFML RENDER HERE" << std::endl;
	// std::cout << "struct id : " << entity_struct->id << " posX = " << entity_struct->posX << " posY = " << entity_struct->posY << std::endl;
}

void RType::ANetwork::setReady()
{
	this->_ready = !this->_ready;
	t_lobby_resp resp = {4242, this->_ready};
	const uint8_t *buffer = reinterpret_cast<const uint8_t *>(&resp);
	this->write(buffer, sizeof(t_lobby_resp));
}