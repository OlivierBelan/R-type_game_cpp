/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SText
*/

#ifndef STEXT_HPP_
#define STEXT_HPP_

#include "IText.hpp"
#include <SFML/Graphics.hpp>
#include "SRenderWindow.hpp"
#include "Misc.hpp"

class SText : public IText {
public:
	SText(std::string, size_t, std::pair<size_t, size_t>, std::string);
	virtual void setString(std::string) noexcept;
	virtual void setCharacterSize(size_t) noexcept;
	virtual void setPosition(std::pair<size_t, size_t>) noexcept;
	virtual void setFont(std::string) noexcept;
	virtual void setTextColor(size_t, size_t, size_t) noexcept;
	virtual std::string getString(void) const noexcept;
	virtual std::pair<size_t, size_t> getPosition(void) const noexcept;
	virtual void draw(IRenderWindow &) noexcept;
	virtual void eventManager(IRenderWindow &) noexcept;
	virtual void textEntered(size_t) noexcept;
	virtual void handleClick(std::pair<size_t, size_t>) noexcept;

private:
	sf::Text _text;
	sf::Font _font;
};

#endif /* !STEXT_HPP_ */
