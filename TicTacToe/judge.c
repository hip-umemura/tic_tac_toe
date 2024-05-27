//判定部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

//Judge_Grid関数の宣言
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
	if (input_possess < '1' || input_possess > '9') {
		printf("1～9の半角整数を一つ入力してください。");
		return FALSE;
	}
	else {
		return TRUE;
	}

}

//
RESULT Judge_Result(char joke[GRID_HEIGHT][GRID_WIDTH], int tern_info, INDEX grid_element_designation)
{
	INDEX start_element_designation;
	start_element_designation.x = grid_element_designation.x;
	start_element_designation.y = 0;

	int loop_count;
	int line_count;
	char standard_symbol;

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
	
	standard_symbol = joke[grid_element_designation.y][grid_element_designation.x];

	for (loop_count = 0; loop_count < 4; loop_count++) {
		line_count = 0;
		while (current_element_designation[loop_count].x < 3 || current_element_designation[loop_count].y < 3) {
			if (joke[current_element_designation[loop_count].y][current_element_designation[loop_count].x] == standard_symbol) {
				line_count++;
			}
			else {
				break;
			}
			current_element_designation[loop_count].x += diff_element_designation[loop_count].x;
			current_element_designation[loop_count].y += diff_element_designation[loop_count].y;
		}
		if (line_count >= 3) {

		}


	}








	//INDEX start_element_designation;
	//start_element_designation.x = grid_element_designation.x;
	//start_element_designation.y = 0;

	

}
