/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** LoginWindow
*/

#ifndef LOGINSCENE_HPP_
#define LOGINSCENE_HPP_

#include "iostream"
#include "string"
#include "SText.hpp"
#include "SInput.hpp"
#include "SRenderWindow.hpp"
#include "SButton.hpp"
#include "SSprite.hpp"

class LoginScene {
public:
	LoginScene(IRenderWindow *);
	~LoginScene();
	// bool windowIsOpen(void) const noexcept;
	void eventManager(void) noexcept;
	void renderWindow(void) noexcept;
	bool isPushed(void) const noexcept { return this->_isPushed; }
	void setPushed(bool state) noexcept { this->_isPushed = state; }
	void setError(bool error) noexcept { this->_error = error; }
	std::string getIp(void) const noexcept { return this->_ip; }
	size_t getPort(void) const noexcept;
	bool getError(void) const noexcept { return this->_error; }

private:
	bool _error;
	bool _isPushed;

	std::string _ip;
	std::string _port;

	IRenderWindow *_window;
	IInput *_inputIp;
	IInput *_inputPort;
	IButton *_buttonConnect;
	IText *_title;
	IText *_titleIp;
	IText *_titlePort;
	IText *_errorMessage;
	SSprite *_kyle;

	std::vector<ADrawable *> _objects;
	// sf::RectangleShape _inputPort;
	// sf::RectangleShape _buttonConnect;
	// sf::Event _event;
	// sf::Sprite _test;

	// Text _title;
	// Text _titleIp;
	// Text _titlePort;
	// Text _textIp;
	// Text _textPort;
	// Text _buttonTitle;
	// Text _errorMessage;

	// bool checkFieldSelection(sf::RectangleShape &, sf::RectangleShape &, size_t, size_t) noexcept;
	// bool isSelected(sf::RectangleShape &) noexcept;
	// void handleButton(sf::RectangleShape &, size_t, size_t) noexcept;
	// void editText(std::string &) noexcept;
};

#endif /* !LOGINWINDOW_HPP_ */
