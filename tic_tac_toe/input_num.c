#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

void InitBoard(char* board) {
	for (int i = 0; i < ELEMENT; i++) {
		*(board + i) = '1' + i;
	}
}

char PushNum() {
	char input = '0';
		input = getch();
		printf("%c\n", input);
	return input;
}

void CountWin(JUDGE result, int* count_circle_win, int* count_cross_win) {

	if (result == CIRCLE_WIN) {
		*count_circle_win += 1;
		printf("〇の勝利\n");
		
	}else {
			*count_cross_win += 1;
			printf("×の勝利\n");

	}
}

RETRY PlayEnd(int count_circle_win, int count_cross_win) {
	char input_end = '0';
	while ((input_end != 'T') && (input_end != 'Q')){
		input_end = '0';
		printf("リトライ(T)or終了(Q):");
		input_end = getch();
		printf("%c\n", input_end);
		if (input_end == 'T') {
			return TRY;
		}else if (input_end == 'Q') {
			printf("o:%d勝\n", count_circle_win);
			printf("x:%d勝\n", count_cross_win);
			return QUIT;
		}else {
			printf("TまたはQのみを入力してください。\n");
		}
	}
}

void ChangeState(char player_input, char* board, JUDGE now_turn) {
	int tmp = player_input - '0';
	if (now_turn == CIRCLE) {
		*(board + tmp - 1) = 'o';
	}
	else {
		*(board + tmp - 1) = 'x';
	}
}