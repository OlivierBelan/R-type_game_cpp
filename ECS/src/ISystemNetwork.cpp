/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ISystemNetwork
*/

#include "ISystemNetwork.hpp"
#include "AGameServer.hpp"
// #include "ComponentType.hpp"
// ISystemNetwork::ISystemNetwork()
// {
// }

// ISystemNetwork::~ISystemNetwork()
// {
// }

void ISystemNetwork::sendToServer(ECS::Entity id)
{
	if (id != 0) {
		_messageSend.id = id;
		_messageSend.posX = _manager->getComponent<Basic::BasicComponent::C_Position>(id)->_posX;
		_messageSend.posY = _manager->getComponent<Basic::BasicComponent::C_Position>(id)->_posY;
		_messageSend.speed = _manager->getComponent<Basic::BasicComponent::C_Speed>(id)->_speed;
		_messageSend.render = _manager->getComponent<Basic::BasicComponent::C_Event>(id)->render;
		_messageSend.magic_number = 4242;
		_messageSend.up = _manager->getComponent<Basic::BasicComponent::C_Event>(id)->moveUp;
		_messageSend.down = _manager->getComponent<Basic::BasicComponent::C_Event>(id)->moveDown;
		_messageSend.right = _manager->getComponent<Basic::BasicComponent::C_Event>(id)->moveRight;
		_messageSend.left = _manager->getComponent<Basic::BasicComponent::C_Event>(id)->moveLeft;
		std::strcpy(_messageSend.sprite, _manager->getComponent<Basic::BasicComponent::C_Sprite>(id)->_sprite.c_str());
		std::cout << _messageSend.id;
		uint8_t *buffer = reinterpret_cast<uint8_t *>(&_messageSend);
		// if (_messageSend.render == true)
		// 	std::cout << "RENDER = TRUE" << std::endl;
		// else
		// 	std::cout << "RENDER = FALSE" << std::endl;
		_gameServer->sendToAllClientUDP(buffer, sizeof(_messageSend));
	}
}
