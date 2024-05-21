#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>

#define NAME_LEN (10)	//ƒvƒŒƒCƒ„[–¼‚Ì’·‚³ãŒÀ
#define FALSE (0)		//gFALSEh‚ğ0‚Æ‚·‚é
#define TRUE (1)		//gTRUEh‚ğ1‚Æ‚·‚é

typedef enum
{
	FIRST_TURN,
	SECOND_TURN,
} TURN;

typedef struct player
{
	char* name; //player–¼
	char piece; //‹î
} PLAYER;

#endif