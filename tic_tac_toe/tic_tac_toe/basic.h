#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>

#define NAME_LEN (10)	//プレイヤー名の長さ上限
#define FALSE (0)	//“FALSE”を0とする
#define TRUE (1)	 //“TRUE”を1とする

typedef enum
{
	FIRST_TURN,
	SECOND_TURN,
} TURN;

<<<<<<< HEAD
typedef struct 
=======
typedef struct playaer
>>>>>>> 2c948bdb7dc2d619b8721acbb517ef3abee730d8
{
	char* name; //player名
	char piece; //駒
} PLAYER;

#endif