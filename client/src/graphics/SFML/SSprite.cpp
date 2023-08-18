/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SSprite
*/

#include "SSprite.hpp"
#include "iostream"

SSprite::SSprite(std::string path, std::pair<float, float> pos)
{
	this->setTexture(path);
	this->setPosition(pos);
}

void SSprite::setScale(std::pair<float, float> scale) noexcept
{
	this->_sprite.setScale(scale.first, scale.second);
}

std::pair<size_t, size_t> SSprite::getScale(void) const noexcept
{
	return std::make_pair<size_t, size_t>(this->_sprite.getScale().x, this->_sprite.getScale().y);
}

std::pair<size_t, size_t> SSprite::getSize(void) const noexcept
{
	return std::make_pair<size_t, size_t>(this->_texture.getSize().x, this->_texture.getSize().y);
}

void SSprite::setRotation(float rotation) noexcept
{
	this->_sprite.setRotation(rotation);
}

void SSprite::setTexture(std::string str) noexcept
{
	this->_texture.loadFromFile(getBinaryDir() + "assets/images/" + str);
	this->_sprite.setTexture(this->_texture);
	// 	std::cout << this->_texture.getSize().x << std::endl;
	// 	std::cout << this->_texture.getSize().y << std::endl;
}

void SSprite::setTextureRect(std::pair<size_t, size_t> pos, std::pair<size_t, size_t> size) noexcept
{
	sf::IntRect rect = sf::IntRect(pos.first, pos.second, size.first, size.second);
	this->_sprite.setTextureRect(rect);
}

std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>> SSprite::getTextureRect(void) const noexcept
{
	// std::pair<size_t, size_t> pos = std::make_pair<size_t, size_t>(this->_sprite.getTextureRect().left, this->_sprite.getTextureRect().top);
	// std::pair<size_t, size_t> size = std::make_pair<size_t, size_t>(this->_sprite.getTextureRect().width, this->_sprite.getTextureRect().height);
	// return std::make_pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>>(pos, size);
}
void SSprite::move(std::pair<float, float> pos) noexcept
{
	this->_sprite.move(pos.first, pos.second);
}

void SSprite::setPosition(std::pair<float, float> pos) noexcept
{
	this->_sprite.setPosition(pos.first, pos.second);
}

std::pair<size_t, size_t> SSprite::getPosition(void) const noexcept
{
	return std::make_pair<size_t, size_t>(this->_sprite.getPosition().x, this->_sprite.getPosition().y);
}

void SSprite::draw(IRenderWindow &iRenderWindow) noexcept
{
	SRenderWindow &sRenderWindow = reinterpret_cast<SRenderWindow &>(iRenderWindow);
	sRenderWindow.getWindow().draw(this->_sprite);
}

void SSprite::eventManager(IRenderWindow &iRenderWindow) noexcept
{
}

void SSprite::textEntered(size_t n) noexcept
{
}

void SSprite::handleClick(std::pair<size_t, size_t> button) noexcept
{
}