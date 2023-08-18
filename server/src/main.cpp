/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** main
*/

#include <iostream>
#include "AsioServer.hpp"

int main(int ac, char **av)
{
	RType::AsioServer asio_server;

	asio_server._startReading();
	asio_server.createGameInstance();
	asio_server.run();
	return 0;
}