/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ADrawable
*/

#include "ADrawable.hpp"

void ADrawable::setDraw(bool draw) noexcept
{
	this->_draw = draw;
}

bool ADrawable::getDraw(void) const noexcept
{
	return this->_draw;
}