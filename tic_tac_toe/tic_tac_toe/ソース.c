#include<stdio.h>

void InitBoard(int square[]) {
	for (int i = 0; i < 9; i++) {
		square[i] = i + 1;
	}
}

int main(void) {
	int square[9];
	printf("%d", square[2]);
}