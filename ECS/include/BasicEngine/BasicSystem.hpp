/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BasicSystem
*/

#pragma once

// #include "BasicComponent.hpp"
// #include "IComponent.hpp"
// #include "IEntity.hpp"
// #include "Manager.hpp"
// #include "Player.hpp"
#include "ISystemNetwork.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <set>
#include <vector>
#ifdef unix
#include <dirent.h>
#include <unistd.h>
#endif

namespace Basic {
	namespace BasicSystem {
		class Move : public ISystemNetwork {
		public:
			Move(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~Move(){};
			virtual bool update() override
			{
				for (auto it : _entities) {
					if (_manager->getComponent<BasicComponent::C_Event>(it)->moveUp) {
						sendToServer(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posY -= _manager->getComponent<BasicComponent::C_Speed>(it)->_speed;
						_manager->getComponent<BasicComponent::C_Event>(it)->moveUp = false;
					}
					if (_manager->getComponent<BasicComponent::C_Event>(it)->moveDown) {
						sendToServer(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posY += _manager->getComponent<BasicComponent::C_Speed>(it)->_speed;
						_manager->getComponent<BasicComponent::C_Event>(it)->moveDown = false;
					}
					if (_manager->getComponent<BasicComponent::C_Event>(it)->moveRight) {
						sendToServer(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posX += _manager->getComponent<BasicComponent::C_Speed>(it)->_speed;
						_manager->getComponent<BasicComponent::C_Event>(it)->moveRight = false;
					}
					if (_manager->getComponent<BasicComponent::C_Event>(it)->moveLeft) {
						sendToServer(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posX -= _manager->getComponent<BasicComponent::C_Speed>(it)->_speed;
						_manager->getComponent<BasicComponent::C_Event>(it)->moveLeft = false;
					}
				}
				// printInfoSysteme("Move");
			};
		};

		class Speed : public ISystemNetwork {
		public:
			Speed(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~Speed(){};
			virtual bool update() override
			{
				for (auto it : _entities) {
					if (_manager->getComponent<BasicComponent::C_Event>(it)->speedUp == true) {
						_manager->getComponent<BasicComponent::C_Speed>(it)->_speed += _manager->getComponent<BasicComponent::C_Speed>(it)->_speedUp;
					}
					if (_manager->getComponent<BasicComponent::C_Event>(it)->speedDown == false) {
						_manager->getComponent<BasicComponent::C_Speed>(it)->_speed += _manager->getComponent<BasicComponent::C_Speed>(it)->_speedDown;
					}
				}
				// printInfoSysteme("Speed")
			};
		};
		class CreateEntityType : public ISystemNetwork {
		public:
			CreateEntityType(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~CreateEntityType(){};
			virtual bool init() override
			{
				BasicComponent::C_Event event;
				BasicComponent::C_Life life;
				BasicComponent::C_Speed speed;
				BasicComponent::C_Position position;
				BasicComponent::C_Sprite sprite;
				BasicComponent::C_Info info;
				BasicComponent::C_Box box;
				box.height = 40;
				box.width = 40;
				auto newEntity = _manager->createEntity();
				_manager->addComponentToEntity(newEntity, std::make_shared<BasicComponent::C_Event>(event),
											   std::make_shared<BasicComponent::C_Life>(life),
											   std::make_shared<BasicComponent::C_Speed>(speed),
											   std::make_shared<BasicComponent::C_Position>(position),
											   std::make_shared<BasicComponent::C_Sprite>(sprite),
											   std::make_shared<BasicComponent::C_Info>(info),
											   std::make_shared<BasicComponent::C_Box>(box));
				_manager->addEntityToSystem(newEntity);
				_manager->getComponent<BasicComponent::C_Event>(newEntity)->render = true;
				// printInfoSysteme("CreateEntityType");
			};
			virtual bool update() override{};
		};
		class CreatePlayer : public ISystemNetwork {
		public:
			CreatePlayer(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~CreatePlayer(){};
			virtual bool init() override
			{
				if (_asset.empty()) {
					_asset.push_back("blue_ship.png");
					_asset.push_back("red_ship.png");
					_asset.push_back("yellow_ship.png");
					_asset.push_back("green_ship.png");
				}
			}
			virtual bool update() override
			{
				Basic::EntityType::Player player;
				auto entities = _entities;
				for (auto it : entities) {
					if (_manager->getComponent<BasicComponent::C_Info>(it)->player == true) {
						_manager->addComponentToEntity(it, std::make_shared<Basic::EntityType::Player>(player));
						_manager->getComponent<Basic::EntityType::Player>(it)->id = it;
						_manager->destroyComponentFromEntity(it, BasicComponent::C_Info::type);
						_manager->addEntityToSystem(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posX = 200;
						_manager->getComponent<BasicComponent::C_Position>(it)->_posY = 200;
						_manager->getComponent<BasicComponent::C_Life>(it)->_life = 200;
						_manager->getComponent<BasicComponent::C_Sprite>(it)->_sprite = _asset[_nbPlayer];
						_nbPlayer++;
						sendToServer(it);
					}
				}
				// printInfoSysteme("CreatePlayer");
			};
			int _nbPlayer = 0;
			std::vector<std::string> _asset;
		};
		class CreateMonster : public ISystemNetwork {
		public:
			CreateMonster(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~CreateMonster(){};
			virtual bool init() override
			{
				if (_asset.empty()) {
					_asset.push_back("monster1.png");
					_asset.push_back("monster2.png");
					_asset.push_back("monster3.png");
					_asset.push_back("monster4.png");
				}
			}
			virtual bool update() override
			{
				Basic::EntityType::Monster monster;
				auto entities = _entities;
				for (auto it : entities) {
					if (_manager->getComponent<BasicComponent::C_Info>(it)->monster == true) {
						_manager->addComponentToEntity(it, std::make_shared<Basic::EntityType::Monster>(monster));
						_manager->getComponent<Basic::EntityType::Monster>(it)->id = it;
						_manager->destroyComponentFromEntity(it, BasicComponent::C_Info::type);
						_manager->addEntityToSystem(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posX = 1000;
						_manager->getComponent<BasicComponent::C_Position>(it)->_posY = std::rand() % (500 - 100 + 1) + 100;
						_manager->getComponent<BasicComponent::C_Event>(it)->moveLeft = true;
						// _manager->getComponent<BasicComponent::C_Speed>(it)->_speed = 100 + entities.size() / 2;
						_manager->getComponent<BasicComponent::C_Life>(it)->_life = 50;
						_manager->getComponent<BasicComponent::C_Sprite>(it)->_sprite = _asset[std::rand() % (3 - 0 + 1) + 0];
						sendToServer(it);
					}
				}
				// printInfoSysteme("CreateMonster");
			};
			std::vector<std::string> _asset;
		};

		class CreateWall : public ISystemNetwork {
		public:
			CreateWall(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~CreateWall(){};

			virtual bool update() override
			{
				Basic::EntityType::Wall wall;
				auto entities = _entities;
				for (auto it : entities) {
					if (_manager->getComponent<BasicComponent::C_Info>(it)->wall == true) {
						_manager->addComponentToEntity(it, std::make_shared<Basic::EntityType::Wall>(wall));
						_manager->getComponent<Basic::EntityType::Wall>(it)->id = it;
						_manager->destroyComponentFromEntity(it, BasicComponent::C_Info::type);
						_manager->addEntityToSystem(it);
						_manager->getComponent<BasicComponent::C_Position>(it)->_posX = std::rand() % (1000 - 100 + 1) + 100;
						_manager->getComponent<BasicComponent::C_Position>(it)->_posY = 0;
						_manager->getComponent<BasicComponent::C_Life>(it)->_life = 50;
						_manager->getComponent<BasicComponent::C_Sprite>(it)->_sprite = "asteroid.png";
						sendToServer(it);
					}
				}
				// printInfoSysteme("CreateWall");
			};
		};
		class CreateFire : public ISystemNetwork {
		public:
			CreateFire(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~CreateFire(){};
			virtual bool update() override
			{
				Basic::EntityType::Fire fire;
				auto entities = _entities;
				auto players = _manager->getComponentManager(Type::PLAYER)->getAllEntitites();
				for (auto it : entities) {
					if (_manager->getComponent<BasicComponent::C_Info>(it)->fire == true) {
						_manager->addComponentToEntity(it, std::make_shared<Basic::EntityType::Fire>(fire));
						_manager->getComponent<Basic::EntityType::Fire>(it)->id = it;
						_manager->destroyComponentFromEntity(it, BasicComponent::C_Info::type);
						_manager->addEntityToSystem(it);
						_manager->getComponent<BasicComponent::C_Event>(it)->moveRight = true;
						for (auto player : players) {
							if (_manager->getComponent<BasicComponent::C_Event>(player)->fire) {
								_manager->getComponent<BasicComponent::C_Position>(it)->_posX = _manager->getComponent<BasicComponent::C_Position>(player)->_posX + 150;
								_manager->getComponent<BasicComponent::C_Position>(it)->_posY = _manager->getComponent<BasicComponent::C_Position>(player)->_posY;
								_manager->getComponent<BasicComponent::C_Event>(player)->fire = false;
								_manager->getComponent<BasicComponent::C_Life>(it)->_life = 50;
								_manager->getComponent<BasicComponent::C_Sprite>(it)->_sprite = "laserbullet.png";

								sendToServer(it);
							}
						}
					}
				}
				// printInfoSysteme("CreateFire");
			};
		};

		class Monster : public ISystemNetwork {
		public:
			Monster(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~Monster(){};
			virtual bool update() override
			{
				auto entities = _entities;
				for (auto it : entities) {
					if (_manager->getComponent<BasicComponent::C_Position>(it)->_posX <= -200) {
						_manager->getComponent<BasicComponent::C_Event>(it)->render = false;
						sendToServer(it);
						_manager->destroyEntity(it);
					} else {
						if ((std::rand() % (600 - 100 + 1) + 100) > _manager->getComponent<BasicComponent::C_Position>(it)->_posY) {
							_manager->getComponent<BasicComponent::C_Event>(it)->moveDown = true;
						} else {
							_manager->getComponent<BasicComponent::C_Event>(it)->moveUp = true;
						}
						_manager->getComponent<BasicComponent::C_Event>(it)->moveLeft = true;
						// _manager->getComponent<BasicComponent::C_Speed>(it)->_speed = 2;
					}
				}
				// printInfoSysteme("Monster");
			};
		};

		class Wall : public ISystemNetwork {
		public:
			Wall(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~Wall(){};
			virtual bool update() override
			{
				auto entity = _entities;
				for (auto it : entity) {
					_manager->getComponent<BasicComponent::C_Event>(it)->moveDown = true;
					if (_manager->getComponent<BasicComponent::C_Position>(it)->_posY >= 720) {
						_manager->getComponent<BasicComponent::C_Event>(it)->render = false;
						sendToServer(it);
						_manager->destroyEntity(it);
					}
				}
			};
		};
		class Player : public ISystemNetwork {
		public:
			Player(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~Player(){};
			virtual bool update() override{
				// printInfoSysteme("Player");
			};
		};
		class Fire : public ISystemNetwork {
		public:
			Fire(int priority, std::set<ComponentType> componentType) :
				ISystemNetwork(priority, componentType) {}
			~Fire(){};
			virtual bool update() override
			{
				auto entities = _entities;
				for (auto it : entities) {
					if (_manager->getComponent<BasicComponent::C_Position>(it)->_posX >= 1280) {
						_manager->getComponent<BasicComponent::C_Event>(it)->render = false;
						sendToServer(it);
						_manager->destroyEntity(it);
					}
					_manager->getComponent<BasicComponent::C_Event>(it)->moveRight = true;
				}
				// printInfoSysteme("Fire");
			};
		};

	} // namespace BasicSystem
} // namespace Basic