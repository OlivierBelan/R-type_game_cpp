/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster2
*/

#pragma once

#include "ILib.hpp"

class Monster2 : public ILib {
	public:
		Monster2();
		~Monster2();

		virtual void addComponent(ECS::Manager &manager) override;
		virtual void addEntity(ECS::Manager &manager) override;
		virtual void addSystem(ECS::Manager &manager) override;


		virtual void removeComponent(ECS::Manager &manager) override;
		virtual void removeEntity(ECS::Manager &manager) override;
		virtual void removeSystem(ECS::Manager &manager) override;
};
