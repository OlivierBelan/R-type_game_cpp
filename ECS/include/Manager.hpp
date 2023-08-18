/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Manager
*/

#pragma once

#include "ComponentManager.hpp"
#include "IComponent.hpp"
#include "IEntity.hpp"
#include "ISystem.hpp"
#include <algorithm>
#include <assert.h>
#include <map>
#include <memory>
#include <set>
#include <type_traits>
#include <vector>
// #include <cctype>
#include <iostream>

namespace ECS {

	class Manager {
	public:
		Manager();
		~Manager();

	public:
		Entity createEntity();
		bool destroyEntity(Entity id);
		void printInfo();

	public:
		template <class T>
		bool createComponent(T component)
		{
			// std::cout << "BEFORE = " << _componentManager.size() << "\n";
			static_assert(std::is_base_of<IComponent, T>::value, "FROM createComponent : COMPONENT SHOULD INEHERIT FROM ICOMPONENT");
			static_assert(T::type != INVALID_COMPENENT, "FROM createComponent : INVALID COMPONENT TYPE SHOULD BE DIFFENRENT THAN 0");
			auto type = T::type;
			_componentManager.insert(std::make_pair(type, std::make_shared<ComponentManager>()));


			// getComponentManager(type)->registerComponent(std::make_shared<T>(component)); //// A CHANGER


			// std::cout << "FROM CREATE COMPONENT TYPE = " << type << " COMPONENTMANGER SIZE =" <<_componentManager.size() << std::endl;
			// _componentManager.find(type)->getAllEntitites();
			// std::cout << "AFTER = " << _componentManager.size() << "\n";
			return (true);
		}
		template <class T, class... Args>
		bool createComponent(T component, Args... args)
		{
			createComponent(component);
			createComponent(args...);
			return (true);
		}
		bool destroyComponentFromEntity(Entity entity, ComponentType type);
		std::shared_ptr<ComponentManager> getComponentManager(ComponentType type);
		std::shared_ptr<IComponent> getComponent(Entity entity, ComponentType type);
		template <class T>
		std::shared_ptr<T> getComponent(Entity entity)
		{
			static_assert(std::is_base_of<IComponent, T>::value, "FROM getComponent : COMPONENT SHOULD INEHERIT FROM ICOMPONENT");
			static_assert(T::type != INVALID_COMPENENT, "FROM getComponent : INVALID COMPONENT TYPE SHOULD BE DIFFENRENT THAN 0");
			return std::static_pointer_cast<T>(getComponent(entity, T::type));
		}

	public:
		// bool addComponentToEntity(Entity entity, ComponentType type);
		template <class T>
		bool addComponentToEntity(Entity entity, std::shared_ptr<T> component)
		{
			static_assert(std::is_base_of<IComponent, T>::value, "FROM addComponentToEntity : COMPONENT SHOULD INEHERIT FROM ICOMPONENT");
			// static_assert(T::type != INVALID_COMPENENT, "FROM addComponentToEntity : INVALID COMPONENT TYPE SHOULD BE DIFFENRENT THAN 0");
			auto isIdValid = _Ids.find(entity);
			if (isIdValid == _Ids.end() || isIdValid->second == FREE) {
				std::cout << "FROM addComponentToEntity : CANT ADD COMPONENT TO ENTITY " << entity << " DOESNT EXIST OR IS UN-ACTIVED\n";
				return (false);
			}
			auto type = T::type;
			auto cManager = getComponentManager(type);
			if (cManager == nullptr) {
				std::cout << " FROM addComponentToEntity : CANT ADD COMPONENT TO ENTITY " << entity << " COMPONENT DOESNT EXIST\n";
				return (false);
			}
			cManager->addEntity(entity, component);
			_entitiesWithComponents[entity].insert(type);
			// std::cout << "SIZE OF ALL ENTITIES " << cManager->getAllEntitites().size() << "\n";
			// std::cout << "SIZE OF ALL ENTITIESWITHCOMPONENT " << _entitiesWithComponents[1].size() << "\n";
		}
		template <class T, class... Args>
		bool addComponentToEntity(Entity entity, std::shared_ptr<T> component, Args... args)
		{
			addComponentToEntity(entity, component);
			addComponentToEntity(entity, args...);
		}

	public:
		template <class T>
		bool addSystem(std::shared_ptr<T> system)
		{
			// std::cout << "BEFORE SYSTEME SIZE = " << _systems.size() << "\n";
			static_assert(std::is_base_of<ISystem, T>::value, "FROM addSystem : SYSTEM SHOULD IHENERIT FROM ISYSTEM");
			_systems.push_back(system);
			std::cout << "SYSTEME SIZE = " << _systems.size() << "\n";
			// initSystem();
			// updateSystem(17);
		}
		template <class T, class... Args>
		bool addSystem(std::shared_ptr<T> system, Args... args)
		{
			addSystem(system);
			addSystem(args...);
		}
		bool initSystem();
		bool updateSystem();
		bool addEntityToSystem(Entity entity);
		bool removeEntityToSystem(Entity entity);
		// template <class T>
		// std::shared_ptr<T> getSystem(Entity entity)
		// {
		// 	// static_assert(std::is_base_of<IComponent, T>::value, "FROM getComponent : COMPONENT SHOULD INEHERIT FROM ICOMPONENT");
		// 	// static_assert(T::type != INVALID_COMPENENT, "FROM getComponent : INVALID COMPONENT TYPE SHOULD BE DIFFENRENT THAN 0");
		// 	return std::static_pointer_cast<T>(getComponent(entity, T::type));
		// }


	protected:
	private:
		enum Etat {
			USED,
			FREE
		};
		Entity _init = 0;
		std::map<Entity, Etat> _Ids;
		std::map<ComponentType, std::shared_ptr<ComponentManager>> _componentManager;
		std::map<Entity, std::set<ComponentType>> _entitiesWithComponents;
		std::vector<std::shared_ptr<ISystem>> _systems;
	};

} // namespace ECS
