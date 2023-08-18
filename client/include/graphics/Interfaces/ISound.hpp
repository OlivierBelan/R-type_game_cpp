/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ISound
*/

#ifndef ISOUND_HPP_
#define ISOUND_HPP_

#include "iostream"

enum sound_action {
	PLAY = 0,
	STOP = 1,
	PAUSE = 2
};

class ISound {
public:
	virtual ~ISound() = default;
	virtual void playSound(sound_action) noexcept = 0;
};

#endif /* !ISOUND_HPP_ */
