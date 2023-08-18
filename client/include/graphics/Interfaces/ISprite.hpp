/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include "ADrawable.hpp"

class ISprite : public ADrawable {
public:
	virtual ~ISprite() = default;
	virtual void setScale(std::pair<float, float>) noexcept = 0;
	virtual std::pair<size_t, size_t> getScale(void) const noexcept = 0;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept = 0;
	virtual void setRotation(float) noexcept = 0;
	virtual void setTexture(std::string) noexcept = 0;
	virtual void setTextureRect(std::pair<size_t, size_t>, std::pair<size_t, size_t>) noexcept = 0;
	virtual std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>> getTextureRect(void) const noexcept = 0;
	virtual void move(std::pair<float, float>) noexcept = 0;		  // ajoute la position actuelle
	virtual void setPosition(std::pair<float, float>) noexcept = 0; // overwrite la position actuelle
	virtual std::pair<size_t, size_t> getPosition(void) const noexcept = 0;
};

#endif /* !ISPRITE_HPP_ */
