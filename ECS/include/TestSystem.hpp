/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** TestSystem
*/

#pragma once

#include "IComponent.hpp"
#include "IEntity.hpp"
#include "Manager.hpp"
#include <memory>
#include <set>
// #include "Manager.hpp"
namespace ECS {
	// class SystemeA : public ISystem {
	// public:
	// 	SystemeA(int priority, std::set<ComponentType> componentType, std::shared_ptr<Manager> manager) :
	// 		ISystem(priority, componentType, manager) {}
	// 	~SystemeA(){};
	// 	virtual bool update() override
	// 	{
	// 		std::cout << "FROM SYSTEME A" << std::endl;
	// 		// std::cout << "SIZE ENTITIES = " << _entities.size() << " IDs = ";
	// 		// if (!_entities.empty()) {
	// 		// 	for (auto it : _entities) {
	// 		// 		std::cout << it << " ";
	// 		// 	}
	// 		// } else {
	// 		// 	std::cout << "NONE";
	// 		// }
	// 		// std::cout << std::endl;
	// 		for (auto it : _entities) {
	// 			std::cout << "BEFORE UPDATE = " <<_manager->getComponent<ECS::A>(it)->posX << "\n";
	// 			_manager->getComponent<ECS::A>(it)->posX += 1;
	// 			std::cout << "AFTER UPDATE = " <<_manager->getComponent<ECS::A>(it)->posX << "\n";
	// 		}

	// 	};
	// };
	// class SystemeB : public ISystem {
	// public:
	// 	SystemeB(int priority, std::set<ComponentType> componentType, std::shared_ptr<Manager> manager) :
	// 		ISystem(priority, componentType, manager) {}
	// 	~SystemeB(){};
	// 	virtual bool update() override
	// 	{
	// 		std::cout << "FROM SYSTEME B" << std::endl;
	// 		// std::cout << "SIZE ENTITIES = " << _entities.size() << " IDs = ";
	// 		// if (!_entities.empty()) {
	// 		// 	for (auto it : _entities) {
	// 		// 		std::cout << it << " ";
	// 		// 	}
	// 		// } else {
	// 		// 	std::cout << "NONE";
	// 		// }
	// 		// std::cout << std::endl;
	// 		for (auto it : _entities) {
	// 			std::cout << "BEFORE UPDATE = " <<_manager->getComponent<ECS::A>(it)->posX << "\n";
	// 			_manager->getComponent<ECS::A>(it)->posX += 1;
	// 			std::cout << "AFTER UPDATE = " <<_manager->getComponent<ECS::A>(it)->posX << "\n";
	// 		}
	// 	};
	// };

} // namespace ECS