/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SText
*/

#include "SText.hpp"

SText::SText(std::string text, size_t size, std::pair<size_t, size_t> pos, std::string font)
{
	this->setString(text);
	this->setCharacterSize(size);
	this->setPosition(pos);
	this->setFont(font);
	this->_draw = false;
}

void SText::setString(std::string str) noexcept
{
	this->_text.setString(str);
}

void SText::setCharacterSize(size_t n) noexcept
{
	this->_text.setCharacterSize(n);
}

void SText::setTextColor(size_t r, size_t g, size_t b) noexcept
{
	this->_text.setFillColor(sf::Color(r, g, b));
}

void SText::setPosition(std::pair<size_t, size_t> pos) noexcept
{
	this->_text.setPosition(sf::Vector2f(pos.first, pos.second));
}

void SText::setFont(std::string str) noexcept
{
	this->_font.loadFromFile(getBinaryDir() + "assets/fonts/" + str);
	this->_text.setFont(this->_font);
}

std::string SText::getString(void) const noexcept
{
	std::string str = this->_text.getString();
	return str;
}

std::pair<size_t, size_t> SText::getPosition(void) const noexcept
{
	sf::Vector2f pos = this->_text.getPosition();
	return std::make_pair<size_t, size_t>(pos.x, pos.y);
}

void SText::draw(IRenderWindow &iRenderWindow) noexcept
{
	SRenderWindow &sRenderWindow = reinterpret_cast<SRenderWindow &>(iRenderWindow);
	sRenderWindow.getWindow().draw(this->_text);
}

void SText::eventManager(IRenderWindow &iRenderWindow) noexcept
{
}

void SText::textEntered(size_t n) noexcept
{
}

void SText::handleClick(std::pair<size_t, size_t> pos) noexcept
{
}