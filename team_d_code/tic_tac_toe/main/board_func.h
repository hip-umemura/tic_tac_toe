#pragma once
#include <stdio.h>
#define BYTE_LIMIT (2)
#define BOARD_CELL (3)
#define TRUE (1)
#define FALSE (0)

typedef enum {
	BLANK,
	PLAYER1_MARK,
	PLAYER2_MARK,
} MARK;

typedef enum {
	NONE, 
	PLAYER1_WIN, 
	PLAYER2_WIN, 
	DRAW
} RESULT;

int ScanInput(void);
void PrintBoard(MARK board[BOARD_CELL][BOARD_CELL]);
RESULT CheckBoard(MARK board[BOARD_CELL][BOARD_CELL]);