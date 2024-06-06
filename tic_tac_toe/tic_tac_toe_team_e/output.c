#include "enum.h"
#include <stdio.h>
#include "output.h"
#include "assert.h"
// 盤面表示
void PrintBoard(void) {
	int i;
	int j;
	for (i = 0; i < NUM; i++) {
		printf("----------\n");
		printf("|");
		for (j = 0; j < NUM; j++) {
			if (g_board[i][j] == ' ') {
				printf("%2d", (i * NUM) + (j + 1));// 入力位置を示す数値を計算・表示
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
// 勝敗の結果を表示
void PrintResult(RESULT result) {
	switch (result) {
	case PLAYER1_WIN:
		printf("先攻の勝ちです。");
		break;
	case PLAYER2_WIN:
		printf("後攻の勝ちです。");
		break;
	case DRAW:
		printf("引き分けです。");
		break;
	case RESULT_NONE:
	    assert(FALSE);
		break;
	}
}
