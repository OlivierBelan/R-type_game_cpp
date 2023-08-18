/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "Error.hpp"
#include "GameScene.hpp"
#include "LobbyScene.hpp"
#include "LoginScene.hpp"
#include "AsioNetwork.hpp"

namespace RType {
	class AsioNetwork;
};

class Window {
public:
	Window(IRenderWindow *);
	~Window();
	void run(void) noexcept;
	void handleNewEntity(t_entity) noexcept;

private:
	IRenderWindow *_renderWindow;
	RType::AsioNetwork _network;
	LoginScene _loginScene;
	LobbyScene _lobbyScene;
	GameScene _gameScene;
};

#endif /* !WINDOW_HPP_ */
