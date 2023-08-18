/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Monster1
*/

#pragma once

#include "ILib.hpp"

class Monster1 : public ILib {
	public:
		Monster1();
		~Monster1();

		virtual void addComponent(ECS::Manager &manager) override;
		virtual void addEntity(ECS::Manager &manager) override;
		virtual void addSystem(ECS::Manager &manager) override;


		virtual void removeComponent(ECS::Manager &manager) override;
		virtual void removeEntity(ECS::Manager &manager) override;
		virtual void removeSystem(ECS::Manager &manager) override;
};
