// 入力部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <conio.h>
#include "define.h"

// 入力を受け付ける関数
void Input(char symbol, char input_info_array[INPUT_LEN])
{
	char input = '0';

	printf("%cを置くグリッドを選択してください。\n：", symbol);

	scanf_s("%s", input_info_array, (unsigned)INPUT_LEN);

	// 入力バッファをクリア
	while (getchar() != '\n');
}
