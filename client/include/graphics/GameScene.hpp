/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "SButton.hpp"
#include "SInput.hpp"
#include "SRenderWindow.hpp"
#include "SSprite.hpp"
#include "SText.hpp"
#include "SSound.hpp"
#include "iostream"
#include "map"
#include "string"
#include "struct.h"

namespace RType {
	class AsioNetwork;
	class ANetwork;
};

class GameScene {
public:
	GameScene(IRenderWindow *, RType::ANetwork &);
	~GameScene();
	void eventManager(void) noexcept;
	void renderWindow(void) noexcept;
	void moveParallax(void) noexcept;
	void handleNewEntity(t_entity) noexcept;
	void setGameMusic(sound_action) noexcept;

private:
	IRenderWindow *_window;
	RType::ANetwork &_network;
	std::vector<ADrawable *> _objects;
	std::map<size_t, ISprite *> _entities;

	ISprite *_1_Layer1;
	ISprite *_1_Layer2;
	ISprite *_1_Layer3;
	ISprite *_1_Layer4;
	ISprite *_2_Layer2;
	ISprite *_2_Layer3;
	ISprite *_2_Layer4;
	ISprite *_2_Layer1;
	ISprite *_3_Layer1;
	ISprite *_3_Layer2;
	ISprite *_3_Layer3;
	ISprite *_3_Layer4;
	ISprite *_4_Layer1;
	ISprite *_4_Layer2;
	ISprite *_4_Layer3;
	ISprite *_4_Layer4;
	ISprite *_5_Layer1;
	ISprite *_5_Layer2;
	ISprite *_5_Layer3;
	ISprite *_5_Layer4;

	ISound *_gameMusic;
};

#endif /* !GAMESCENE_HPP_ */
