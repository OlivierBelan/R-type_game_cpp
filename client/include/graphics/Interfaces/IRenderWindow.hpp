/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IRenderWindow
*/

#ifndef IRENDERWINDOW_HPP_
#define IRENDERWINDOW_HPP_

#include "string"

class IRenderWindow {
public:
	virtual ~IRenderWindow() = default;
	virtual void clearWindow(void) noexcept = 0;
	virtual void displayWindow(void) noexcept = 0;
	virtual void setPosition(std::pair<size_t, size_t>) noexcept = 0;
	virtual void resizeWindow(std::pair<size_t, size_t>) noexcept = 0;
	virtual std::pair<size_t, size_t> getSize(void) const noexcept = 0;
	virtual void setFramerateLimit(size_t) noexcept = 0;
	virtual bool isOpen(void) const noexcept = 0;
	virtual void setScene(int) noexcept = 0;
	virtual int getScene(void) const noexcept = 0;
};

#endif /* !IRENDERWINDOW_HPP_ */
