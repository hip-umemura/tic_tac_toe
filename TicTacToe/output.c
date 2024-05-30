// 出力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// 盤面を表示する関数
void Output_Grid(char board_info[3][3])
{
	printf("-----------------\n");
	for (int column = 0; column < GRID_HEIGHT; column++) {
		for (int row = 0; row < GRID_WIDTH; row++) {
			printf("  %c  ", board_info[column][row]);
			printf("|");
		}
		printf("\b \n");
		printf("-----------------\n");
	}
}

// 盤面とどちらのターンかを表示する関数
void Output_Turn(TURN turn_info)
{
	if (turn_info == O_TURN) {
		printf("○のターンです。\n");
	}
	else {
		printf("×のターンです。\n");
	}
}

// 盤面と勝敗の結果を表示する関数
void Output_Result(RESULT result_info)
{
	if (result_info == O_WIN) {
		printf("〇の勝利です。\n");
	}
	else if (result_info == X_WIN){
		printf("×の勝利です。\n");
	}
	else if (result_info  == DRAW){
		printf("引き分けです。\n");
	}
}


