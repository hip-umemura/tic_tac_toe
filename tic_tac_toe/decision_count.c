#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

BOOL RangeNum(char input_num) {
	BOOL range;
	if (input_num >= '1' && input_num <= '9') {
		range = TRUE;
	}else {
		range = FALSE;
		printf("範囲内の値を入力してください。\n");
	}
	return range;
}

BOOL CheckNum(char input_num, char *square) {
	BOOL ischeck;
	int tmp = input_num - '0';
	if (*(square + tmp - 1) == input_num) {
		ischeck = TRUE;
	}else {
		printf("既に入力されています。\n");
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(char square[ELEMENT], TURN turn_symbol) {
	JUDGE win_result= UNKNOWN;

	if (turn_symbol == CIRCLE) {
		for (int i=0; i < WIDE_GAP; i++) {//横のライン
			if (square[(i * WIDE_GAP)] == square[(i * WIDE_GAP) + 1] && square[(i * WIDE_GAP) + 1] == square[(i * WIDE_GAP) + 2]) {
				win_result = CIRCLE_WIN;
			}
		}
		for (int j = 0; j < VERETICAL_GAP; j++) {//縦のライン
			if (square[j] == square[j + VERETICAL_GAP] && square[j + VERETICAL_GAP] == square[j + (2 * VERETICAL_GAP)]) {
				win_result = CIRCLE_WIN;
			}
		}
		if (square[0] == square[4] && square[4] == square[8]) {//左上から右下のライン
			win_result = CIRCLE_WIN;
		}

		if (square[2] == square[4] && square[4] == square[6]) {//右上から左下のライン
			win_result = CIRCLE_WIN;
		}
	}
	if (turn_symbol == CROSS) {
		for (int i = 0; i < WIDE_GAP; i++) {
			if (square[(i * WIDE_GAP)] == square[(i * WIDE_GAP) + 1] && square[(i * WIDE_GAP) + 1] == square[(i * WIDE_GAP) + 2]) {
				win_result = CROSS_WIN;
			}
		}
		for (int j = 0; j < VERETICAL_GAP; j++) {
			if (square[j] == square[j + VERETICAL_GAP] && square[j + VERETICAL_GAP] == square[j + (2 * VERETICAL_GAP)]) {
				win_result = CROSS_WIN;
			}
		}
		if (square[0] == square[4] && square[4] == square[8]) {
			win_result = CROSS_WIN;
		}
		if (square[2] == square[4] && square[4] == square[6]) {
			win_result = CROSS_WIN;
		}
	}
	return win_result;
}

JUDGE CheckDraw(int turn_counter) {
	JUDGE draw_result;
	if (turn_counter == ELEMENT-1) {
		draw_result = DROW;
	}else {
		draw_result = UNKNOWN;
	}
	return draw_result;
}

