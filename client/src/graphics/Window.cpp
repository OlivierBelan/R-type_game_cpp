/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Window
*/

#include "Window.hpp"
#include "AsioNetwork.hpp"

Window::Window(IRenderWindow *renderWindow) :
	_renderWindow(renderWindow),
	_network(*this),
	_loginScene(renderWindow),
	_lobbyScene(renderWindow, this->_network),
	_gameScene(renderWindow, this->_network)
{
}

Window::~Window()
{
}

void Window::handleNewEntity(t_entity entity) noexcept
{
	this->_gameScene.handleNewEntity(entity);
}

void Window::run(void) noexcept
{
	while (this->_renderWindow->isOpen()) {
		if (this->_renderWindow->getScene() == SCENE_LOGIN) {
			if (this->_loginScene.isPushed()) {
				try {
					std::cout << "Connection..." << std::endl;
					this->_network.init(this->_loginScene.getIp(), this->_loginScene.getPort());
					this->_network.async_read();
					this->_network.run();
					this->_renderWindow->setScene(SCENE_LOBBY);
					std::cout << "SUCCESS" << std::endl;
				} catch (Error &e) {
					std::cerr << e.what() << std::endl;
					this->_loginScene.setError(true);
					std::cout << "ERROR" << std::endl;
				}
				this->_loginScene.setPushed(false);
			}
			this->_loginScene.eventManager();
			this->_loginScene.renderWindow();
		} else if (this->_renderWindow->getScene() == SCENE_LOBBY) {
			if (this->_network.getLobbyReady()) {
				this->_renderWindow->resizeWindow(std::make_pair<size_t, size_t>(1280, 720));
				this->_renderWindow->setPosition(std::make_pair<size_t, size_t>(0, 0));
				this->_renderWindow->setScene(SCENE_GAME);
			}
			this->_lobbyScene.eventManager();
			if (this->_network.getUpdate()) {
				this->_network.setUpdate(false);
				this->_lobbyScene.refreshLobby(this->_network.getLobbyStatus());
			}
			this->_lobbyScene.renderWindow();
		} else if (this->_renderWindow->getScene() == SCENE_GAME) {
			this->_gameScene.eventManager();
			this->_gameScene.renderWindow();
		}
	}
}
