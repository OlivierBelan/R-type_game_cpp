/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SButton
*/

#ifndef SBUTTON_HPP_
#define SBUTTON_HPP_

#include "IButton.hpp"
#include "Misc.hpp"
#include "SRenderWindow.hpp"
#include <SFML/Graphics.hpp>

class SButton : public IButton {
public:
	SButton(std::string, std::pair<size_t, size_t>, std::pair<size_t, size_t>, std::pair<size_t, size_t>, std::string, size_t);
	virtual void setString(std::string) noexcept;
	virtual void setSize(std::pair<size_t, size_t>) noexcept;
	virtual bool isPushed(void) const noexcept;
	virtual void setPushed(bool) noexcept;
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

private:
	bool _isPushed;
	sf::Text _text;
	sf::Font _font;
	sf::RectangleShape _rect;
};

#endif /* !SBUTTON_HPP_ */
