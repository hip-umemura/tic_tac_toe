#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

void InitBoard(int *board_num) {
	for (int i = 0; i < 9; i++) {
		*(board_num + i) = i + 1;
	}
	return *board_num;
}

int PushNum(int turn){
	int num;
	if (turn % 2 == 0) {
		printf("�Z�̔Ԃł��F");
		scanf_s("%d", &num);
	}
	else {
		printf("�~�̔Ԃł��F");
		scanf_s("%d", &num);
	}
	return num;
}

int CountWin(JUDGE result,int get_circle,int get_cross) {

	if (result == CIRCLE_WIN) {
		return get_circle++;
	 }
	else if (result == CROSS_WIN) {
	return	get_cross++;
	}
}

RETRY PlayEnd() {

	RETRY iscontinue=ERROR;
	while (iscontinue=ERROR) {
		char  input_end[1];
		printf("���g���C(T)or�I��(Q):");
		scanf_s("%c", &input_end[0] );
		if (input_end == 'T') {
			iscontinue = TRY;
			break;
		}
		else if (input_end == 'Q') {
			iscontinue = QUIT;
			break;
		}
		else  {
			printf("T�܂���Q�݂̂���͂��Ă��������B");
		}
		return iscontinue;
	}



}





