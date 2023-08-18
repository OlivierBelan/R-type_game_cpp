/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ISystemNetwork
*/

#pragma once

#include "Manager.hpp"
#include "BasicComponent.hpp"
#include "IComponent.hpp"
#include "IEntity.hpp"
#include "Player.hpp"

// #include "struct.h"
// namespace RType {
// 	class AGameServer;
// }
class ISystemNetwork : public ECS::ISystem {
public:
	ISystemNetwork(int priority, std::set<ComponentType> componentType):
    ECS::ISystem(priority, componentType) {}
	~ISystemNetwork(){};
	virtual void initManagerandNetWork(std::shared_ptr<ECS::Manager> manager, RType::AGameServer *gameserver)
	{
		_manager = manager;
		_gameServer = gameserver;
	};
	virtual void sendToServer(ECS::Entity id);
	// {
	// 	_messageSend.id = id;
	// 	_messageSend.posX = _manager->getComponent<Basic::BasicComponent::C_Position>(id)->_posX;
	// 	_messageSend.posY = _manager->getComponent<Basic::BasicComponent::C_Position>(id)->_posY;
	// 	_messageSend.speed = _manager->getComponent<Basic::BasicComponent::C_Speed>(id)->_speed;
	// 	_messageSend.render = _manager->getComponent<Basic::BasicComponent::C_Event>(id)->render;
	// 	std::strcpy(_messageSend.sprite, _manager->getComponent<Basic::BasicComponent::C_Sprite>(id)->_sprite);
    //     std::cout << _messageSend.id;
    //     uint8_t *buffer = reinterpret_cast<uint8_t *>(&_messageSend);
    //     _gameServer->sendToAllClientUDP(buffer, sizeof(_messageSend));
    // }
    virtual bool update(){};
protected:
	// RType::AGameServer *_gameServer;

private:
};
