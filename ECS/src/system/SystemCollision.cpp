/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SystemCollision
*/

#include "SystemCollision.hpp"
#include "BasicComponent.hpp"

SystemCollision::SystemCollision(int priority, std::set<ComponentType> componentType) :
	ISystemNetwork(priority, componentType)
{
}

SystemCollision::~SystemCollision()
{
}

box_t create_collision_box(obj_t obj)
{
	box_t res_box;

	res_box.top_left.x = obj.position->_posX;
	res_box.top_left.y = obj.position->_posY;

	res_box.top_right.x = obj.position->_posX + obj.box->width;
	res_box.top_right.y = obj.position->_posY;

	res_box.bottom_left.x = obj.position->_posX;
	res_box.bottom_left.y = obj.position->_posY + obj.box->height;

	res_box.bottom_right.x = obj.position->_posX + obj.box->width;
	res_box.bottom_right.y = obj.position->_posY + obj.box->height;

	return (res_box);
}

bool checkCollisionBox(box_t box1, box_t box2)
{
	if (box1.top_left.x <= box2.top_right.x && box1.top_left.x >= box2.top_left.x && box1.top_left.y <= box2.bottom_left.y && box1.top_left.y >= box2.top_left.y)
		return true;

	if (box1.bottom_left.x <= box2.bottom_right.x && box1.bottom_left.x >= box2.bottom_left.x && box1.bottom_left.y <= box2.bottom_left.y && box1.bottom_left.y >= box2.top_left.y)
		return true;

	return false;
}

void SystemCollision::handleCollision(const obj_t &obj1, const obj_t &obj2)
{
	this->_manager->getComponent<Basic::BasicComponent::C_Life>(obj2.id)->_life -= this->_manager->getComponent<Basic::BasicComponent::C_Life>(obj1.id)->_life;
	this->_manager->getComponent<Basic::BasicComponent::C_Life>(obj1.id)->_life = 0;
}

void SystemCollision::checkCollision(std::vector<obj_t> obj1, std::vector<obj_t> obj2)
{
	for (auto &obj1_it : obj1) {
		auto collision_box_1 = create_collision_box(obj1_it);
		for (auto &obj2_it : obj2) {
			auto collision_box_2 = create_collision_box(obj2_it);
			if (checkCollisionBox(collision_box_1, collision_box_2) || checkCollisionBox(collision_box_2, collision_box_1)) {
				this->handleCollision(obj1_it, obj2_it);
				return;
			}
		}
	}
}

std::vector<obj_t> SystemCollision::packComponents(const std::set<ComponentType> &entities)
{
	std::vector<obj_t> res;

	for (auto &Elem : entities) {
		obj_t new_obj;
		new_obj.id = Elem;
		new_obj.box = this->_manager->getComponent<Basic::BasicComponent::C_Box>(Elem);
		new_obj.position = this->_manager->getComponent<Basic::BasicComponent::C_Position>(Elem);
		res.push_back(new_obj);
	}
	return res;
}

bool SystemCollision::update()
{
	auto monsters = this->_manager->getComponentManager(Type::MONSTER)->getAllEntitites();
	auto monsters_box = this->packComponents(monsters);

	auto bullets = this->_manager->getComponentManager(Type::FIRE)->getAllEntitites();
	auto bullets_box = this->packComponents(bullets);

	auto players = this->_manager->getComponentManager(Type::PLAYER)->getAllEntitites();
	auto players_box = this->packComponents(players);

	auto walls = this->_manager->getComponentManager(Type::WALL)->getAllEntitites();
	auto walls_box = this->packComponents(walls);

	this->checkCollision(monsters_box, players_box);
	this->checkCollision(bullets_box, players_box);
	this->checkCollision(walls_box, players_box);
	this->checkCollision(bullets_box, monsters_box);
	this->checkCollision(bullets_box, walls_box);
	return false;
}
