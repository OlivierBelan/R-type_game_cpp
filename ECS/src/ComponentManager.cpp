/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

bool ECS::ComponentManager::hadEntity(Entity entity)
{
	return (_componentManager.find(entity) != _componentManager.end());
}
bool ECS::ComponentManager::addEntity(Entity entity, std::shared_ptr<IComponent> component)
{
	auto res = _componentManager.insert(std::make_pair(entity, component));
	return (res.second);
}
std::shared_ptr<ECS::IComponent> ECS::ComponentManager::getComponent(Entity entity)
{
	auto it = _componentManager.find(entity);
	return (it != _componentManager.end() ? it->second : nullptr);
}
bool ECS::ComponentManager::removeEntity(Entity entity)
{
	return (_componentManager.erase(entity) > 0);
}
std::set<ECS::Entity> ECS::ComponentManager::getAllEntitites()
{
	std::set<ECS::Entity> res;

	for (auto it : _componentManager) {
		res.insert(it.first);
	}
	return (res);
}

/////// A CHANGER

std::shared_ptr<ECS::IComponent> ECS::ComponentManager::get()
{
	return (_component);
}
void ECS::ComponentManager::registerComponent(std::shared_ptr<IComponent> component)
{
	_component = component;
}
