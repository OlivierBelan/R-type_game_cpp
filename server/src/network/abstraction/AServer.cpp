/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Server
*/

#include "AServer.hpp"
#include <boost/asio.hpp>
#include <thread>

#ifdef unix
#include <dirent.h>
#include <unistd.h>
#endif

std::string getBinaryDir()
{
#ifdef unix
	char buffer[BUFSIZ];
	size_t n = readlink("/proc/self/exe", buffer, BUFSIZ);
	buffer[n] = 0;
	std::string res(buffer);
	res = res.substr(0, res.find_last_of('/') + 1);
	return res;
#else
#include <string>
#include <windows.h>
	char result[MAX_PATH];
	std::string res(result, GetModuleFileName(NULL, result, MAX_PATH));
	res = res.substr(0, res.find_last_of('/') + 1);
	std::cout << "path for windows : " << res << std::endl;
	return res;
#endif
}

std::vector<std::pair<std::size_t, std::string>> findFiles(const std::string &dir, const std::string &content)
{
#ifdef unix
	std::vector<std::pair<std::size_t, std::string>> res;
	std::string file;
	std::size_t counter = 1;
	DIR *pDir;
	struct dirent *pDirent;
	pDir = opendir(dir.c_str());
	while ((pDirent = readdir(pDir)) != NULL) {
		file = pDirent->d_name;
		size_t found = file.find(content);
		if (found != std::string::npos) {
			res.push_back(std::pair<std::size_t, std::string>(counter, file));
			counter++;
		}
	}
	return res;
#else
	std::vector<std::pair<std::size_t, std::string>> res;
	HANDLE hFind;
	WIN32_FIND_DATA FindFileData;

	if ((hFind = FindFirstFile("dir" + "*" + content + "*", &FindFileData)) != INVALID_HANDLE_VALUE) {
		do {
			printf("%s\n", FindFileData.cFileName);
		} while (FindNextFile(hFind, &FindFileData));
		FindClose(hFind);
	}
	return res;
#endif
}

RType::AServer::AServer()
{
	this->_libDir = getBinaryDir() + "lib/";
	this->_systems = findFiles(this->_libDir, "lib");
	for (auto &Elem : this->_systems) {
		std::cout << Elem.first << " : " << Elem.second << std::endl;
	}
	std::cout << "You can add / remove external lib as the following way : +1 or -1" << std::endl
			  << std::endl;
}

void RType::AServer::handleInput() noexcept
{
	// Error handling
	if (this->_message[0] != '-' && this->_message[0] != '+') {
		std::cout << "Bad formatted input : " << this->_message << std::endl;
		return;
	}
	std::size_t counter = 0;
	try {
		counter = std::stoi(this->_message.substr(1, this->_message.length()));
	} catch (std::exception &e) {
		std::cout << "Bad formatted input : " << this->_message << std::endl;
		return;
	}
	bool exist = false;
	for (auto &Elem : this->_systems) {
		if (Elem.first == counter)
			exist = true;
	}
	if (exist == false) {
		std::cout << "Bad formatted input : " << this->_message << std::endl;
		return;
	}
	if (this->_message[0] == '+') {
		// Adding lib
		for (auto &Elem : this->_selectedSystems) {
			if (Elem.first == counter) {
				std::cout << "Library already selected" << std::endl;
				return;
			}
		}
		for (auto &Elem : this->_systems) {
			if (Elem.first == counter) {
				this->_selectedSystems.push_back(Elem);
				std::cout << "Added lib : " << Elem.second << std::endl;
				for (auto &gameServer : this->_gameServer) {
					gameServer->AddLibToGameEngin(Elem.second);
				}
			}
		}
	} else {
		// Removing lib
		for (auto it = this->_selectedSystems.begin(); it != this->_selectedSystems.end(); it++) {
			if (it->first == counter) {
				std::cout << "Removed lib : " << it->second << std::endl;
				this->_selectedSystems.erase(it);
				for (auto &gameServer : this->_gameServer)
					gameServer->RemoveLibToGameEngin(it->second);
				return;
			}
		}
		std::cout << "Library isn't selected" << std::endl;
	}
}

void RType::AServer::_startReading() noexcept
{
	std::thread([this] {
		while (std::cin) {
			std::cin >> this->_message;
			if (!std::cin)
				continue;
			this->handleInput();
		}
		this->stop();
	})
		.detach();
}
