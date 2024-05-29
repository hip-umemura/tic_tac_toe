#pragma once
//三目並べに使用する関数のプロトタイプ宣言を行うヘッダファイル
#include "define.h"

//盤面を表示する関数
void Output_Grid(char board_info[3][3]);

//現在のターンを表示する関数
void Output_Turn(TURN turn_info);

//ゲームの勝敗を表示する関数
void Output_Result(RESULT result_info);

//入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(char input_info, char board_info[3][3]);

//データの挿入部分の定義を記述する関数
void Insert(char* board_element_info, TURN turn_info);

//入力を受け付ける関数
char Input(TURN turn_info);

//
BOOL Judge_Grid(char board_info);

//
BOOL Judge_Input(char input_possess);

//
RESULT Judge_Result(char joke[GRID_HEIGHT][GRID_WIDTH], TURN turn_info, INDEX grid_element_designation, int turn_count);


