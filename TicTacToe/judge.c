// 判定部分の関数の定義を記述するソースファイル

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// Judge_Grid関数の宣言
BOOL Judge_Grid(char board_info_array)
{
	for (int i = 0; i < PLAYER_NUM; i++) {
		if (board_info_array == O_MARK || board_info_array == X_MARK) {
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
RESULT Judge_Result(char board_info_array[GRID_HEIGHT][GRID_WIDTH], INDEX grid_element_designation, int turn_count)
{
	// INDEXのメンバの値が、要素指定できない値の場合、強制終了させる
	if (grid_element_designation.x < 0 || grid_element_designation.x >= GRID_WIDTH ||
			grid_element_designation.y < 0 || grid_element_designation.y >= GRID_HEIGHT) {
		abort();
	}

	// 縦を見て、同じ図柄が3つ並んでいるか確認する。
	int count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[(grid_element_designation.y + i) % GRID_HEIGHT][grid_element_designation.x] ==
				board_info_array[(grid_element_designation.y + 1 + i) % GRID_HEIGHT][grid_element_designation.x]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// 横を見て、同じ図柄が3つ並んでいるか確認する。
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[grid_element_designation.y][(grid_element_designation.x + i) % GRID_WIDTH] ==
				board_info_array[grid_element_designation.y][(grid_element_designation.x + 1 + i) % GRID_WIDTH]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// 斜めを見て、同じ図柄が3つ並んでいるか確認する。
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
		if (board_info_array[i][GRID_WIDTH - 1 - i] == board_info_array[i + 1][GRID_WIDTH - 2 - i]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// グリッド内がすべって埋まっている場合、DRAWを返す。
	// ゲームの終了が判定されていない場合、CONTINUEを返す。
	if (turn_count >= GRID_WIDTH * GRID_HEIGHT) {
		return DRAW;
	}
	else {
		return CONTINUE;
	}
}