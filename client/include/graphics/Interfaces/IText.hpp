/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IText
*/

#ifndef ITEXT_HPP_
#define ITEXT_HPP_

#include "ADrawable.hpp"

class IText : public ADrawable {
public:
	virtual ~IText() = default;
	virtual void setString(std::string) noexcept = 0;
	virtual void setCharacterSize(size_t) noexcept = 0;
	virtual void setPosition(std::pair<size_t, size_t>) noexcept = 0;
	virtual void setFont(std::string) noexcept = 0;
	virtual void setTextColor(size_t, size_t, size_t) noexcept = 0;
	virtual std::string getString(void) const noexcept = 0;
	virtual std::pair<size_t, size_t> getPosition(void) const noexcept = 0;
};

#endif /* !ITEXT_HPP_ */
