/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include "AsioNetwork.hpp"

GameScene::GameScene(IRenderWindow *window, RType::ANetwork &network) :
	_window(window),
	_network(network)
{
	this->_1_Layer1 = new SSprite("1_Layer1.png", std::make_pair<float, float>(0, 0));
	this->_1_Layer2 = new SSprite("1_Layer2.png", std::make_pair<float, float>(0, 0));
	this->_1_Layer3 = new SSprite("1_Layer3.png", std::make_pair<float, float>(0, 0));
	this->_1_Layer4 = new SSprite("1_Layer4.png", std::make_pair<float, float>(0, 0));
	this->_objects.push_back(this->_1_Layer1);
	this->_objects.push_back(this->_1_Layer2);
	this->_objects.push_back(this->_1_Layer3);
	this->_objects.push_back(this->_1_Layer4);
	this->_2_Layer1 = new SSprite("2_Layer1.png", std::make_pair<float, float>(1280, 0));
	this->_2_Layer2 = new SSprite("2_Layer2.png", std::make_pair<float, float>(1280, 0));
	this->_2_Layer3 = new SSprite("2_Layer3.png", std::make_pair<float, float>(1280, 0));
	this->_2_Layer4 = new SSprite("2_Layer4.png", std::make_pair<float, float>(1280, 0));
	this->_objects.push_back(this->_2_Layer1);
	this->_objects.push_back(this->_2_Layer2);
	this->_objects.push_back(this->_2_Layer3);
	this->_objects.push_back(this->_2_Layer4);
	this->_3_Layer1 = new SSprite("3_Layer1.png", std::make_pair<float, float>(2560, 0));
	this->_3_Layer2 = new SSprite("3_Layer2.png", std::make_pair<float, float>(2560, 0));
	this->_3_Layer3 = new SSprite("3_Layer3.png", std::make_pair<float, float>(2560, 0));
	this->_3_Layer4 = new SSprite("3_Layer4.png", std::make_pair<float, float>(2560, 0));
	this->_objects.push_back(this->_3_Layer1);
	this->_objects.push_back(this->_3_Layer2);
	this->_objects.push_back(this->_3_Layer3);
	this->_objects.push_back(this->_3_Layer4);
	this->_4_Layer1 = new SSprite("4_Layer1.png", std::make_pair<float, float>(3840, 0));
	this->_4_Layer2 = new SSprite("4_Layer2.png", std::make_pair<float, float>(3840, 0));
	this->_4_Layer3 = new SSprite("4_Layer3.png", std::make_pair<float, float>(3840, 0));
	this->_4_Layer4 = new SSprite("4_Layer4.png", std::make_pair<float, float>(3840, 0));
	this->_objects.push_back(this->_4_Layer1);
	this->_objects.push_back(this->_4_Layer2);
	this->_objects.push_back(this->_4_Layer3);
	this->_objects.push_back(this->_4_Layer4);
	this->_5_Layer1 = new SSprite("1_Layer1.png", std::make_pair<float, float>(5120, 0));
	this->_5_Layer2 = new SSprite("1_Layer2.png", std::make_pair<float, float>(5120, 0));
	this->_5_Layer3 = new SSprite("1_Layer3.png", std::make_pair<float, float>(5120, 0));
	this->_5_Layer4 = new SSprite("1_Layer4.png", std::make_pair<float, float>(5120, 0));
	this->_objects.push_back(this->_5_Layer1);
	this->_objects.push_back(this->_5_Layer2);
	this->_objects.push_back(this->_5_Layer3);
	this->_objects.push_back(this->_5_Layer4);

	this->_gameMusic = new SSound("mega.ogg", true);
	this->_gameMusic->playSound(sound_action::PLAY);
}

GameScene::~GameScene()
{
	this->_gameMusic->playSound(sound_action::STOP);
}

void GameScene::setGameMusic(sound_action action) noexcept
{
	this->_gameMusic->playSound(action);
}

void GameScene::eventManager(void) noexcept
{
	SRenderWindow *sRenderWindow = reinterpret_cast<SRenderWindow *>(this->_window);
	RType::AsioNetwork *asioNetwork = reinterpret_cast<RType::AsioNetwork *>(&this->_network);
	sRenderWindow->eventManager(this->_objects, *asioNetwork);
}

void GameScene::moveParallax(void) noexcept
{
	this->_1_Layer1->move(std::make_pair<float, float>(-0.5, 0));
	this->_2_Layer1->move(std::make_pair<float, float>(-0.5, 0));
	this->_3_Layer1->move(std::make_pair<float, float>(-0.5, 0));
	this->_4_Layer1->move(std::make_pair<float, float>(-0.5, 0));
	this->_5_Layer1->move(std::make_pair<float, float>(-0.5, 0));
	if (this->_5_Layer1->getPosition().first <= 0) {
		this->_1_Layer1->setPosition(std::make_pair<float, float>(0, 0));
		this->_2_Layer1->setPosition(std::make_pair<float, float>(1280, 0));
		this->_3_Layer1->setPosition(std::make_pair<float, float>(2560, 0));
		this->_4_Layer1->setPosition(std::make_pair<float, float>(3840, 0));
		this->_5_Layer1->setPosition(std::make_pair<float, float>(5120, 0));
	}
	this->_1_Layer2->move(std::make_pair<float, float>(-0.75, 0));
	this->_2_Layer2->move(std::make_pair<float, float>(-0.75, 0));
	this->_3_Layer2->move(std::make_pair<float, float>(-0.75, 0));
	this->_4_Layer2->move(std::make_pair<float, float>(-0.75, 0));
	this->_5_Layer2->move(std::make_pair<float, float>(-0.75, 0));
	if (this->_5_Layer2->getPosition().first <= 0) {
		this->_1_Layer2->setPosition(std::make_pair<float, float>(0, 0));
		this->_2_Layer2->setPosition(std::make_pair<float, float>(1280, 0));
		this->_3_Layer2->setPosition(std::make_pair<float, float>(2560, 0));
		this->_4_Layer2->setPosition(std::make_pair<float, float>(3840, 0));
		this->_5_Layer2->setPosition(std::make_pair<float, float>(5120, 0));
	}
	this->_1_Layer3->move(std::make_pair<float, float>(-1, 0));
	this->_2_Layer3->move(std::make_pair<float, float>(-1, 0));
	this->_3_Layer3->move(std::make_pair<float, float>(-1, 0));
	this->_4_Layer3->move(std::make_pair<float, float>(-1, 0));
	this->_5_Layer3->move(std::make_pair<float, float>(-1, 0));
	if (this->_5_Layer3->getPosition().first <= 0) {
		this->_1_Layer3->setPosition(std::make_pair<float, float>(0, 0));
		this->_2_Layer3->setPosition(std::make_pair<float, float>(1280, 0));
		this->_3_Layer3->setPosition(std::make_pair<float, float>(2560, 0));
		this->_4_Layer3->setPosition(std::make_pair<float, float>(3840, 0));
		this->_5_Layer3->setPosition(std::make_pair<float, float>(5120, 0));
	}
	this->_1_Layer4->move(std::make_pair<float, float>(-1.25, 0));
	this->_2_Layer4->move(std::make_pair<float, float>(-1.25, 0));
	this->_3_Layer4->move(std::make_pair<float, float>(-1.25, 0));
	this->_4_Layer4->move(std::make_pair<float, float>(-1.25, 0));
	this->_5_Layer4->move(std::make_pair<float, float>(-1.25, 0));
	if (this->_5_Layer4->getPosition().first <= 0) {
		this->_1_Layer4->setPosition(std::make_pair<float, float>(0, 0));
		this->_2_Layer4->setPosition(std::make_pair<float, float>(1280, 0));
		this->_3_Layer4->setPosition(std::make_pair<float, float>(2560, 0));
		this->_4_Layer4->setPosition(std::make_pair<float, float>(3840, 0));
		this->_5_Layer4->setPosition(std::make_pair<float, float>(5120, 0));
	}
}

void GameScene::handleNewEntity(t_entity entity) noexcept
{
	std::cout << "ID: " << entity.id << " - PATH: " << entity.sprite << std::endl;
	std::cout << "New position : " << entity.posX << ":" << entity.posY << std::endl;
	if (!entity.render) {
		if (this->_entities.find(entity.id) == this->_entities.end()) {
			// std::cout << "fail erase entity with id: " << entity.id << std::endl;
		} else {
			// std::cout << "erase entity with id: " << entity.id << std::endl;
			this->_entities.erase(entity.id);
		}
		return;
	}
	if (this->_entities.find(entity.id) == this->_entities.end()) {
		// std::cout << "create entity with id: " << entity.id << std::endl;
		ISprite *sprite = new SSprite(entity.sprite, std::make_pair<float, float>((float)entity.posX, (float)entity.posY));
		this->_entities[entity.id] = sprite;
	} else {
		// std::cout << "update entity with id: " << entity.id << std::endl;
		this->_entities[entity.id]->setPosition(std::make_pair<float, float>((float)entity.posX, (float)entity.posY));
	}
}

void GameScene::renderWindow(void) noexcept
{
	moveParallax();
	for (auto it = this->_objects.begin(); it != this->_objects.end(); it++)
		(*it)->setDraw(true);

	this->_window->clearWindow();
	SRenderWindow *sRenderWindow = reinterpret_cast<SRenderWindow *>(this->_window);
	sRenderWindow->drawObjects(this->_objects);
	for (auto it = this->_entities.begin(); it != this->_entities.end(); it++) {
		it->second->setDraw(true);
		sRenderWindow->drawObjects(it->second);
	}
	this->_window->displayWindow();
}