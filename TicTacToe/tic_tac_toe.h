#pragma once
//三目並べに使用する関数のプロトタイプ宣言を行うヘッダファイル
#include "define.h"

//盤面を表示する関数
void Output_Grid(char board_info[3][3]);

//現在のターンを表示する関数
void Output_Info(int tern_info);

//ゲームの勝敗を表示する関数
void Output_Result(int result_info);

//入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(char input_info, char board_info[3][3]);
