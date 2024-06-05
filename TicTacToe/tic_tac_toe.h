#pragma once

// 三目並べに使用する関数のプロトタイプ宣言を行うヘッダファイル
#include "define.h"

// 盤面を表示する関数
void Output_Grid(char board_info_array[3][3]);

// 現在のターンを表示する関数
void Output_Turn(TURN turn_info);

// ゲームの勝敗を表示する関数
void Output_Result(TURN current_turn, RESULT result_info);

// 入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(int input_info, char board_info_array[3][3]);

// データの挿入部分の定義を記述する関数
void Insert(char* board_element_info, TURN turn_info);

// 入力を受け付ける関数
void Input(TURN turn, char input_info_array[INPUT_LEN]);

// グリッドが開いているかを判定する関数
BOOL Judge_Grid(char board_info_array);

// 入力が正しいかを判定する関数
BOOL Judge_Input(char input_possess[INPUT_LEN]);

// 三目並べの勝敗の判定をする関数
RESULT Judge_Result(char joke[GRID_HEIGHT][GRID_WIDTH], INDEX grid_element_designation, int turn_count);