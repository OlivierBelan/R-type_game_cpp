/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ComponentManagement
*/

#pragma once

#include "IEntity.hpp"
#include "IComponent.hpp"
#include <iostream>
#include <cstddef>
#include <set>
#include <map>
#include <memory>
namespace ECS {
	class ComponentManager {
	public:
        bool hadEntity(Entity entity);
        bool addEntity(Entity entity, std::shared_ptr<IComponent> component);
        std::shared_ptr<IComponent> getComponent(Entity entity);
        bool removeEntity(Entity entity);
        std::set<Entity> getAllEntitites();
        /////// A CHANGER
        std::shared_ptr<IComponent> get();
        void registerComponent(std::shared_ptr<IComponent> component);
	protected:
	private:
    std::map<Entity, std::shared_ptr<IComponent>>_componentManager;
    /////// A CHANGER
    std::shared_ptr<IComponent> _component;
	};
} // namespace ECS
