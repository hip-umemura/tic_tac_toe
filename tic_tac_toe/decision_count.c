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
		printf("�͈͓��̒l����͂��Ă��������B");
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(int p[9],int turn) {
	int win = 0;
	if (turn % 2 == 0) {
		for (int i=0; i < 3; i++) {//���̃��C��
			if (p[(i * 3)] == p[(i * 3) + 1] == p[(i * 3) + 2]) {
				win = CIRCLE_WIN;
			}
		}
		for (int j = 0; j < 3; j++) {//�c�̃��C��
			if (p[j] == p[j + 3] == p[j + 6]) {
				win = CIRCLE_WIN;
			}
		}
		
	}

}