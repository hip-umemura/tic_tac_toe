#pragma once
#include "tic_tac_toe.h"

BOOL isMatchedCondition(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y]){
	if (
		((display_ox_board[0][0] == display_ox_board[1][1]) &&
			(display_ox_board[1][1] == display_ox_board[2][2])) ||
		((display_ox_board[0][2] == display_ox_board[1][1]) &&
			(display_ox_board[1][1] == display_ox_board[2][0]))) {
		return TRUE;
	} 
	else if (
		((display_ox_board[0][0] == display_ox_board[0][1]) &&
			(display_ox_board[0][1] == display_ox_board[0][2])) ||
		((display_ox_board[1][0] == display_ox_board[1][1]) &&
			(display_ox_board[1][1] == display_ox_board[1][2]))) {
		return TRUE;
	}
	else if (
		((display_ox_board[2][0] == display_ox_board[2][1]) &&
			(display_ox_board[2][1] == display_ox_board[2][2])) ||
		((display_ox_board[0][0] == display_ox_board[1][0]) &&
			(display_ox_board[1][0] == display_ox_board[2][0]))) {
		return TRUE;
	}
	else if (
		((display_ox_board[0][1] == display_ox_board[1][1]) &&
			(display_ox_board[1][1] == display_ox_board[2][1])) ||
		((display_ox_board[0][2] == display_ox_board[1][2]) &&
			(display_ox_board[1][2] == display_ox_board[2][2]))) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

BOOL isFilledBOARD(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y]) {
	for (int i = 0; i < BOARD_SIZE_X * BOARD_SIZE_Y; i++) {
		if (
			('1' <= display_ox_board[i / BOARD_SIZE_X][i % BOARD_SIZE_Y]) &&
			(display_ox_board[i / BOARD_SIZE_X][i % BOARD_SIZE_Y] <= '9')) {
			return FALSE;
		}
	}
	return TRUE;
}
