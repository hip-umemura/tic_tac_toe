// 入力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <conio.h>
#include "define.h"

// 入力を受け付ける関数
void Input(TURN turn, char input_info_array[INPUT_LEN])
{
	if (turn == O_TURN) {
		printf("%c", O_MARK);
	}
	else {
		printf("%c", X_MARK);
	}
	printf("を置くグリッドを選択してください。\n：");

	scanf_s("%s", input_info_array, (unsigned)INPUT_LEN);

	// 入力バッファをクリア
	while (getchar() != '\n');
}