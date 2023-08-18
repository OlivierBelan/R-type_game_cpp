/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

class Error : public std::exception {
public:
	Error(const std::string &ExceptionMessage) :
		_ExceptionMessage(ExceptionMessage){};
	~Error() = default;
	const char *what() const noexcept override { return _ExceptionMessage.c_str(); };

protected:
private:
	std::string _ExceptionMessage;
};

#endif