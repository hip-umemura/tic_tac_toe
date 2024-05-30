#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

BOOL RangeNum(char input_num) {
	BOOL range;
	if (input_num >= '1' && input_num <= '9') {
		range = TRUE;
	}
	else {
		range = FALSE;
		printf("�͈͓��̒l����͂��Ă��������B\n");
	}
	return range;
}

BOOL CheckNum(char input_num, char *square) {
	BOOL ischeck;
	int tmp = input_num - '0';
	if (*(square + tmp-1 ) == input_num) {//input_num��char�^�ɂ���
		ischeck = TRUE;
	}
	else {
		printf("���ɓ��͂���Ă��܂��B\n");
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(char square[9], TURN turn_symbol) {
	JUDGE win_result= UNKNOWN;

	if (turn_symbol == CIRCLE) {
		for (int i=0; i < 3; i++) {//���̃��C��
			if (square[(i * 3)] == square[(i * 3) + 1] && square[(i * 3) + 1] == square[(i * 3) + 2]) {
				win_result = CIRCLE_WIN;
			}
		}
		for (int j = 0; j < 3; j++) {//�c�̃��C��
			if (square[j] == square[j + 3] && square[j + 3] == square[j + 6]) {
				win_result = CIRCLE_WIN;
			}
		}
		if (square[0] == square[4] && square[4] == square[8]) {//���ォ��E���̃��C��
			win_result = CIRCLE_WIN;
		}

		if (square[2] == square[4] && square[4] == square[6]) {//�E�ォ�獶���̃��C��
			win_result = CIRCLE_WIN;
		}
	}
		if (turn_symbol == CROSS) {
			for (int i = 0; i < 3; i++) {//���̃��C��
				if (square[(i * 3)] == square[(i * 3) + 1] && square[(i * 3) + 1] == square[(i * 3) + 2]) {
					win_result = CROSS_WIN;
				}
			}
			for (int j = 0; j < 3; j++) {//�c�̃��C��
				if (square[j] == square[j + 3] && square[j + 3] == square[j + 6]) {
					win_result = CROSS_WIN;
				}
			}
			if (square[0] == square[4] && square[4] == square[8]) {//���ォ��E���̃��C��
				win_result = CROSS_WIN;
			}
			if (square[2] == square[4] && square[4] == square[6]) {//�E�ォ�獶���̃��C��
				win_result = CROSS_WIN;
			}
		}
		return win_result;
}

CONTINUE CheckDraw(int turn_counter) {
	CONTINUE draw_result;
	if (turn_counter == 8) {
		draw_result = END;
	}
	else {
		draw_result = EXTEND;
	}
	return draw_result;
}

