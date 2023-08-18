/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** main
*/

#include "Window.hpp"
#include "SRenderWindow.hpp"
#include "Error.hpp"
#include "iostream"

int main()
{
	IRenderWindow *renderWindow = new SRenderWindow("RType", std::make_pair<size_t, size_t>(800, 600));
	Window win(renderWindow);
	win.run();
	return 0;
}

// int main()
// {
// 	IRenderWindow *window = new SRenderWindow("RType", std::make_pair<size_t, size_t>(800, 600));
// 	RType::AsioNetwork network(window);
// 	LoginScene loginScene(window);
// 	LobbyScene lobbyScene(window, network);
// 	GameScene gameScene(window, network);
// 	// window->resizeWindow(std::make_pair<size_t, size_t>(1280, 720));
// 	// window->setPosition(std::make_pair<size_t, size_t>(320, 180));
// 	while (window->isOpen()) {
// 		if (window->getScene() == SCENE_LOGIN) {
// 			if (loginScene.isPushed()) {
// 				try {
// 					std::cout << "Connection..." << std::endl;
// 					network.init(loginScene.getIp(), loginScene.getPort());
// 					network.async_read();
// 					network.run();
// 					window->setScene(SCENE_LOBBY);
// 					std::cout << "SUCCESS" << std::endl;
// 				} catch (Error &e) {
// 					std::cerr << e.what() << std::endl;
// 					loginScene.setError(true);
// 					std::cout << "ERROR" << std::endl;
// 				}
// 				loginScene.setPushed(false);
// 			}
// 			loginScene.eventManager();
// 			loginScene.renderWindow();
// 		} else if (window->getScene() == SCENE_LOBBY) {
// 			if (network.getLobbyReady()) {
// 				window->resizeWindow(std::make_pair<size_t, size_t>(1280, 720));
// 				window->setPosition(std::make_pair<size_t, size_t>(0, 0));
// 				window->setScene(SCENE_GAME);
// 			}
// 			lobbyScene.eventManager();
// 			if (network.getUpdate()) {
// 				network.setUpdate(false);
// 				lobbyScene.refreshLobby(network.getLobbyStatus());
// 			}
// 			lobbyScene.renderWindow();
// 		} else if (window->getScene() == SCENE_GAME) {
// 			if (network.getNewEntity()) {
// 				network.setNewEntity(false);
// 				gameScene.handleNewEntity(network.getNewEntityStruct());
// 			}
// 			gameScene.eventManager();
// 			gameScene.renderWindow();
// 		}
// 	}
// 	return 0;
// }