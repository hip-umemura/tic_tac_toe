#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

void InitBoard(char* square) {
	for (int i = 0; i < ELEMENT; i++) {
		*(square + i) = '1' + i;
	}
}

char PushNum(TURN turn_symbol) {
	char input_num = '0';
	if (turn_symbol == CIRCLE) {
		printf("〇の番です：");
		input_num = getch();
		printf("%c\n", input_num);

	}else {
		printf("×の番です：");
		input_num = getch();
		printf("%c\n", input_num);

	}
	return input_num;
}

void CountWin(JUDGE win_result, int* get_circle, int* get_cross) {

	if (win_result == CIRCLE_WIN) {
		printf("Oの勝利\n");
		*get_circle += 1;
		
	}else {
		printf("Xの勝利\n");
		*get_cross += 1;

	}
}

RETRY PlayEnd(int get_circle,int get_cross) {
	RETRY iscontinue = ERROR;

	while (iscontinue == ERROR) {
		char input_end = '0';

		printf("リトライ(T)or終了(Q):");
		input_end = getch();
		printf("%c\n", input_end);

		if (input_end == 'T') {
			iscontinue = TRY;

		}else if (input_end == 'Q') {
			iscontinue = QUIT;
			printf("O:%d勝\n", get_circle);
			printf("X:%d勝\n", get_cross);

		}else {
			printf("TまたはQのみを入力してください。\n");
		}
	}
	return iscontinue;
}
