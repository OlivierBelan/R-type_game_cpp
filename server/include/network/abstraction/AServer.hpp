/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server
*/

#pragma once

#include "AGameServer.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace RType {
	class AServer {
	public:
		AServer();
		virtual ~AServer() = default;

	public:
		void _startReading() noexcept;

	private:
		void handleInput() noexcept;


	public:
		virtual void run() noexcept = 0;
		virtual void stop() noexcept = 0;
		virtual void createGameInstance() noexcept = 0;

	protected:
		std::vector<std::shared_ptr<RType::AGameServer>> _gameServer;
		std::vector<std::pair<std::size_t, std::string>> _selectedSystems;

	private:
		std::string _message;
		std::string _libDir;
		std::vector<std::pair<std::size_t, std::string>> _systems;
	};
}; // namespace RType
