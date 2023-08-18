/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Misc
*/

#include "Misc.hpp"
#include <boost/asio.hpp>

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
	return res;
#endif
}