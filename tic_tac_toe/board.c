#include<stdio.h>
#include<locale.h>
#include "sanmoku.h"
#include "board.h"


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

TURN CheckTurn(int turn) {
	TURN mark;
	if (turn % 2 == 0) {
		mark = CIRCLE;
	}else {
		mark = CROSS;
	}
	return mark;
}

int DisplayWin(JUDGE win_result) {
	if (win_result ==CIRCLE_WIN) {
		printf("〇の勝利");
	}else if(win_result == CROSS_WIN){
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
