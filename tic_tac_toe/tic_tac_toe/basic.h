#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>

#define NAME_LEN (10)	//ƒvƒŒƒCƒ„[–¼‚Ì’·‚³ãŒÀ
#define FALSE (0)	//gFALSEh‚ğ0‚Æ‚·‚é
#define TRUE (1)	 //gTRUEh‚ğ1‚Æ‚·‚é

typedef enum
{
	FIRST_TURN,
	SECOND_TURN,
} TURN;

<<<<<<< HEAD
typedef struct player
=======
typedef struct playaer
>>>>>>> 2c948bdb7dc2d619b8721acbb517ef3abee730d8
{
	char* name; //player–¼
	char piece; //‹î
} PLAYER;

#endif