//出力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

//Output_Grid関数の宣言
//char board_info	ボードの情報を持つ変数
void Output_Grid(char board_info[3][3])
{
	printf("-----------------\n");
	for (int column = 0; column < GRID_HEIGHT; column++) {
		for (int row = 0; row <= GRID_WIDTH - 1; row++) {
			printf("  %c  ", board_info[column][row]);
			printf("|");
		}

		//バックスペースを入力し、半角スペースで上書き
		printf("\b \n");
		printf("-----------------\n");
	}
}

//Output_Info関数の宣言
//int tern_info	ターンの情報を持つ変数
void Output_Info(int tern_info)
{
	if (tern_info % 2 == 0) {
		printf("○のターンです。\n");
	}
	else {
		printf("×のターンです。\n");
	}
}

//Output_Result関数の実装
void Output_Result(int result_info)
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


