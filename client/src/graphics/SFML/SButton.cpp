/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SButton
*/

#include "SButton.hpp"
#include "Misc.hpp"

SButton::SButton(std::string text, std::pair<size_t, size_t> size, std::pair<size_t, size_t> Rpos, std::pair<size_t, size_t> Tpos, std::string font, size_t characterSize)
{
	this->setSize(size);
	this->setRectPosition(Rpos);
	this->setRectColor(225, 225, 225);
	this->setOutlineColor(255, 0, 0);

	this->setTextPosition(Tpos);
	this->setString(text);
	this->setFont(font);
	this->setCharacterSize(characterSize);
	this->setTextColor(0, 0, 0);

	this->_isPushed = false;
}

void SButton::setString(std::string str) noexcept
{
	this->_text.setString(str);
}

void SButton::setSize(std::pair<size_t, size_t> size) noexcept
{
	this->_rect.setSize(sf::Vector2f(size.first, size.second));
}

std::pair<size_t, size_t> SButton::getSize(void) const noexcept
{
	return std::make_pair<size_t, size_t>(this->_rect.getSize().x, this->_rect.getSize().y);
}

void SButton::setCharacterSize(size_t n) noexcept
{
	this->_text.setCharacterSize(n);
}

void SButton::setTextPosition(std::pair<size_t, size_t> pos) noexcept
{
	this->_text.setPosition(sf::Vector2f(pos.first, pos.second));
}

void SButton::setTextColor(size_t r, size_t g, size_t b) noexcept
{
	this->_text.setFillColor(sf::Color(r, g, b));
}

void SButton::setRectPosition(std::pair<size_t, size_t> pos) noexcept
{
	this->_rect.setPosition(sf::Vector2f(pos.first, pos.second));
}

void SButton::setRectColor(size_t r, size_t g, size_t b) noexcept
{
	this->_rect.setFillColor(sf::Color(r, g, b));
}

void SButton::setOutlineColor(size_t r, size_t g, size_t b) noexcept
{
	this->_rect.setOutlineColor(sf::Color(r, g, b));
}

void SButton::setOutlineThickness(size_t n) noexcept
{
	this->_rect.setOutlineThickness(n);
}

void SButton::setFont(const std::string &str) noexcept
{
	this->_font.loadFromFile(getBinaryDir() + "assets/fonts/" + str);
	this->_text.setFont(this->_font);
}

std::string SButton::getString(void) const noexcept
{
	std::string str = this->_text.getString();
	return str;
}

std::pair<size_t, size_t> SButton::getPosition(void) const noexcept
{
	sf::Vector2f pos = this->_text.getPosition();
	return std::make_pair<size_t, size_t>(pos.x, pos.y);
}

bool SButton::isPushed(void) const noexcept
{
	return this->_isPushed;
}

void SButton::setPushed(bool state) noexcept
{
	this->_isPushed = state;
}

void SButton::draw(IRenderWindow &iRenderWindow) noexcept
{
	SRenderWindow &sRenderWindow = reinterpret_cast<SRenderWindow &>(iRenderWindow);
	sRenderWindow.getWindow().draw(this->_rect);
	sRenderWindow.getWindow().draw(this->_text);
}

void SButton::eventManager(IRenderWindow &iRenderWindow) noexcept
{
	// SRenderWindow &sRenderWindow = reinterpret_cast<SRenderWindow &>(iRenderWindow);
}

void SButton::textEntered(size_t) noexcept
{
}

void SButton::handleClick(std::pair<size_t, size_t> button) noexcept
{
	std::pair<size_t, size_t> pos = this->getPosition();
	std::pair<size_t, size_t> size = this->getSize();
	// std::cout << "pos:" << pos.first << ":" << pos.second << std::endl;
	// std::cout << "size:" << size.first << ":" << size.second << std::endl;
	if ((button.first > pos.first && button.first < pos.first + size.first) && (button.second > pos.second && button.second < pos.second + size.second)) {
		this->_isPushed = true;
		// std::cout << this->getString() << " - HIT" << std::endl;
	} else {
		// std::cout << this->getString() << " - MISS" << std::endl;
		this->_isPushed = false;
	}
}