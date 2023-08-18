/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** LobbyScene
*/

#include "LobbyScene.hpp"
#include "ANetwork.hpp"

LobbyScene::LobbyScene(IRenderWindow *window, RType::ANetwork &network) :
	_window(window),
	_network(network)
{
	this->_player1 = new SButton("Ready", std::make_pair<size_t, size_t>(150, 50), std::make_pair<size_t, size_t>(50, 400),
								 std::make_pair<size_t, size_t>(80, 405), "Roboto-Medium.ttf", 30);
	this->_player2 = new SButton("Ready", std::make_pair<size_t, size_t>(150, 50), std::make_pair<size_t, size_t>(225, 400),
								 std::make_pair<size_t, size_t>(255, 405), "Roboto-Medium.ttf", 30);
	this->_player3 = new SButton("Ready", std::make_pair<size_t, size_t>(150, 50), std::make_pair<size_t, size_t>(400, 400),
								 std::make_pair<size_t, size_t>(430, 405), "Roboto-Medium.ttf", 30);
	this->_player4 = new SButton("Ready", std::make_pair<size_t, size_t>(150, 50), std::make_pair<size_t, size_t>(575, 400),
								 std::make_pair<size_t, size_t>(605, 405), "Roboto-Medium.ttf", 30);

	this->_character1 = new SSprite("blue.png", std::make_pair<float, float>(30, 165));
	this->_character2 = new SSprite("red.png", std::make_pair<float, float>(210, 165));
	this->_character3 = new SSprite("yellow.png", std::make_pair<float, float>(380, 165));
	this->_character4 = new SSprite("green.png", std::make_pair<float, float>(555, 165));
	this->_characterList = {
		{1, this->_character1},
		{2, this->_character2},
		{3, this->_character3},
		{4, this->_character4},
	};
	for (auto it = this->_characterList.begin(); it != this->_characterList.end(); it++) {
		it->second->setScale(std::make_pair<float, float>(0.75, 0.75));
		this->_objects.push_back(it->second);
	}
	this->_readyStatus = {
		{1, false},
		{2, false},
		{3, false},
		{4, false},
	};
	this->_onlineStatus = {
		{1, false},
		{2, false},
		{3, false},
		{4, false},
	};
	this->_playerList = {
		{1, this->_player1},
		{2, this->_player2},
		{3, this->_player3},
		{4, this->_player4},
	};

	for (auto it = this->_playerList.begin(); it != this->_playerList.end(); it++) {
		it->second->setTextColor(255, 255, 255);
		it->second->setRectColor(238, 75, 75);
		this->_objects.push_back(it->second);
	}
	this->_objects.push_back(this->_character1);
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::refreshLobby(t_lobby lobby) noexcept
{
	this->_lobby_status = lobby;
	this->_readyStatus[1] = lobby.player_1.ready;
	this->_readyStatus[2] = lobby.player_2.ready;
	this->_readyStatus[3] = lobby.player_3.ready;
	this->_readyStatus[4] = lobby.player_4.ready;
	this->_onlineStatus[1] = lobby.player_1.connected;
	this->_onlineStatus[2] = lobby.player_2.connected;
	this->_onlineStatus[3] = lobby.player_3.connected;
	this->_onlineStatus[4] = lobby.player_4.connected;
	auto player = this->_playerList.begin();
	auto status = this->_readyStatus.begin();
	for (; player != this->_playerList.end(); player++, status++) {
		if (status->second)
			player->second->setRectColor(53, 188, 122);
		else
			player->second->setRectColor(238, 75, 75);
	}
	this->_playerList[this->_network.getPlayerId()]->setOutlineColor(255, 255, 255);
	this->_playerList[this->_network.getPlayerId()]->setOutlineThickness(5);
}

void LobbyScene::eventManager(void) noexcept
{
	SRenderWindow *sRenderWindow = reinterpret_cast<SRenderWindow *>(this->_window);
	sRenderWindow->eventManager(this->_objects);
}

void LobbyScene::renderWindow(void) noexcept
{
	if (this->_playerList[this->_network.getPlayerId()]->isPushed()) {
		this->_playerList[this->_network.getPlayerId()]->setRectColor(53, 188, 122);
		this->_playerList[this->_network.getPlayerId()]->setPushed(false);
		this->_network.setReady();
	}

	for (auto it = this->_playerList.begin(); it != this->_playerList.end(); it++)
		it->second->setDraw(true);
	auto character = this->_characterList.begin();
	auto online = this->_onlineStatus.begin();
	for (; character != this->_characterList.end(); character++, online++) {
		if (online->second)
			character->second->setDraw(true);
	}
	this->_window->clearWindow();
	SRenderWindow *sRenderWindow = reinterpret_cast<SRenderWindow *>(this->_window);
	sRenderWindow->drawObjects(this->_objects);
	this->_window->displayWindow();
}