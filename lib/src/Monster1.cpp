/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster1
*/

#include "Monster1.hpp"
#include "Player.hpp"

Monster1::Monster1()
{
}

Monster1::~Monster1()
{
}

void Monster1::addComponent(ECS::Manager &manager)
{
}

void Monster1::addEntity(ECS::Manager &manager)
{
	manager.createComponent(Basic::BasicComponent::C_Position(),
							Basic::BasicComponent::C_Life(),
							Basic::BasicComponent::C_Event(),
							Basic::BasicComponent::C_Speed(),
							Basic::BasicComponent::C_Sprite(),
							Basic::BasicComponent::C_Info(),
							Basic::BasicComponent::C_Box(),
							Basic::EntityType::Player(),
							Basic::EntityType::Monster(),
							Basic::EntityType::Wall(),
							Basic::EntityType::Fire());
	Basic::BasicComponent::C_Event event;
	Basic::BasicComponent::C_Life life;
	Basic::BasicComponent::C_Speed speed;
	Basic::BasicComponent::C_Position position;
	Basic::BasicComponent::C_Sprite sprite;
	Basic::BasicComponent::C_Info info;
	Basic::BasicComponent::C_Box box;
	Basic::EntityType::Monster monster;
	sprite._sprite = "monster1.png";
	box.width = 40;
	box.height = 40;
	life._life = 50;
	position._posX = 1300;
	position._posY = 300;
	speed._speed = 25;
	auto newEntity = manager.createEntity();
	manager.addComponentToEntity(newEntity, std::make_shared<Basic::BasicComponent::C_Event>(event),
								 std::make_shared<Basic::BasicComponent::C_Life>(life),
								 std::make_shared<Basic::BasicComponent::C_Speed>(speed),
								 std::make_shared<Basic::BasicComponent::C_Position>(position),
								 std::make_shared<Basic::BasicComponent::C_Sprite>(sprite),
								 std::make_shared<Basic::BasicComponent::C_Info>(info),
								 std::make_shared<Basic::BasicComponent::C_Box>(box),
								 std::make_shared<Basic::EntityType::Monster>(monster));
	manager.addEntityToSystem(newEntity);
}

void Monster1::addSystem(ECS::Manager &manager)
{
}

void Monster1::removeComponent(ECS::Manager &manager)
{
	auto entities = manager.getComponentManager(Type::MONSTER)->getAllEntitites();
	for(auto it : entities) {
		if (manager.getComponent<Basic::BasicComponent::C_Sprite>(it)->_sprite == "monster1.png") {
			manager.destroyEntity(it);
		}
	}
}

void Monster1::removeEntity(ECS::Manager &manager)
{
}

void Monster1::removeSystem(ECS::Manager &manager)
{
}

extern "C" {
Monster1 *make()
{
	return new Monster1();
}
}