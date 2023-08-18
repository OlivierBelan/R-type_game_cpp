/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include "ADrawable.hpp"

class IButton : public ADrawable {
public:
	virtual ~IButton() = default;
	virtual void setString(std::string) noexcept = 0;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept = 0;
	virtual bool isPushed(void) const noexcept = 0;
	virtual void setPushed(bool) noexcept = 0;
	virtual void setSize(std::pair<size_t, size_t>) noexcept = 0;
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
};

#endif /* !IBUTTON_HPP_ */
