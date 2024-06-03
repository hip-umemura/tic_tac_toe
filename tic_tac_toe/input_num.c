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
		printf("Z‚Ì”Ô‚Å‚·F");
		input_num = getch();
		printf("%c\n", input_num);
	}else {
		printf("~‚Ì”Ô‚Å‚·F");
		input_num = getch();
		printf("%c\n", input_num);
	}
	return input_num;
}

void CountWin(JUDGE win_result, int* get_circle, int* get_cross) {

	if (win_result == CIRCLE_WIN) {
		printf("Z‚ÌŸ—˜\n");
		*get_circle += 1;
		
	}else {
		printf("~‚ÌŸ—˜\n");
		*get_cross += 1;

	}
}

RETRY PlayEnd(int get_circle,int get_cross) {
	RETRY iscontinue = ERROR;
	while (iscontinue == ERROR) {
		char input_end = '0';
		printf("ƒŠƒgƒ‰ƒC(T)orI—¹(Q):");
		input_end = getch();
		printf("%c\n", input_end);
		if (input_end == 'T') {
			iscontinue = TRY;
		}else if (input_end == 'Q') {
			iscontinue = QUIT;
			printf("Z:%dŸ\n", get_circle);
			printf("~:%dŸ\n", get_cross);
		}else {
			printf("T‚Ü‚½‚ÍQ‚Ì‚Ý‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
		}
	}
	return iscontinue;
}
