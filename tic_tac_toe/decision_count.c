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
		printf("�͈͓��̒l����͂��Ă��������B");
	}
	return in_range;
}

BOOL CheckNum(int input, int* square) {
	BOOL ischeck;
	if (*(square + input) == input) {
		ischeck = TRUE;
	}
	else {
		printf("���ɓ��͂���Ă��܂��B");
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(int arr[9],TURN mk) {
	JUDGE winnner= UNKNOWN;
	if (mk % 2 == 0) {
		for (int i=0; i < 3; i++) {//���̃��C��
			if (arr[(i * 3)] == arr[(i * 3) + 1] == arr[(i * 3) + 2]) {
				winnner = CIRCLE_WIN;
			}
		}
		for (int j = 0; j < 3; j++) {//�c�̃��C��
			if (arr[j + 3] == arr[j + 3] == arr[j + 6]) {
				winnner = CIRCLE_WIN;
			}
		}
		if (arr[0] == arr[4] == arr[8]) {//���ォ��E���̃��C��
			winnner = CIRCLE_WIN;
		}

		if (arr[2] == arr[4] == arr[6]) {//�E�ォ�獶���̃��C��
			winnner = CIRCLE_WIN;
		}
	}
		if (mk % 2 == 1) {
			for (int i = 0; i < 3; i++) {//���̃��C��
				if (arr[(i * 3)] == arr[(i * 3) + 1] == arr[(i * 3) + 2]) {
					winnner = CROSS_WIN;
				}
			}
			for (int j = 0; j < 3; j++) {//�c�̃��C��
				if (arr[j + 3] == arr[j + 3] == arr[j + 6]) {
					winnner = CROSS_WIN;
				}
			}
			if (arr[0] == arr[4] == arr[8]) {//���ォ��E���̃��C��
				winnner = CROSS_WIN;
			}
			if (arr[2] == arr[4] == arr[6]) {//�E�ォ�獶���̃��C��
				winnner = CROSS_WIN;
			}
		}
		return winnner;
}

CONTINUE CheckDraw(turn) {
	CONTINUE keep;
	if (turn = 9) {
		keep = END;
	}
	else {
		keep = EXTEND;
	}
	return keep;
}

