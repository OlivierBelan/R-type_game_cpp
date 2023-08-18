/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BasicComponent
*/

#pragma once

#include "ComponentType.hpp"
#include "IComponent.hpp"

namespace Basic {
	namespace BasicComponent {
		class C_Position : public ECS::IComponent {
		public:
			static const ComponentType type = Type::POSITION;
			float _posX = 100;
			float _posY = 100;
		};

		class C_Life : public ECS::IComponent {
		public:
			static const ComponentType type = Type::LIFE;
			int _life = 100;
		};

		class C_Sprite : public ECS::IComponent {
		public:
			static const ComponentType type = Type::SPRITE;
			std::string _sprite = "";
		};

		class C_Speed : public ECS::IComponent {
		public:
			static const ComponentType type = Type::SPEED;
			float _speed = 10;
			float _speedDown = 0;
			float _speedUp = 0;
		};
		// class C_Player : public ECS::IComponent {
		// public:
		// 	static const ComponentType type = Type::PLAYER;
		// 	int player = 0;
		// };
		class C_Box : public ECS::IComponent {
			public:
				static const ComponentType type = Type::BOX;
				int width = 0;
				int height = 0;
		};
		class C_Event : public ECS::IComponent {
		public:
			static const ComponentType type = Type::EVENT;
			bool speedUp = false;
			bool speedDown = false;
			bool lifeUp = false;
			bool lifeDown = false;
			bool colision = false;
			bool moveUp = false;
			bool moveDown = false;
			bool moveLeft = false;
			bool moveRight = false;
			bool fire = false;
			bool render = false;
		};
		class C_Info : public ECS::IComponent {
		public:
			static const ComponentType type = Type::INFO;
			bool player = false;
			bool monster = false;
			bool wall = false;
			bool fire = false;
			bool render = false;
		};
	} // namespace BasicCompopenent
} // namespace Basic