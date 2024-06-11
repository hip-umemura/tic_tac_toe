#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

BOOL RangeNum(char player_input) {

	if (player_input >= '1' && player_input <= '9') {

		return TRUE;
	}else {

		printf("範囲内の値を入力してください。\n");
		return FALSE;
	}
}

BOOL CheckNum(char player_input, char board[ELEMENT]) {

	int tmp = player_input - '0';
	if (board[tmp - 1] == player_input) {
		return TRUE;
	}else {

		printf("既に入力されています。\n");
		return FALSE;
	}
}

JUDGE CheckWin(char board[ELEMENT], JUDGE now_turn, int count_turn) {
	JUDGE result = UNKNOWN;
	int same_mark_count;

	for (int i = 0; i <= (2 * BOARD_LEN); i += BOARD_LEN) {//横のライン
		same_mark_count = 0;
		for (int j = 0; j < MATCH_COUNTER; j++) {
			if (board[i + j] == board[i + j + 1]) {
				same_mark_count++;
			}
		}
	
		if (same_mark_count >= MATCH_COUNTER) {
			return result = (now_turn == CIRCLE) ? CIRCLE_WIN : CROSS_WIN;
		}
	}


	for (int i = 0; i < BOARD_LEN; i++) {//縦のライン
		same_mark_count = 0;
		for (int j = 0; j <= (2 * BOARD_LEN); j += BOARD_LEN) {
			if (board[i + j] == board[i + j + BOARD_LEN]) {
				same_mark_count++;

			}
		}
		
		if (same_mark_count >= MATCH_COUNTER) {
			return result = (now_turn == CIRCLE) ? CIRCLE_WIN : CROSS_WIN;
		}
	}

	same_mark_count = 0;
	for (int i = 0; i <= (BOARD_LEN + 1); i += (BOARD_LEN + 1)) {//左上から右下
		
		if (board[i] == board[i + BOARD_LEN + 1]) {
			same_mark_count++;

		}
	}
	if (same_mark_count >= MATCH_COUNTER) {
			return result = (now_turn == CIRCLE) ? CIRCLE_WIN : CROSS_WIN;
		}

	same_mark_count = 0;
	for (int i = (BOARD_LEN - 1); i <= 2 * (BOARD_LEN - 1); i += (BOARD_LEN - 1)) {//右上から左下

		if (board[i] == board[i + BOARD_LEN - 1]) {
			same_mark_count++;

		}
	}
	if (same_mark_count >= MATCH_COUNTER) {
			return result = (now_turn == CIRCLE) ? CIRCLE_WIN : CROSS_WIN;
		}
	if (result == UNKNOWN) {
		if (count_turn == ELEMENT - 1) {
			result = DROW;
		}
		else {

			return result;
		}
	}
}

