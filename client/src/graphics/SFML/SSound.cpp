/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SSound
*/

#include "SSound.hpp"

SSound::SSound(std::string path, bool loop)
{
	this->_soundBuffer.loadFromFile(getBinaryDir() + "assets/sounds/" + path);
	this->_sound.setBuffer(this->_soundBuffer);
	this->_sound.setLoop(loop);
}

void SSound::playSound(sound_action action) noexcept
{
	if (action == sound_action::PLAY)
		this->_sound.play();
	else if (action == sound_action::STOP)
		this->_sound.stop();
	else if (action == sound_action::PAUSE)
		this->_sound.pause();
}