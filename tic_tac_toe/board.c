#include<stdio.h>
#include<locale.h>
#include "sanmoku.h"
#include "board.h"


void ShowBoard(wchar_t square[9]) {
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
	}else {
		return CROSS;
	}
}

int DisplayWin(JUDGE judge) {
	if (judge ==CIRCLE_WIN) {
		printf("〇の勝利");
	}else if(judge == CROSS_WIN){
		printf("×の勝利");
	}
	return EXTEND;
}

int ChangeState(int input,MARK mark) {
	if (mark == CIRCLE) {
		square[input] = '〇';
	}else {
		square[input] = '×';
	}
	return square[input];
}
