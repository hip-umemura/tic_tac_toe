#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "basic.h"

#define BOARD_SIZE (3)

typedef enum
{
	WIN,
	DRAW,
	NONE,
}RESULT;

//  プロトタイプ宣言
void print_now_board(void);
int put_piece(int row, int column, PLAYER player);
RESULT judge_game(void);
void clean_board(void);

#endif