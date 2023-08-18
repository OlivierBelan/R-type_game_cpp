/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SRenderWidnow
*/

#ifndef SRENDERWINDOW_HPP_
#define SRENDERWINDOW_HPP_

#include "ADrawable.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

namespace RType {
	class AsioNetwork;
};

static const int SCENE_LOGIN = 0;
static const int SCENE_LOBBY = 1;
static const int SCENE_GAME = 2;

class SRenderWindow : public IRenderWindow {
public:
	SRenderWindow(std::string, std::pair<size_t, size_t>);
	virtual void clearWindow(void) noexcept;
	virtual void displayWindow(void) noexcept;
	virtual void resizeWindow(std::pair<size_t, size_t>) noexcept;
	virtual void setPosition(std::pair<size_t, size_t>) noexcept;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept;
	virtual void setScene(int scene) noexcept { this->_scene = scene; }
	virtual int getScene(void) const noexcept { return this->_scene; }
	virtual void setFramerateLimit(size_t) noexcept;
	virtual void eventManager(std::vector<ADrawable *>) noexcept;
	virtual void eventManager(std::vector<ADrawable *>, RType::AsioNetwork &) noexcept;
	virtual bool isOpen(void) const noexcept;
	virtual void drawObjects(std::vector<ADrawable *>) noexcept;
	sf::RenderWindow &getWindow(void) noexcept;
	void drawObjects(ADrawable *) noexcept;


private:
	int _scene;
	sf::RenderWindow _window;
	sf::Event _event;
};

#endif /* !SRENDERWIDNOW_HPP_ */
