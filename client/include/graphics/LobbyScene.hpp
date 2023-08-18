/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** LobbyScene
*/

#ifndef LOBBYSCENE_HPP_
#define LOBBYSCENE_HPP_

#include "SButton.hpp"
#include "SInput.hpp"
#include "SRenderWindow.hpp"
#include "SSprite.hpp"
#include "SText.hpp"
#include "iostream"
#include "string"
#include "map"
#include "struct.h"

namespace RType {
	class ANetwork;
};
class LobbyScene {
public:
	LobbyScene(IRenderWindow *, RType::ANetwork &);
	~LobbyScene();
	void eventManager(void) noexcept;
	void renderWindow(void) noexcept;
	void refreshLobby(t_lobby lobby) noexcept;

private:
	bool _isReadyPushed;

	IRenderWindow *_window;
	RType::ANetwork &_network;

	IButton *_player1;
	IButton *_player2;
	IButton *_player3;
	IButton *_player4;
	std::map<int, IButton *> _playerList;

	ISprite *_character1;
	ISprite *_character2;
	ISprite *_character3;
	ISprite *_character4;
	std::map<int, ISprite *> _characterList;
	
	t_lobby _lobby_status;
	std::map<int, bool> _readyStatus;
	std::map<int, bool> _onlineStatus;

	std::vector<ADrawable *> _objects;
};

#endif /* !LOBBYSCENE_HPP_ */
