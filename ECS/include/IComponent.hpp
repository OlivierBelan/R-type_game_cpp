/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Component
*/

#pragma once

#include <iostream>


typedef std::size_t ComponentType;

namespace ECS {
	static const ComponentType INVALID_COMPENENT = 0;
	class IComponent {
	public:
		static const ComponentType type = INVALID_COMPENENT;
	};
	class A : public IComponent {
	private:
	public:
		// A() { std::cout << "A IS ALIVE\n"; };
		static const ComponentType type = 100;
		int posX = 14;
		int posY = 12;
		// ~A(){};
	};
	class B : public IComponent {
	private:
	public:
		// B() { std::cout << "B IS ALIVE\n"; };
		static const ComponentType type = 101;
		int posX = 17;
		int posY = 23;
		// ~B(){};
	};

} // namespace ECS