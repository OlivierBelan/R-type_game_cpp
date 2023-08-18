/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IEvent
*/

#ifndef IEVENT_HPP_
#define IEVENT_HPP_

#include <map>

enum Key {
	A = 'A',
	B = 'B',
	C = 'C',
	D = 'D',
	E = 'E',
	F = 'F',
	G = 'G',
	H = 'H',
	I = 'I',
	J = 'J',
	K = 'K',
	L = 'L',
	M = 'M',
	N = 'N',
	O = 'O',
	P = 'P',
	Q = 'Q',
	R = 'R',
	S = 'S',
	T = 'T',
	U = 'U',
	V = 'V',
	W = 'W',
	X = 'X',
	Y = 'Y',
	Z = 'Z',
	NUM0 = '0',
	NUM1 = '1',
	NUM2 = '2',
	NUM3 = '3',
	NUM4 = '4',
	NUM5 = '5',
	NUM6 = '6',
	NUM7 = '7',
	NUM8 = '8',
	NUM9 = '9',
	DASH = '.',
	RETURN,
	ESC,
	SPACE,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	null = 0
};

class IEvent {
public:
	virtual ~IEvent() = default;
	std::map<Key, bool> _key;
	std::map<Key, bool> _keyRelease;
};

#endif /* !IEVENT_HPP_ */
