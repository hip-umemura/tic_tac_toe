#pragma once

#include "tic_tac_toe.c"

#define PLAYER_ONE 0
#define PLAYER_TWO 1

typedef enum { 
	FIRST, 
	LAST,
}FIRSTMOVE; 

typedef struct player {
	char player_name[NAME_SIZE];
	FIRSTMOVE turn;
}PLAYER;