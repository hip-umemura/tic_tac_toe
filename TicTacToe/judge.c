//判定部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

//関数の宣言
BOOL Judge_Grid(char board_info)
{
	if (board_info == 'o' || board_info == 'x') {
		printf("空いているグリッドを選択してください。\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

//
BOOL Judge_Input(char input_possess)
{
	if (input_possess ) {

	}

}
