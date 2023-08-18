/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ADrawable
*/

#ifndef ADRAWABLE_HPP_
#define ADRAWABLE_HPP_

#include "IRenderWindow.hpp"
#include "Misc.hpp"
class ADrawable {
public:
	virtual ~ADrawable() = default;
	virtual void draw(IRenderWindow &) noexcept = 0;
	virtual void setDraw(bool) noexcept;
	virtual bool getDraw(void) const noexcept;
	virtual void eventManager(IRenderWindow &) noexcept = 0;
	virtual void textEntered(size_t) noexcept = 0;
	virtual void handleClick(std::pair<size_t, size_t>) noexcept = 0;

protected:
	bool _draw;
};

#endif /* !ADRAWABLE_HPP_ */
