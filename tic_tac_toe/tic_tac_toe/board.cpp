#include <stdio.h>
#include "board.h"

char board[BOARD_SIZE][BOARD_SIZE];

void print_now_board(void) {
	int column; 
	printf("　 1   2   3\n");
	printf(" -------------\n");
	printf("1|");
	for (column = 0; column < 3; column++) {
		printf(" %c | ", board[0][column]);
	}
	printf("\n -------------\n");
	printf("2|");
	for (column = 0; column < 3; column++) {
		printf(" %c | ", board[1][column]);
	}
	printf("\n -------------\n");
	printf("3|");
	for (column = 0; column < 3; column++) {
		printf(" %c | ", board[2][column]);
	}
	printf("\n -------------\n\n"); 

}

int put_piece(int row, int column, PLAYER player) {
	if (row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE && board[row][column] == ' ') {
		board[row][column] = player.piece;
		return TRUE; //駒を配置出来た場合にはTRUE(1)
	}
	else {
		return FALSE;// 配置出来なかった場合（座標が不正または駒が既に配置されている）にはFALSE(0)を戻り値として返す。
	}
}

RESULT judge_game(void) {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			if (board[row][column] == ' ') {
				return NONE;
			}
		}
	}
	for (int row = 0; row < BOARD_SIZE; row++) {
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
			return WIN;
		}
	}
	for (int column = 0; column < BOARD_SIZE; column++) {
		if (board[0][column] == board[1][column] && board[1][column] == board[2][column] && board[0][column] != ' ') {
			return WIN;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return WIN; 
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
		return WIN;  
	}
	else {
		return DRAW;
	}
}

void clean_board(void) {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			board[row][column] = ' ';
		}
	}
}
