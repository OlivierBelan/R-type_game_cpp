/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SystemCollision
*/

#pragma once

#include "ISystemNetwork.hpp"

typedef struct corner
{
	int x;
	int y;
} corner_t;

typedef struct obj
{
	std::shared_ptr<Basic::BasicComponent::C_Box> box;
	std::shared_ptr<Basic::BasicComponent::C_Position> position;
	std::size_t id;
} obj_t;

typedef struct box
{
	struct corner top_left;
	struct corner top_right;
	struct corner bottom_left;
	struct corner bottom_right;
} box_t;

class SystemCollision : public ISystemNetwork {
public:
	SystemCollision(int priority, std::set<ComponentType> componentType);
	~SystemCollision();
	virtual bool update() override;

private:
	std::vector<obj_t> packComponents(const std::set<ComponentType> &entities);
	void checkCollision(std::vector<obj_t>, std::vector<obj_t>);
	void handleCollision(const obj_t &, const obj_t &);
};
