#include <stdio.h>
#include "board.h"

char board[BOARD_SIZE][BOARD_SIZE];	// 盤面をグローバル変数で定義（char型）

void print_now_board(void) { // 盤面の状況を表示

		int row, column; //行、列
		for (column = 0; column < BOARD_SIZE; column++) {
			printf("   %d", column + 1);
		}
		printf("\n");
		for (row = 0; row < BOARD_SIZE; row++) {
			printf(" -------------\n");
			printf("%d|", row + 1);
			for (column = 0; column < BOARD_SIZE; column++) {
				printf(" %c |", board[row][column]);
			}
			printf("\n");
		}
		printf(" -------------\n");
}

int put_piece(int row, int column, PLAYER player) {
	row--; // 1から始まる入力を0から始まるインデックスに変換
	column--;
	if (((row >= 0) && (row < BOARD_SIZE)) && ((column >= 0) && (column < BOARD_SIZE)) && (board[row][column] == ' ')) {
		board[row][column] = player.piece;
		return TRUE; //駒を配置出来た場合にはTRUE(1)
	}
	else {
		return FALSE;// 配置出来なかった場合（座標が不正または駒が既に配置されている）にはFALSE(0)を戻り値として返す。
	}
}

RESULT judge_game(void) {
	for (int row = 0; row < BOARD_SIZE; row++) {
		if ((board[row][0] == board[row][1]) && (board[row][1] == board[row][2]) && (board[row][0] != ' ')) {
			return WIN; //　行をチェックしてOXがそろっているとき
		}
	}
	for (int column = 0; column < BOARD_SIZE; column++) {
		if ((board[0][column] == board[1][column]) && (board[1][column] == board[2][column]) && (board[0][column] != ' ')) {
			return WIN; //　列をチェックしてOXがそろっているとき
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' ')) {
		return WIN; //　右斜めがそろっているとき
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != ' ')) {
		return WIN; // 左斜めがそろっているとき
	}
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			if (board[row][column] == ' ') {
				return NONE; // まだ空きスペースがあるならNONE
			}
		}
	}
	return DRAW; // 全てのスペースが埋まっているならDRAW
}

void clean_board(void) { // 盤面を初期化
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			board[row][column] = ' ';
		}
	}
}
