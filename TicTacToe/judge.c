// 判定部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

// Judge_Grid関数の宣言
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

// 入力が正しいかを判定する関数
BOOL Judge_Input(char input_possess)
{
	if (input_possess < '1' || input_possess > '9') {
		printf("1～9の半角整数を一つ入力してください。");
		return FALSE;
	}
	else {
		return TRUE;
	}

}

// 三目並べの勝敗の判定をする関数
RESULT Judge_Result(char board_info[GRID_HEIGHT][GRID_WIDTH], TURN turn_info, INDEX grid_element_designation, int turn_count)
{
	int		loop_count;
	int		line_count;
	char 	standard_symbol = board_info[grid_element_designation.y][grid_element_designation.x];

	INDEX current_element_designation[] = {
		{grid_element_designation.x,0},
		{0,grid_element_designation.y},
		{0,0},
		{2,0}
	};

	INDEX diff_element_designation[] = {
		{0,1},
		{1,0},
		{1,1},
		{-1,1}
	};
	
	for (loop_count = 0; loop_count < 4; loop_count++) {
		line_count = 0;
		while (current_element_designation[loop_count].x < 3 && current_element_designation[loop_count].y < 3) {
			if (board_info[current_element_designation[loop_count].y][current_element_designation[loop_count].x] == standard_symbol) {
				line_count++;
			}
			else {
				break;
			}
			current_element_designation[loop_count].x += diff_element_designation[loop_count].x;
			current_element_designation[loop_count].y += diff_element_designation[loop_count].y;
		}
		if (line_count >= 3) {
			if (turn_info == O_TURN) {
				return O_WIN;
			}
			else {
				return X_WIN;
			}
		}
	}

	// グリッド内がすべって埋まっている場合、DRAWを返す。
	// ゲームの終了が判定されていない場合、CONTINUEを返す。
	if (turn_count >= 9) {
		return DRAW;
	}
	else {
		return CONTINUE;
	}

}
