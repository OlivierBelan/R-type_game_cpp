#ifndef STRUCT_H_
#define STRUCT_H_

enum player_enum {
	PLAYER_1 = 1,
	PLAYER_2 = 2,
	PLAYER_3 = 3,
	PLAYER_4 = 4,
};

typedef struct udp_client_message {
	int magic_number;
	player_enum player;
	bool up;
	bool down;
	bool left;
	bool right;
	bool action;
} t_udp_client_message;

typedef struct entity {
	int magic_number;
	char sprite[100];
	int id;
	float posX;
	float posY;
	float speed;
	int direction;
	bool render;
	bool up;
	bool down;
	bool left;
	bool right;
} t_entity;

typedef struct lobby_udp
{
	int magic_number;
	unsigned short int udp_port;
} t_lobby_udp;
typedef struct lobby_resp
{
	int magic_number;
	bool ready;
} t_lobby_resp;

typedef struct player
{
	bool connected;
	bool ready;
} t_player;

typedef struct lobby
{
	int magic_number;
	int player_id;
	t_player player_1;
	t_player player_2;
	t_player player_3;
	t_player player_4;
} t_lobby;

#endif