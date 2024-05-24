#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

BOOL RangeNum(int input) {
	BOOL in_range;
	if (input >= 1 && input <= 9) {
		in_range = TRUE;
	}
	else {
		in_range = FALSE;
	}
	return in_range;
}

BOOL CheckNum(int input, int* p) {
	BOOL ischeck;
	if (*(p + input) == input) {
		ischeck = TRUE;
	}
	else {
		printf("範囲内の値を入力してください。");
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(int p[9],int turn) {
	int win = 0;
	if (turn % 2 == 0) {
		for (int i=0; i < 3; i++) {//横のライン
			if (p[(i * 3)] == p[(i * 3) + 1] == p[(i * 3) + 2]) {
				win = CIRCLE_WIN;
			}
		}
		for (int j = 0; j < 3; j++) {//縦のライン
			if (p[j] == p[j + 3] == p[j + 6]) {
				win = CIRCLE_WIN;
			}
		}
		
	}

}