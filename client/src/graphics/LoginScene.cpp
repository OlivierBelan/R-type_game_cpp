/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** LoginScene
*/

#include "LoginScene.hpp"
#include "AsioNetwork.hpp"

LoginScene::LoginScene(IRenderWindow *window) :
	_window(window)
{
	this->_inputIp = new SInput("127.0.0.1", std::make_pair<size_t, size_t>(300, 50), std::make_pair<size_t, size_t>(250, 250),
								std::make_pair<size_t, size_t>(260, 255), "Roboto-Medium.ttf", 30);
	this->_inputPort = new SInput("", std::make_pair<size_t, size_t>(300, 50), std::make_pair<size_t, size_t>(250, 350),
								  std::make_pair<size_t, size_t>(260, 355), "Roboto-Medium.ttf", 30);
	this->_buttonConnect = new SButton("Connection", std::make_pair<size_t, size_t>(200, 50), std::make_pair<size_t, size_t>(300, 450),
									   std::make_pair<size_t, size_t>(320, 455), "Roboto-Medium.ttf", 30);
	this->_title = new SText("RTYPE", 100, std::make_pair<size_t, size_t>(250, 50), "Roboto-Medium.ttf");
	this->_titleIp = new SText("Ip Adress", 25, std::make_pair<size_t, size_t>(250, 210), "Roboto-Medium.ttf");
	this->_titlePort = new SText("Port", 25, std::make_pair<size_t, size_t>(250, 310), "Roboto-Medium.ttf");
	this->_errorMessage = new SText("An error occured, please try again", 20, std::make_pair<size_t, size_t>(250, 540), "Roboto-Medium.ttf");
	this->_kyle = new SSprite("kyle.png", std::make_pair<float, float>(20, 20));

	this->_objects.push_back(this->_inputIp);
	this->_objects.push_back(this->_inputPort);
	this->_objects.push_back(this->_buttonConnect);
	this->_objects.push_back(this->_title);
	this->_objects.push_back(this->_titleIp);
	this->_objects.push_back(this->_titlePort);
	this->_objects.push_back(this->_errorMessage);
	this->_objects.push_back(this->_kyle);

	this->_errorMessage->setTextColor(255, 0, 0);

	this->_isPushed = false;
	this->_error = false;
}

LoginScene::~LoginScene()
{
}

size_t LoginScene::getPort(void) const noexcept
{
	int x;
	try {
		x = std::stoi(this->_port);
	} catch (...) {
		return 0;
	}
	return x;
}

void LoginScene::eventManager(void) noexcept
{
	SRenderWindow *sRenderWindow = reinterpret_cast<SRenderWindow *>(this->_window);
	sRenderWindow->eventManager(this->_objects);
}

void LoginScene::renderWindow(void) noexcept
{
	if (this->_buttonConnect->isPushed()) {
		if (this->_inputIp->getString().length() == 0 || this->_inputPort->getString().length() == 0)
			this->_error = true;
		this->_ip = this->_inputIp->getString();
		this->_port = this->_inputPort->getString();
		this->_buttonConnect->setPushed(false);
		this->_isPushed = true;
		this->_error = false;
		// std::cout << "PUSHED" << std::endl;
	}
	if (this->_error)
		this->_errorMessage->setDraw(true);

	this->_inputIp->setDraw(true);
	this->_inputPort->setDraw(true);
	this->_buttonConnect->setDraw(true);
	this->_title->setDraw(true);
	this->_titleIp->setDraw(true);
	this->_titlePort->setDraw(true);
	// this->_kyle->setDraw(true);

	this->_window->clearWindow();
	SRenderWindow *sRenderWindow = reinterpret_cast<SRenderWindow *>(this->_window);
	sRenderWindow->drawObjects(this->_objects);
	this->_window->displayWindow();
}