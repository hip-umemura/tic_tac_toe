#include<stdio.h>
#include "sanmoku.h"
#include "board.h"

void ShowBoard(char square[ELEMENT]) {
	printf(" -------------------- \n");
	printf("|      |      |      |\n");
	for (int i = 0; i < 9; i++) {
		printf("|   %c  ", square[i]);

		if (i == 8) {
			printf("| \n");
			printf("|      |      |      |\n");
			printf(" --------------------\n");
		}
		else if ((i + 1) % 3 == 0) {
			printf("|\n");
			printf("|      |      |      |\n");
			printf(" -------------------- \n");
			printf("|      |      |      |\n");
		}
	}
}

TURN CheckTurn(int turn_counter) {
	TURN turn_symbol;
	if (turn_counter % 2 == 0) {
		turn_symbol = CIRCLE;
	}else {
		turn_symbol = CROSS;
	}
	return turn_symbol;
}

CONTINUE DisplayWin(JUDGE win_result) {
	if (win_result == CIRCLE_WIN) {
		printf("〇の勝利");
	}
	else if (win_result == CROSS_WIN) {
		printf("×の勝利");
	}
	return EXTEND;
}

void ChangeState(char input_num,char *square,TURN turn_symbol) {
		int tmp = input_num - '0';
		if (turn_symbol == CIRCLE) {
			*(square + tmp - 1) = 'o';
		}else {
			*(square + tmp - 1) = 'x';
		}
}
