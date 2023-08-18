/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#include "GameEngine.hpp"
#include "AGameServer.hpp"
#include "BasicComponent.hpp"
#include "BasicSystem.hpp"
#include "ComponentType.hpp"
#include "Error.hpp"
#include "ILib.hpp"
#include "Player.hpp"
#include "SystemCollision.hpp"
#include <chrono>
#include <dirent.h>
#include <dlfcn.h>
#include <fstream>

GameEngine::GameEngine(RType::AGameServer &gameServer) :
	_gameServer(&gameServer)
{
	ECS::Manager manager;
	_manager = std::make_shared<ECS::Manager>(manager);
}

GameEngine::GameEngine()
{
	ECS::Manager manager;
	_manager = std::make_shared<ECS::Manager>(manager);
}
GameEngine::~GameEngine()
{
}

void GameEngine::initComponent()
{
	_manager->createComponent(Basic::BasicComponent::C_Position(),
							  Basic::BasicComponent::C_Life(),
							  Basic::BasicComponent::C_Event(),
							  Basic::BasicComponent::C_Speed(),
							  Basic::BasicComponent::C_Sprite(),
							  Basic::BasicComponent::C_Info(),
							  Basic::BasicComponent::C_Box());
	_manager->createComponent(Basic::EntityType::Player());
	_manager->createComponent(Basic::EntityType::Monster());
	_manager->createComponent(Basic::EntityType::Wall());
	_manager->createComponent(Basic::EntityType::Fire());
}
void GameEngine::initSystem()
{
	Basic::BasicSystem::CreateEntityType createEntityType(1, {Basic::BasicComponent::C_Info::type});
	Basic::BasicSystem::CreatePlayer createPlayer(2, {Basic::BasicComponent::C_Info::type});
	Basic::BasicSystem::CreateMonster createMonster(3, {Basic::BasicComponent::C_Info::type});
	Basic::BasicSystem::CreateWall createWall(4, {Basic::BasicComponent::C_Info::type});
	Basic::BasicSystem::CreateFire createFire(10, {Basic::BasicComponent::C_Info::type});
	Basic::BasicSystem::Move move(5, {Basic::BasicComponent::C_Position::type, Basic::BasicComponent::C_Speed::type});
	Basic::BasicSystem::Speed speed(6, {Basic::BasicComponent::C_Speed::type, Basic::BasicComponent::C_Event::type});
	Basic::BasicSystem::Player player(7, {Basic::EntityType::Player::type});
	Basic::BasicSystem::Monster monster(8, {Basic::EntityType::Monster::type});
	Basic::BasicSystem::Wall wall(9, {Basic::EntityType::Wall::type});
	Basic::BasicSystem::Fire fire(11, {Basic::EntityType::Fire::type});
	SystemCollision collision(12, {Basic::EntityType::Fire::type});
	createEntityType.initManagerandNetWork(_manager, _gameServer);
	createPlayer.initManagerandNetWork(_manager, _gameServer);
	createMonster.initManagerandNetWork(_manager, _gameServer);
	createWall.initManagerandNetWork(_manager, _gameServer);
	createFire.initManagerandNetWork(_manager, _gameServer);
	move.initManagerandNetWork(_manager, _gameServer);
	speed.initManagerandNetWork(_manager, _gameServer);
	player.initManagerandNetWork(_manager, _gameServer);
	monster.initManagerandNetWork(_manager, _gameServer);
	wall.initManagerandNetWork(_manager, _gameServer);
	fire.initManagerandNetWork(_manager, _gameServer);
	collision.initManagerandNetWork(_manager, _gameServer);
	_manager->addSystem(std::make_shared<Basic::BasicSystem::CreateEntityType>(createEntityType),
						std::make_shared<Basic::BasicSystem::CreatePlayer>(createPlayer),
						std::make_shared<Basic::BasicSystem::CreateMonster>(createMonster),
						std::make_shared<Basic::BasicSystem::CreateWall>(createWall),
						std::make_shared<Basic::BasicSystem::CreateFire>(createFire),
						std::make_shared<Basic::BasicSystem::Move>(move),
						std::make_shared<Basic::BasicSystem::Speed>(speed),
						std::make_shared<Basic::BasicSystem::Player>(player),
						std::make_shared<Basic::BasicSystem::Monster>(monster),
						std::make_shared<Basic::BasicSystem::Wall>(wall),
						std::make_shared<Basic::BasicSystem::Fire>(fire),
						std::make_shared<SystemCollision>(collision));
}
void GameEngine::init(size_t nb)
{
	// _manager->createComponent(position, life, event, speed, sprite, player);
	// Basic::BasicComponent::
	initComponent();
	initSystem();
	this->createEntityType(nb, Type::PLAYER);
	// this->createEntityType(10, Type::WALL);
	// this->createEntityType(15, Type::MONSTER);
	// this->createEntityType(1, Type::FIRE);
}

void GameEngine::createEntityType(int nbType, int type)
{
	// std::cout << "CREATE ENTITY TYPE = " << type << "\n";
	for (auto i = 0; i != nbType; i++) {
		_manager->initSystem();
	}
	auto entitiesWithInfo = _manager->getComponentManager(Basic::BasicComponent::C_Info::type)->getAllEntitites();
	auto entity = entitiesWithInfo.begin();
	for (auto i = 0; i != nbType; i++, entity++) {
		if (type == Type::PLAYER)
			_manager->getComponent<Basic::BasicComponent::C_Info>(*entity)->player = true;
		else if (type == Type::MONSTER)
			_manager->getComponent<Basic::BasicComponent::C_Info>(*entity)->monster = true;
		else if (type == Type::WALL)
			_manager->getComponent<Basic::BasicComponent::C_Info>(*entity)->wall = true;
		else if (type == Type::FIRE)
			_manager->getComponent<Basic::BasicComponent::C_Info>(*entity)->fire = true;
		_manager->updateSystem();
	}
	_manager->updateSystem();
}

void GameEngine::addLibrary(const std::string &libPath)
{
	void *maker;
	ILib *(*pMaker)(void);

	this->_handler = dlopen(libPath.c_str(), RTLD_LAZY);
	if (this->_handler == NULL)
		throw Error("dlopen : " + static_cast<std::string>(dlerror()));
	*(void **)(&maker) = dlsym(this->_handler, "make");
	if (maker == NULL)
		throw Error("dlsym : " + static_cast<std::string>(dlerror()));
	pMaker = (ILib * (*)(void)) maker;
	ILib *new_lib = pMaker();
	new_lib->addEntity(*this->_manager);
	new_lib->addComponent(*this->_manager);
	new_lib->addSystem(*this->_manager);
	delete new_lib;
	dlclose(this->_handler);
}

void GameEngine::removeLibrary(const std::string &libPath)
{
	void *maker;
	ILib *(*pMaker)(void);

	this->_handler = dlopen(libPath.c_str(), RTLD_LAZY);
	if (this->_handler == NULL)
		throw Error("dlopen : " + (std::string)dlerror());
	*(void **)(&maker) = dlsym(this->_handler, "make");
	if (maker == NULL)
		throw Error("dlsym : " + (std::string)dlerror());
	pMaker = (ILib * (*)(void)) maker;
	ILib *new_lib = pMaker();
	new_lib->removeEntity(*this->_manager);
	new_lib->removeComponent(*this->_manager);
	new_lib->removeSystem(*this->_manager);
	delete new_lib;
	dlclose(this->_handler);
}

void GameEngine::run(size_t nb)
{
	this->init(nb);
	std::srand(std::time(nullptr));
	auto end = std::chrono::system_clock::now();
	auto start = end;
	auto endEvent = std::chrono::system_clock::now();
	float time = 0;
	float spawn = 0;
	int level = 7;
	// createEntityType(2, Type::MONSTER);
	while (true) {
		start = std::chrono::system_clock::now();
		time = std::chrono::duration_cast<std::chrono::milliseconds>(start - end).count();
		spawn = std::chrono::duration_cast<std::chrono::seconds>(start - endEvent).count();
		if (time > 50) {
			_manager->updateSystem();
			end = start;
		}
		if (spawn > level) {
			createEntityType(1, Type::WALL);
			createEntityType(1, Type::MONSTER);
			if (level <= LEVEL_METEOR) {
			}
			if (level > LEVEL_MAX)
				level--;
			endEvent = start;
		}
	}
}
void GameEngine::update()
{
	std::cout << "//////////////////////////////////////////////////////////////////\n";
	auto players = _manager->getComponentManager(Type::PLAYER)->getAllEntitites();
	if (!players.empty()) {
		for (auto it : players) {
			if (it == _messageReceive->player) {
				_manager->getComponent<Basic::BasicComponent::C_Event>(it)->moveUp = _messageReceive->up;
				_manager->getComponent<Basic::BasicComponent::C_Event>(it)->moveDown = _messageReceive->down;
				_manager->getComponent<Basic::BasicComponent::C_Event>(it)->moveRight = _messageReceive->right;
				_manager->getComponent<Basic::BasicComponent::C_Event>(it)->moveLeft = _messageReceive->left;
				_manager->getComponent<Basic::BasicComponent::C_Event>(it)->fire = _messageReceive->action;
				if (_messageReceive->action) {
					createEntityType(1, Type::FIRE);
				}
			}
		}
	}
}

inline const char *const BoolToString(bool b)
{
	return b ? "true" : "false";
}

void GameEngine::receiveMessage(const t_udp_client_message *message)
{
	if (message) {
		_messageReceive = message;
		update();
	}
	// std::cout << "receiveMessage" << std::endl;
	// std::cout << "Up: " << BoolToString(message->up) << std::endl;
	// std::cout << "Down: " << BoolToString(message->down) << std::endl;
	// std::cout << "Left: " << BoolToString(message->left) << std::endl;
	// std::cout << "Right: " << BoolToString(message->right) << std::endl;
	// std::cout << "Action: " << BoolToString(message->action) << std::endl;
	// std::cout << "message.magic_number : " << message->magic_number << std::endl;
}
void GameEngine::sendMessage()
{

	// uint8_t *buffer = reinterpret_cast<uint8_t *>(&_messageSend);
	// _gameServer.sendToAllClientUDP(buffer, sizeof(_messageSend));
	// _gameServer->
}
