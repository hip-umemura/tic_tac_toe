//探索部分の関数の定義を記述するソースファイル

#include "define.h"

// 入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(char input_info, char board_info[3][3]) {
	// カウンタ変数の宣言
	int x = 0;
	int y = 0;

	// 線形探索
	for (y = GRID_HEIGHT - 1; y >= 0; y--) {
		BOOL match = FALSE;
		for (x = 0; x < GRID_WIDTH; x++) {
			if (input_info == ('1' + (GRID_HEIGHT - y - 1) * GRID_WIDTH + x)) {
				match = TRUE;
				break;
			}
		}
		if (match) {
			break;
		}
	}

	INDEX index = { x, y };
	return index;
}