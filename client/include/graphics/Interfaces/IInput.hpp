/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IInput
*/

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include "ADrawable.hpp"

class IInput : public ADrawable {
public:
	virtual ~IInput() = default;
	virtual void setString(std::string) noexcept = 0;
	virtual void setSize(std::pair<size_t, size_t>) noexcept = 0;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept = 0;
	virtual void setCharacterSize(size_t) noexcept = 0;
	virtual void setTextPosition(std::pair<size_t, size_t>) noexcept = 0;
	virtual void setTextColor(size_t, size_t, size_t) noexcept = 0;
	virtual void setRectPosition(std::pair<size_t, size_t>) noexcept = 0;
	virtual void setRectColor(size_t, size_t, size_t) noexcept = 0;
	virtual void setOutlineColor(size_t, size_t, size_t) noexcept = 0;
	virtual void setOutlineThickness(size_t) noexcept = 0;
	virtual void setFont(const std::string &) noexcept = 0;
	virtual std::string getString(void) const noexcept = 0;
	virtual std::pair<size_t, size_t> getPosition(void) const noexcept = 0;
	virtual bool isSelected(void) const noexcept = 0;
	virtual void setSelected(bool) noexcept = 0;
};

#endif /* !IINPUT_HPP_ */
