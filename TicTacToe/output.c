//出力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <stdlib.h>

//Output_Info関数の宣言
//int tern_info	ターンの情報を持つ変数
//char board_info	ボードの情報を持つ変数
void Output_Info(int tern_info, char board_info [3][3])
{
	if (tern_info % 2 == 0) {
		printf("○のターンです。\n");
	}
	else {
		printf("×のターンです。\n");
	}
	printf("-----------------\n");
	for (int column = 2; column >= 0; column--) {
		for (int row = 0; row <= 2; row++) {
			printf("  %c  ", board_info[column][row]);
			printf("|");
		}

		//バックスペースを入力し、半角スペースで上書き
		printf("\b \n");
		printf("-----------------\n");
	}

}