/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SRenderWindow
*/

#include "SRenderWindow.hpp"
#include "iostream"
#include <typeinfo>
#include "AsioNetwork.hpp"

SRenderWindow::SRenderWindow(std::string name, std::pair<size_t, size_t> size) :
	_window(sf::VideoMode(size.first, size.second), name, sf::Style::Titlebar | sf::Style::Close)
{
	this->setFramerateLimit(30);
	this->_scene = SCENE_LOGIN;
}

void SRenderWindow::setFramerateLimit(size_t fps) noexcept
{
	this->_window.setFramerateLimit(fps);
}

void SRenderWindow::clearWindow(void) noexcept
{
	this->_window.clear(sf::Color(50, 50, 50));
}
void SRenderWindow::displayWindow(void) noexcept
{
	this->_window.display();
}

void SRenderWindow::drawObjects(ADrawable *object) noexcept
{
	if (object->getDraw()) {
		object->draw(*this);
		object->setDraw(false);
	}
}

void SRenderWindow::drawObjects(std::vector<ADrawable *> objects) noexcept
{
	for (auto it = objects.begin(); it != objects.end(); it++) {
		if ((*it)->getDraw()) {
			(*it)->draw(*this);
			(*it)->setDraw(false);
		}
	}
}

void SRenderWindow::setPosition(std::pair<size_t, size_t> pos) noexcept
{
	this->_window.setPosition(sf::Vector2i(pos.first, pos.second));
}

void SRenderWindow::resizeWindow(std::pair<size_t, size_t> size) noexcept
{
	this->_window.setSize(sf::Vector2u(size.first, size.second));
}

std::pair<size_t, size_t> SRenderWindow::getSize(void) const noexcept
{
	sf::Vector2u size = this->_window.getSize();
	return std::make_pair<size_t, size_t>(size.x, size.y);
}

bool SRenderWindow::isOpen(void) const noexcept
{
	return this->_window.isOpen();
}

sf::RenderWindow &SRenderWindow::getWindow(void) noexcept
{
	return this->_window;
}

void SRenderWindow::eventManager(std::vector<ADrawable *> objects) noexcept
{
	while (this->_window.pollEvent(this->_event)) {
		if (this->_event.type == sf::Event::Closed) {
			this->_window.close();
			return;
		}
		if (this->_event.type == sf::Event::TextEntered) {
			for (auto it = objects.begin(); it != objects.end(); it++)
				(*it)->textEntered(this->_event.text.unicode);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// std::cout << "\nClick:" << this->_event.mouseButton.x << ":" << this->_event.mouseButton.y << std::endl;
			for (auto it = objects.begin(); it != objects.end(); it++)
				(*it)->handleClick(std::make_pair<size_t, size_t>(this->_event.mouseButton.x, this->_event.mouseButton.y));
		}
	}
}

inline const char *const BoolToString(bool b)
{
	return b ? "true" : "false";
}

void SRenderWindow::eventManager(std::vector<ADrawable *> objects, RType::AsioNetwork &network) noexcept
{
	t_udp_client_message controls;
	while (this->_window.pollEvent(this->_event)) {
		if (this->_event.type == sf::Event::Closed) {
			this->_window.close();
			network.stop();
			return;
		}
		if (this->_event.type == sf::Event::KeyPressed) {
			if (this->_event.key.code == sf::Keyboard::Z)
				controls.up = true;
			else
				controls.up = false;
			if (this->_event.key.code == sf::Keyboard::S)
				controls.down = true;
			else
				controls.down = false;
			if (this->_event.key.code == sf::Keyboard::Q)
				controls.left = true;
			else
				controls.left = false;
			if (this->_event.key.code == sf::Keyboard::D)
				controls.right = true;
			else
				controls.right = false;
			if (this->_event.key.code == sf::Keyboard::E)
				controls.action = true;
			else
				controls.action = false;
			if (controls.up || controls.down || controls.left || controls.right || controls.action) {
				controls.magic_number = 4242;
				controls.player = static_cast<player_enum>(network.getPlayerId());
				// std::cout << "eventManager" << std::endl;
				// std::cout << "Up: " << BoolToString(controls.up) << std::endl;
				// std::cout << "Down: " << BoolToString(controls.down) << std::endl;
				// std::cout << "Left: " << BoolToString(controls.left) << std::endl;
				// std::cout << "Right: " << BoolToString(controls.right) << std::endl;
				// std::cout << "Action: " << BoolToString(controls.action) << std::endl;
				network.sendUDPmessage(controls);
			}
		}
	}
}