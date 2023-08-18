/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SInput
*/

#ifndef SINPUT_HPP_
#define SINPUT_HPP_

#include "IInput.hpp"
#include "Misc.hpp"
#include "SRenderWindow.hpp"
#include <SFML/Graphics.hpp>

class SInput : public IInput {
public:
	SInput(std::string, std::pair<size_t, size_t>, std::pair<size_t, size_t>, std::pair<size_t, size_t>, std::string, size_t);
	virtual void setString(std::string) noexcept;
	virtual void setSize(std::pair<size_t, size_t>) noexcept;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept;
	virtual void setCharacterSize(size_t) noexcept;
	virtual void setTextPosition(std::pair<size_t, size_t>) noexcept;
	virtual void setTextColor(size_t, size_t, size_t) noexcept;
	virtual void setRectPosition(std::pair<size_t, size_t>) noexcept;
	virtual void setRectColor(size_t, size_t, size_t) noexcept;
	virtual void setOutlineColor(size_t, size_t, size_t) noexcept;
	virtual void setOutlineThickness(size_t) noexcept;
	virtual void setFont(const std::string &) noexcept;
	virtual std::string getString(void) const noexcept;
	virtual std::pair<size_t, size_t> getPosition(void) const noexcept;
	virtual void draw(IRenderWindow &) noexcept;
	virtual void eventManager(IRenderWindow &) noexcept;
	virtual void textEntered(size_t) noexcept;
	virtual void handleClick(std::pair<size_t, size_t>) noexcept;
	virtual bool isSelected(void) const noexcept;
	virtual void setSelected(bool) noexcept;

private:
	bool _isSelected;
	sf::Text _text;
	sf::Font _font;
	sf::RectangleShape _rect;
};

#endif /* !SINPUT_HPP_ */
