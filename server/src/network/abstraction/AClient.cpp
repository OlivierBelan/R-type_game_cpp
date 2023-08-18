/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AClient
*/

#include "AClient.hpp"

unsigned int RType::AClient::getId() const noexcept
{
	return this->_id;
}

void RType::AClient::setId(unsigned int new_id) noexcept
{
	this->_id = new_id;
}

void RType::AClient::setUDP(unsigned int new_udp) noexcept
{
	this->_udp = new_udp;
}

unsigned int RType::AClient::getUDP() const noexcept
{
	return this->_udp;
}