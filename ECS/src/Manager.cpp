/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Manager
*/

#include "Manager.hpp"

ECS::Manager::Manager()
{
}

ECS::Manager::~Manager()
{
}

/////// ENTITY PART ///////

ECS::Entity ECS::Manager::createEntity()
{
	auto newId = 0;

	if (!_Ids.empty()) {
		for (auto &it : _Ids) {
			if (it.second == FREE) {
				_Ids[it.first] = USED;
				_entitiesWithComponents.emplace(it.first, std::set<ComponentType>());
				// std::cout << "NEW ENTITIE RECYCLED" << std::endl;
				return (it.first);
			}
		}
	}
	newId = ++_init;
	_Ids.emplace(newId, USED);
	_entitiesWithComponents.emplace(newId, std::set<ComponentType>());
	// std::cout << "NEW ENTITIE CREATED" << std::endl;
	return (newId);
}

void ECS::Manager::printInfo()
{
	std::cout << std::endl << std::endl << "//////////////////////// INFO ECS /////////////////////////: "<< std::endl ;
	std::cout << "NB ID && ETAT ID :"<< std::endl;
	for (auto &it : _Ids) {
		auto etat = it.second == 0 ? "USED" : "FREE";
		std::cout << "_IDS = " << it.first << " ETAT = " << etat << std::endl;
	}
	std::cout << "SIZE IDS = " << _Ids.size();
	std::cout << std::endl;
	std::cout << "ENTITIES WITH COMPONENT :" << std::endl;
	for (auto &it : _entitiesWithComponents) {
		std::cout << "ID = " << it.first << " NOMBRE COMPONENT = " << it.second.size() << " ";
		std::cout << "COMPONENT TYPE :";
		if (!it.second.empty()) {
			for (auto &at : it.second) {
				std::cout <<" " << at << " ";
			}
		} else {
			std::cout << " NONE";
		}
		std::cout << std::endl;
	}
	std::cout << "SIZE ENTITIES WITH COMPONENT = " << _entitiesWithComponents.size() << std::endl;
	std::cout << "SIZE SYSTEMES = " << _systems.size() << std::endl; 
	std::cout << "////////////////////// END INFO ECS ///////////////////////: "<< std::endl << std::endl;
}

bool ECS::Manager::destroyEntity(Entity id)
{
	auto res = _Ids[id] = FREE;
	_entitiesWithComponents.erase(id);
	removeEntityToSystem(id);
	return (res > 0);
}

/////// ENTITY END PART //////

/////// COMPONENT PART ///////

std::shared_ptr<ECS::ComponentManager> ECS::Manager::getComponentManager(ComponentType type)
{
	auto res = _componentManager.find(type);
	return (res != _componentManager.end() ? res->second : nullptr);
}

std::shared_ptr<ECS::IComponent> ECS::Manager::getComponent(Entity entity, ComponentType type)
{
	if (entity == 0 || type == 0)
		return nullptr;
	auto res = getComponentManager(type);
	if (res == nullptr)
		return nullptr;
	return res->getComponent(entity);
}

bool ECS::Manager::destroyComponentFromEntity(Entity entity, ComponentType type)
{
	if (entity == 0 || type == 0)
		return false;
	auto res = getComponentManager(type);
	auto del = _entitiesWithComponents.find(entity);
	if (del == _entitiesWithComponents.end())
		return false;
	// std::cout << "BEFORE DESTROYED " << res->getAllEntitites().size() << std::endl;
	del->second.erase(type);
	res->removeEntity(entity);
	// addEntityToSystem(entity);
	// std::cout << "AFTER DESTROYED " << res->getAllEntitites().size() << std::endl;
	return (true);
}

/////// COMPONENT END PART /////

//////// MANAGE ENTITY WITH COMPONENT START /////

// bool ECS::Manager::addComponentToEntity()
// {

// }

//////// MANAGE ENTITY WITH COMPONENT END /////

/////// SYSTEM START PART //////

bool ECS::Manager::initSystem()
{
	// for (auto it : _systems) {
	// 	std::cout << "BEFORE ORDER " << it->getPriority() << std::endl;
	// }
	std::sort(_systems.begin(), _systems.end(), [](const std::shared_ptr<ISystem> &a, const std::shared_ptr<ISystem> &b) {
		return (a->getPriority() < b->getPriority());
	});
	// for (auto it : _systems) {
	// 	std::cout << "AFTER ORDER " << it->getPriority() << std::endl;
	// }

	for (auto &it : _systems) {
		it->init();
	}
}
bool ECS::Manager::updateSystem()
{
	for (auto &it : _systems) {
		it->update();
	}
}

bool ECS::Manager::addEntityToSystem(Entity entity)
{
	auto res = _entitiesWithComponents.find(entity);
	if (entity == INVALIDE_ENTITY || res == _entitiesWithComponents.end()) {
		return (false);
	}
	for (auto &it : _systems) {
		auto systemComponentType = it->getComponentType();
		if (std::includes(res->second.begin(), res->second.end(), systemComponentType.begin(), systemComponentType.end())) {
			// std::cout << "ENTITIES ADDED TO SYSTEME" << std::endl;
			it->addEntity(entity);
		} else {
			// std::cout << "ENTITIES REMOVED TO SYSTEME" << std::endl;
			it->removeEntity(entity);
		}
	}
	return true;
}
bool ECS::Manager::removeEntityToSystem(Entity entity) 
{
	for (auto &it : _systems) {
		// std::cout << "ENTITIES REMOVED TO SYSTEME" << std::endl;
		it->removeEntity(entity);
	}
}

////// SYSTEM END PART ////////