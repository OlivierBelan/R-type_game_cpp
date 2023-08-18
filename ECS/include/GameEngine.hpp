/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#pragma once

#include "Manager.hpp"
// #include "struct.h"
// #include <memory>
namespace RType {
	class AGameServer;
}

static const int LEVEL_MAX = 2;
static const int LEVEL_METEOR = 5;

class GameEngine {
public:
	GameEngine(RType::AGameServer &gameServer);
	GameEngine();
	~GameEngine();
	void init(size_t nb);
	void initComponent();
	void initSystem();
	void addLibrary(const std::string &libPath);
	void removeLibrary(const std::string &libPath);
	void run(size_t nb);
	void update();
	void receiveMessage(const t_udp_client_message *message);
	void sendMessage();
protected:
private:
	void createEntityType(int player, int type);
private:
	RType::AGameServer *_gameServer;
	std::shared_ptr<ECS::Manager> _manager;
	void *_handler;
	// t_entity _messageSend;
	const udp_client_message *_messageReceive;
};