#pragma once

#include "tic_tac_toe.h"

void ShowPlayer(PLAYER now_player);
void ShowBoard(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y],
	char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y]);
int Input(void);
void RangeJudgeException(int* p_move_x, int* p_move_y, int direction);
BOOL MarkPosition(PLAYER now_player, char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], char* p_dispaly_ox_board);
