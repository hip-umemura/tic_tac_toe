#include "enum.h"
#include <stdio.h>
#include "output.h"
// ”Õ–Ê•\Ž¦
void PrintBoard(void) {
	int i;
	int j;
	for (i = 0; i < NUM; i++) {
		printf("----------\n");
		printf("|");
		for (j = 0; j < NUM; j++) {
			if (g_board[i][j] == ' ') {
				printf("%2d", (i * NUM) + (j + 1));// “ü—ÍˆÊ’u‚ðŽ¦‚·”’l‚ðŒvŽZE•\Ž¦
				printf("|");
			}
			else {
				printf("%2c", g_board[i][j]);
				printf("|");
			}
		}
		printf("\n");
	}
	printf("----------\n");
}
// Ÿ”s‚ÌŒ‹‰Ê‚ð•\Ž¦
void PrintResult(RESULT result) {
	switch (result) {
	case PLAYER1_WIN:
		printf("æU‚ÌŸ‚¿‚Å‚·\n");
		break;
	case PLAYER2_WIN:
		printf("ŒãU‚ÌŸ‚¿‚Å‚·\n");
		break;
	case DRAW:
		printf("ˆø‚«•ª‚¯‚Å‚·\n");
		break;
	}
}
