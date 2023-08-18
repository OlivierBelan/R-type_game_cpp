/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SInput
*/

#include "SInput.hpp"
#include "Misc.hpp"
#include "iostream"

SInput::SInput(std::string text, std::pair<size_t, size_t> size, std::pair<size_t, size_t> Rpos, std::pair<size_t, size_t> Tpos, std::string font, size_t characterSize)
{
	this->setSize(size);
	this->setRectPosition(Rpos);
	this->setRectColor(255, 255, 255);
	this->setOutlineColor(255, 0, 0);

	this->setTextPosition(Tpos);
	this->setString(text);
	this->setFont(font);
	this->setCharacterSize(characterSize);
	this->setTextColor(0, 0, 0);

	this->_isSelected = false;
}

void SInput::setString(std::string str) noexcept
{
	this->_text.setString(str);
}

void SInput::setSize(std::pair<size_t, size_t> size) noexcept
{
	this->_rect.setSize(sf::Vector2f(size.first, size.second));
}

std::pair<size_t, size_t> SInput::getSize(void) const noexcept
{
	return std::make_pair<size_t, size_t>(this->_rect.getSize().x, this->_rect.getSize().y);
}

void SInput::setCharacterSize(size_t n) noexcept
{
	this->_text.setCharacterSize(n);
}

void SInput::setTextPosition(std::pair<size_t, size_t> pos) noexcept
{
	this->_text.setPosition(sf::Vector2f(pos.first, pos.second));
}

void SInput::setTextColor(size_t r, size_t g, size_t b) noexcept
{
	this->_text.setFillColor(sf::Color(r, g, b));
}

void SInput::setRectPosition(std::pair<size_t, size_t> pos) noexcept
{
	this->_rect.setPosition(sf::Vector2f(pos.first, pos.second));
}

void SInput::setRectColor(size_t r, size_t g, size_t b) noexcept
{
	this->_rect.setFillColor(sf::Color(r, g, b));
}

void SInput::setOutlineColor(size_t r, size_t g, size_t b) noexcept
{
	this->_rect.setOutlineColor(sf::Color(r, g, b));
}

void SInput::setOutlineThickness(size_t n) noexcept
{
	this->_rect.setOutlineThickness(n);
}

void SInput::setFont(const std::string &str) noexcept
{
	this->_font.loadFromFile(getBinaryDir() + "assets/fonts/" + str);
	this->_text.setFont(this->_font);
}

std::string SInput::getString(void) const noexcept
{
	std::string str = this->_text.getString();
	return str;
}

std::pair<size_t, size_t> SInput::getPosition(void) const noexcept
{
	sf::Vector2f pos = this->_text.getPosition();
	return std::make_pair<size_t, size_t>(pos.x, pos.y);
}

void SInput::setSelected(bool state) noexcept
{
	this->_isSelected = state;
}

bool SInput::isSelected(void) const noexcept
{
	return this->_isSelected;
}

void SInput::draw(IRenderWindow &iRenderWindow) noexcept
{
	SRenderWindow &sRenderWindow = reinterpret_cast<SRenderWindow &>(iRenderWindow);
	sRenderWindow.getWindow().draw(this->_rect);
	sRenderWindow.getWindow().draw(this->_text);
}

void SInput::eventManager(IRenderWindow &iRenderWindow) noexcept
{
	// SRenderWindow &sRenderWindow = reinterpret_cast<SRenderWindow &>(iRenderWindow);
}

void SInput::textEntered(size_t n) noexcept
{
	if (!this->_isSelected)
		return;
	if (n == 8)
		this->setString(this->getString().substr(0, this->getString().length() - 1));
	else if (n < 128 && this->getString().length() <= 16)
		this->setString(this->getString() += static_cast<char>(n));
}

void SInput::handleClick(std::pair<size_t, size_t> button) noexcept
{
	std::pair<size_t, size_t> pos = this->getPosition();
	std::pair<size_t, size_t> size = this->getSize();
	// std::cout << "pos:" << pos.first << ":" << pos.second << std::endl;
	// std::cout << "size:" << size.first << ":" << size.second << std::endl;
	if ((button.first > pos.first && button.first < pos.first + size.first) && (button.second > pos.second && button.second < pos.second + size.second)) {
		this->setOutlineThickness(5);
		this->_isSelected = true;
		// std::cout << this->getString() << " - HIT" << std::endl;
	} else {
		// std::cout << this->getString() << " - MISS" << std::endl;
		this->setOutlineThickness(0);
		this->_isSelected = false;
	}
}