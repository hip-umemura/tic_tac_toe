//データの挿入部分の定義を記述するソースファイル

#include <stdio.h>

void Insert(char* board_element_info, int turn_info)
{
	if (turn_info % 2 == 1) {
		*board_element_info = 'o';
	}
	else {
		*board_element_info = 'x';
	}


}