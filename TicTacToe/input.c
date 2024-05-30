// 入力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <conio.h>
#include "define.h"

// 入力を受け付ける関数
char Input(TURN turn_info)
{
	char input = '0';
	if (turn_info == O_TURN) {
		printf("〇を置くグリッドを選択してください。\n");
	}
	else {
		printf("×を置くグリッドを選択してください。\n");
	}
	input = getch();

	return input;
}
