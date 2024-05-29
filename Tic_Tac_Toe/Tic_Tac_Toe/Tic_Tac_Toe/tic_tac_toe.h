#pragma once
#include <conio.h>
#include <time.h>
#include <stdlib.h>


#define PLAYER_ONE 0
#define PLAYER_TWO 1

#define PLAYER_MEM 2
#define NAME_SIZE 21
#define BOARD_SIZE_X 3
#define BOARD_SIZE_Y 3

#define UP_KEY 'w'
#define LEFT_KEY 'a'
#define DOWN_KEY 's'
#define RIGHT_KEY 'd'
#define DECIDE_KEY ' '

#define PLAYER_MEM 2
#define NAME_SIZE 21
#define BOARD_SIZE_X 3
#define BOARD_SIZE_Y 3

#define NUL '\0'
#define DEL 127
#define LWC 161
#define UPC 223
#define ENTER '\n'

#define MIN_NAME_SIZE 1

typedef enum {
	FALSE,
	TRUE
}BOOL;

typedef enum {
	FIRST,
	LAST,
}FIRSTMOVE;

typedef struct player {
	char player_name[NAME_SIZE];
	FIRSTMOVE turn;
}PLAYER;

