// 探索部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

// 入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(int input_info, char board_info_array[3][3])
{
	// カウンタ変数の宣言
	int x = 0;
	int y = 0;
	int count = 0;

	// ループを抜ける条件
	BOOL match = FALSE;

	for (y = GRID_HEIGHT - 1; y >= 0; y--) {
		for (x = 0; x < GRID_WIDTH; x++) {
			count++;
			if (input_info == count) {
				INDEX index = { x, y };
				return index;
			}
		}
	}
	printf("エラー：入力をやり直してください。");
}