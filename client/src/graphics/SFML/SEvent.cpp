/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SEvent
*/

#include "SEvent.hpp"
#include "iostream"

SEvent::SEvent()
{
	for (auto key_it = this->_key.begin(); key_it != this->_key.end(); key_it++)
		key_it->second = false;
}

SEvent::~SEvent()
{
}

void SEvent::update(const sf::Event &event) noexcept
{
	for (auto dic_it = this->_keyDic.begin(); dic_it != this->_keyDic.end(); dic_it++)
		if (dic_it->second == event.key.code)
			this->_key[dic_it->first] = true;
		else
			this->_key[dic_it->first] = false;
	// if (!event.KeyPressed)
	// {
	// 	for (auto dic_it = this->_keyDic.begin(); dic_it != this->_keyDic.end(); dic_it++)
	// 	{
	// 		if (dic_it->second == event.key.code)
	// 		{
	// 			this->_keyRelease[dic_it->first] = true;
	// 		}
	// 		else
	// 		{
	// 			this->_keyRelease[dic_it->first] = false;
	// 		}
	// 	}
	// }
}