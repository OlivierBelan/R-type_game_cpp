/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SEvent
*/

#ifndef SEVENT_HPP_
#define SEVENT_HPP_

#include "IEvent.hpp"
#include <SFML/Graphics.hpp>

class SEvent : public IEvent {
public:
	SEvent();
	~SEvent();
	void update(const sf::Event &event) noexcept;

protected:
private:
	const std::map<Key, sf::Keyboard::Key> _keyDic = {
		{Key::A, sf::Keyboard::A},
		{Key::B, sf::Keyboard::B},
		{Key::C, sf::Keyboard::C},
		{Key::D, sf::Keyboard::D},
		{Key::E, sf::Keyboard::E},
		{Key::F, sf::Keyboard::F},
		{Key::G, sf::Keyboard::G},
		{Key::H, sf::Keyboard::H},
		{Key::I, sf::Keyboard::I},
		{Key::J, sf::Keyboard::J},
		{Key::K, sf::Keyboard::K},
		{Key::L, sf::Keyboard::L},
		{Key::M, sf::Keyboard::M},
		{Key::N, sf::Keyboard::N},
		{Key::O, sf::Keyboard::O},
		{Key::P, sf::Keyboard::P},
		{Key::Q, sf::Keyboard::Q},
		{Key::R, sf::Keyboard::R},
		{Key::S, sf::Keyboard::S},
		{Key::T, sf::Keyboard::T},
		{Key::U, sf::Keyboard::U},
		{Key::V, sf::Keyboard::V},
		{Key::W, sf::Keyboard::W},
		{Key::X, sf::Keyboard::X},
		{Key::Y, sf::Keyboard::Y},
		{Key::Z, sf::Keyboard::Z},
		{Key::NUM0, sf::Keyboard::Num0},
		{Key::NUM1, sf::Keyboard::Num1},
		{Key::NUM2, sf::Keyboard::Num2},
		{Key::NUM3, sf::Keyboard::Num3},
		{Key::NUM4, sf::Keyboard::Num4},
		{Key::NUM5, sf::Keyboard::Num5},
		{Key::NUM6, sf::Keyboard::Num6},
		{Key::NUM7, sf::Keyboard::Num7},
		{Key::NUM8, sf::Keyboard::Num8},
		{Key::NUM9, sf::Keyboard::Num9},
		{Key::DASH, sf::Keyboard::Dash},
		{Key::RETURN, sf::Keyboard::Return},
		{Key::ESC, sf::Keyboard::Escape},
		{Key::SPACE, sf::Keyboard::Space},
		{Key::KEY_UP, sf::Keyboard::Up},
		{Key::KEY_DOWN, sf::Keyboard::Down},
		{Key::KEY_LEFT, sf::Keyboard::Left},
		{Key::KEY_RIGHT, sf::Keyboard::Right},
	};
};

#endif /* !SEVENT_HPP_ */
