//データの挿入部分の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

//
void Insert(char* board_element_info, TURN turn_info)
{
	if (turn_info == O_TURN) {
		*board_element_info = 'o';
	}
	else {
		*board_element_info = 'x';
	}
}