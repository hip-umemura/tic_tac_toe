#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

BOOL RangeNum(char input_num) {
	BOOL range;
	if (input_num >= '1' && input_num <= '9') {
		range = TRUE;
	}else {
		range = FALSE;
		/*printf("範囲内の値を入力してください。\n"); mainに移行した　*/
	}
	return range;
}

BOOL CheckNum(int input_num, char *square) {
	BOOL ischeck;
	int tmp = input_num - '0';
	if (*(square + tmp-1 ) == input_num) {//input_numをchar型にする
		ischeck = TRUE;
	}else {
		/*printf("既に入力されています。\n");	mainに移行した　*/
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(char square[ELEMENT],TURN turn_symbol) {
	JUDGE win_result= UNKNOWN;

	if (turn_symbol == CIRCLE) {
		for (int i=0; i < 3; i++) {//横のライン
			if (square[(i * 3)] == square[(i * 3) + 1] && square[(i * 3) + 1] == square[(i * 3) + 2]) {
				win_result = CIRCLE_WIN;
			}
		}
		for (int j = 0; j < 3; j++) {//縦のライン
			if (square[j] == square[j + 3] && square[j + 3] == square[j + 6]) {
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
			for (int i = 0; i < 3; i++) {//横のライン
				if (square[(i * 3)] == square[(i * 3) + 1] && square[(i * 3) + 1] == square[(i * 3) + 2]) {
					win_result = CROSS_WIN;
				}
			}
			for (int j = 0; j < 3; j++) {//縦のライン
				if (square[j] == square[j + 3] && square[j + 3] == square[j + 6]) {
					win_result = CROSS_WIN;
				}
			}
			if (square[0] == square[4] && square[4] == square[8]) {//左上から右下のライン
				win_result = CROSS_WIN;
			}
			if (square[2] == square[4] && square[4] == square[6]) {//右上から左下のライン
				win_result = CROSS_WIN;
			}
		}
		return win_result;
}

CONTINUE CheckDraw(int turn_counter) {
	CONTINUE draw_result;
	if (turn_counter == 8) {
		draw_result = END;
	}else {
		draw_result = EXTEND;
	}
	return draw_result;
}

