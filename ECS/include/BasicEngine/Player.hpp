/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Player
*/

#pragma once

#include "ComponentType.hpp"
#include "IComponent.hpp"

namespace Basic {
	namespace EntityType {
		class Player : public ECS::IComponent {
		public:
			static const ComponentType type = Type::PLAYER;
			int id = 0;
		};
		class Fire : public ECS::IComponent {
		public:
			static const ComponentType type = Type::FIRE;
			int id = 0;
		};
		class Monster : public ECS::IComponent {
		public:
			static const ComponentType type = Type::MONSTER;
			int id = 0;
		};

		class Wall : public ECS::IComponent {
		public:
			static const ComponentType type = Type::WALL;
			int id = 0;
		};
	} // namespace EntityType
} // namespace Basic
