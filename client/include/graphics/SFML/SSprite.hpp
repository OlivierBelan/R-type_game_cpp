/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SSprite
*/

#ifndef SSPRITE_HPP_
#define SSPRITE_HPP_

#include "ISprite.hpp"
#include "Misc.hpp"
#include "SRenderWindow.hpp"
#include <SFML/Graphics.hpp>

class SSprite : public ISprite {
public:
	SSprite(std::string, std::pair<float, float>);
	virtual void setScale(std::pair<float, float>) noexcept;
	virtual std::pair<size_t, size_t> getScale(void) const noexcept;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept;
	virtual void setTexture(std::string) noexcept;
	virtual void setRotation(float) noexcept;
	virtual void setTextureRect(std::pair<size_t, size_t>, std::pair<size_t, size_t>) noexcept;
	virtual std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>> getTextureRect(void) const noexcept;
	virtual void move(std::pair<float, float>) noexcept;		  // ajoute la position actuelle
	virtual void setPosition(std::pair<float, float>) noexcept; // overwrite la position actuelle
	virtual std::pair<size_t, size_t> getPosition(void) const noexcept;

	virtual void draw(IRenderWindow &) noexcept;
	virtual void eventManager(IRenderWindow &) noexcept;
	virtual void textEntered(size_t) noexcept;
	virtual void handleClick(std::pair<size_t, size_t>) noexcept;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
};

#endif /* !SSPRITE_HPP_ */
