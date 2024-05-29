#pragma once
#include "general.h"
#include <string.h>
#include <stdio.h>
#include "game.h"

// タイトル画面の表示を行う関数
// 引数 void
// 返り値 列挙型 ゲーム終了命令/ゲーム開始命令
GAME_CONTINUE_INSTRUCTION Show_GameTitle(void);

// ゲームを終了するかプレイヤーに確認をする画面を表示する関数
// 引数 void
// 返り値 int型Get_Input関数の返り値
int Show_ExitGame(void);

// 現在の盤面と三目並べのルールを表示する関数
/* 引数 int型のプレイヤ―を表す変数
   任意の型の盤面を表す変数へのポインタ　*/
// 返り値 void型
void Show_GameInfo(int player_info, int* board);

// ゲームの勝敗判定に基づき、結果を表示する関数
/* リザルト表示命令
   任意の方の盤面を表す変数へのポインタ */
// 返り値 void
void Show_GameResult(SHOW_RESULT_INSTRUCTION result_instruction, int* board);

