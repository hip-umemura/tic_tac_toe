#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>

#define NAME_LEN (10)	//�v���C���[���̒������
#define FALSE (0)	//�gFALSE�h��0�Ƃ���
#define TRUE (1)	 //�gTRUE�h��1�Ƃ���

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
	char* name; //player��
	char piece; //��
} PLAYER;

#endif