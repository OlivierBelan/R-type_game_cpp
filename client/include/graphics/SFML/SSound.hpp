/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** SSound
*/

#ifndef SSOUND_HPP_
#define SSOUND_HPP_

#include "ISound.hpp"
#include "Misc.hpp"
#include <SFML/Audio.hpp>

class SSound : public ISound {
public:
	SSound(std::string, bool);
	virtual void playSound(sound_action) noexcept;

private:
	sf::Sound _sound;
	sf::SoundBuffer _soundBuffer;
};

#endif /* !SSOUND_HPP_ */
