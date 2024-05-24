#include<stdio.h>
#include<locale.h>
#include "board.h"
#include"sanmoku.h"


void ShowBoard(int square[9]) {
	setlocale(LC_ALL, "ja_JP.UTF-8");
	printf(" -------------------- \n|      |      |      |\n");
	for (int i = 0; i < 9; i++) {
		wprintf(L"|  %lc  ", square[i]);
		if (i == 8) {
			printf("| \n|      |      |      |\n --------------------\n");
			break;
		}
		if ((i + 1) % 3 == 0) {
			wprintf(L"|\n|      |      |      |\n -------------------- \n|      |      |      |\n");
		}

	}
}

int CheckTurn(int turn) {
	if (turn % 2 == 0) {
		return CIRCLE;
	}
	else {
		return CROSS;
	}
}

int DisplayWin(CIRCLE_WIN || CROSS_WIN) {
	if (CIRCLE_WIN) {
		printf("〇の勝利");
	}
	else {
		printf("×の勝利")
	}
	return EXTEND;
}

int ChangeState(int input, CIRCLE || CROSS) {
	if (CIRCLE) {
		square[input] = '〇';
	}
	else {
		square[input] = '×';
	}
	return square[input];
}
