#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

void InitBoard(int a[]) {
	for (int i = 0; i < 9; i++) {
		*(a + i) = i + 1;
	}
	return *a;
}

int PushNum(int turn){
	int num;
	if (turn % 2 == 0) {
		printf("Z‚Ì”Ô‚Å‚·F");
		scanf_s("%d", &num);
	}
	else {
		printf("~‚Ì”Ô‚Å‚·F");
		scanf_s("%d", &num);
	}
	return num;
}

int CountWin(int result,int get_circle,int get_cross) {

	if (result == CIRCLE_WIN) {
		get_circle++;
	 }
	else if (result == CROSS_WIN) {
		get_cross++;
	}
}

PlayEnd() {

}





