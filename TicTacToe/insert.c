// データの挿入部分の定義を記述するソースファイル

#include "define.h"

// 指定されたグリッドに図柄を代入する関数
void Insert(char* board_element_info, TURN turn_info)
{
	switch (turn_info) {
	case O_TURN:
		*board_element_info = O_MARK;
		break;
	case X_TURN:
		*board_element_info = X_MARK;
		break;
	default:
		exit(ERROR);
	}
}