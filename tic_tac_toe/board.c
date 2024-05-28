#include<stdio.h>
#include<locale.h>
#include "sanmoku.h"
#include "board.h"


void ShowBoard(int square[ELEMENT]) {
	setlocale(LC_ALL, "ja_JP.UTF-8");
	printf(" -------------------- \n|      |      |      |\n");
	for (int i = 0; i < 9; i++) {
		printf("|  %lc  ", square[i]);
		if (i == 8) {
			printf("| \n|      |      |      |\n --------------------\n");
			break;
		}
		else if ((i + 1) % 3 == 0) {
			printf("|\n|      |      |      |\n -------------------- \n|      |      |      |\n");
		}

	}
}

TURN CheckTurn(int turn) {
	TURN mark;
	if (turn % 2 == 0) {
		mark = CIRCLE;
	}else {
		mark = CROSS;
	}
	return mark;
}

CONTINUE DisplayWin(JUDGE judge) {
	if (judge == CIRCLE_WIN) {
		printf("〇の勝利");
	}
	else if (judge == CROSS_WIN) {
		printf("×の勝利");
	}
	return EXTEND;
}

int ChangeState(int input,int *square,TURN mark) {
	if (mark == CIRCLE) {
		*(square+input) = '〇';
	}else {
		*(square + input) = '×';
	}
	return square[input];
}
