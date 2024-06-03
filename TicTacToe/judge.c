// 判定部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

// Judge_Grid関数の宣言
BOOL Judge_Grid(char board_info_array, char symbol_array[PLAYER_NUM])
{
	for (int i = 0; i < PLAYER_NUM; i++) {
		if (board_info_array == symbol_array[i]) {
			printf("グリッドが空の番号を選択してください！\n");
			return FALSE;
		}
	}
	return TRUE;
}

// 入力が正しいかを判定する関数
BOOL Judge_Input(char input_possess[INPUT_LEN])
{
	if (input_possess[1] != '\0' && input_possess[1] != '\n' || input_possess[0] < '1' || input_possess[0] > '9') {
		printf("1～9の半角整数を選択してください！\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

// 三目並べの勝敗の判定をする関数
RESULT Judge_Result(char board_info_array[GRID_HEIGHT][GRID_WIDTH], char symbol, INDEX grid_element_designation, int turn_count)
{
	int count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[(grid_element_designation.y + 1 + i) % GRID_HEIGHT][grid_element_designation.x] == symbol) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[grid_element_designation.y][(grid_element_designation.x + 1 + i) % GRID_WIDTH] == symbol) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[i][i] == board_info_array[i + 1][i + 1]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[i][GRID_WIDTH - 1 - i] == board_info_array[i + 1][GRID_WIDTH -2 - i]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
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