// 出力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// 盤面を表示する関数
void Output_Grid(char board_info_array[3][3])
{
	printf("-----------------\n");
	for (int column = 0; column < GRID_HEIGHT; column++) {
		for (int row = 0; row < GRID_WIDTH; row++) {
			printf("  %c  ", board_info_array[column][row]);
			printf("|");
		}
		printf("\b \b\n");
		printf("-----------------\n");
	}
}

// 盤面とどちらのターンかを表示する関数
void Output_Turn(TURN current_turn)
{
	if (current_turn == O_TURN) {
		printf("%cのターンです。\n", O_MARK);
	}
	else {
		printf("%cのターンです。\n", X_MARK);
	}
}

// 盤面と勝敗の結果を表示する関数
void Output_Result(TURN current_turn, RESULT result_info)
{
	switch (result_info) {
	case WIN:
		if (current_turn == O_TURN) {
			printf("%c", O_MARK);
		}
		else {
			printf("%c", X_MARK);
		}
		printf("の勝利です。\n");
		break;
	case DRAW:
		printf("引き分けです。\n");
		break;
	default:
		printf("エラー：結果を判定できませんでした。\n");
		break;
	}
}