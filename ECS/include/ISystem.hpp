/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** System
*/

#pragma once

#include "BasicComponent.hpp"
#include "IComponent.hpp"
#include "IEntity.hpp"
#include "struct.h"
// #include "IEntity.hpp"
// #include "Manager.hpp"
// #include "Player.hpp"
#include <cstring>
#include <iostream>
#include <memory>
#include <set>
namespace RType {
	class AGameServer;
}
namespace ECS {
	class Manager;
	class ISystem {
	public:
		ISystem(int priority, std::set<ComponentType> componentType) :
			_priority(priority),
			_componentType(componentType){};
		virtual ~ISystem(){};
		std::set<ComponentType> getComponentType()
		{
			return _componentType;
		};
		int getPriority() const
		{
			return _priority;
		};
		std::shared_ptr<Manager> getManager()
		{
			return _manager;
		};
		std::set<Entity> getEntities()
		{
			return _entities;
		}
		bool addEntity(Entity entity)
		{
			_entities.insert(entity);
		};
		bool removeEntity(Entity entity)
		{
			_entities.erase(entity);
		}
		// virtual bool
		virtual bool update() = 0;
		virtual bool init(){};
		// virtual void initManagerandNetWork(std::shared_ptr<Manager> manager, RType::AGameServer *gameserver)
		// {
		// 	_manager = manager;
		// 	_gameServer = gameserver;
		// };
		// virtual void sendToServer(ECS::Entity id) {
		// 	_messageSend.id = id;
		// 	_messageSend.posX = _manager->getComponent<Basic::BasicCompopenent::C_Position>(id)->_posX;
		// 	_messageSend.posY = _manager->getComponent<Basic::BasicCompopenent::C_Position>(id)->_posY;
		// 	_messageSend.speed = _manager->getComponent<Basic::BasicCompopenent::C_Speed>(id)->_speed;
		// 	std::strcpy(_messageSend.sprite, _manager->getComponent<Basic::BasicCompopenent::C_Sprite>(id)->_sprite);
		// 	_gameServer->
		// }
		virtual void printInfoSysteme(std::string name)
		{
			std::cout << std::endl
					  << "FROM " << name << std::endl;
			std::cout << "SIZE ENTITIES = " << _entities.size() << " IDs = ";
			if (!_entities.empty()) {
				for (auto it : _entities) {
					std::cout << it << " ";
				}
			} else {
				std::cout << "NONE";
			}
			std::cout << std::endl;
		}

	protected:
		const int _priority;
		std::set<Entity> _entities;
		std::set<ComponentType> _componentType;
		std::shared_ptr<Manager> _manager;
		t_entity _messageSend;
		RType::AGameServer *_gameServer;
		// t_entity _messageSend;
		// RType::AGameServer *_gameServer;

	private:
	};

} // namespace ECS