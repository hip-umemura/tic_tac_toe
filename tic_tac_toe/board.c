#include<stdio.h>
#include "sanmoku.h"
#include "board.h"

void ShowBoard(char board[ELEMENT]) {
	printf(" -------------------- \n");
	printf("|      |      |      |\n");
	for (int i = 0; i < ELEMENT; i++) {
		printf("|   %c  ", board[i]);

		if (i == ELEMENT - 1) {
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

JUDGE CheckTurn(int turn) {

	if (turn % 2 == 0) {
		return CIRCLE;
	}else {
		return CROSS;
	}
}



void DisplayNum(JUDGE now_turn) {
	if (now_turn == CIRCLE) {
		printf("o‚Ì”Ô‚Å‚·F");
	}else {
		printf("x‚Ì”Ô‚Å‚·F");
	}
}
