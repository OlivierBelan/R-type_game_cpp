/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ILib
*/

#pragma once

#include <vector>
#include <Manager.hpp>

class ILib {
	public:
		ILib() = default;
		virtual ~ILib() = default;

		virtual void addComponent(ECS::Manager &manager) = 0;
		virtual void addEntity(ECS::Manager &manager) = 0;
		virtual void addSystem(ECS::Manager &manager) = 0;

		virtual void removeComponent(ECS::Manager &manager) = 0;
		virtual void removeEntity(ECS::Manager &manager) = 0;
		virtual void removeSystem(ECS::Manager &manager) = 0;
};
