#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>

#define NAME_LEN (10)	//�v���C���[���̒������
#define FALSE (0)		//�gFALSE�h��0�Ƃ���
#define TRUE (1)		//�gTRUE�h��1�Ƃ���

typedef enum
{
	FIRST_TURN,
	SECOND_TURN,
} TURN;

typedef struct player
{
	char* name; //player��
	char piece; //��
} PLAYER;

#endif