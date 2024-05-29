#pragma once

#include <stdio.h>
#include <conio.h>

#define TITLE "三目並べゲーム"
#define VERSION "ver1.0"
#define TEXT_WIDTH 76
#define STR_SIZE 35
#define PLAYER1 1
#define PLAYER2 -1
#define ENTER '\n'
#define Y 'y'
#define N 'n'
#define PLAYER1_MARK 'o'
#define PLAYER2_MARK 'x'
#define ZHU_SIZE 3

/// <summary>
/// ゲーム終了命令
/// </summary>
typedef enum {
  GAME_END,
  GAME_START,
  RE_INPUT,
} GAME_CONTINUE_INSTRUCTION;

/// <summary>
/// リザルト表示命令
/// </summary>
typedef enum {
  GAME_CONTINUE,
  GAME_DRAW,
  GAME_WIN_1,
  GAME_WIN_2,
} SHOW_RESULT_INSTRUCTION;

/// <summary>
/// BOOL型
/// </summary>
typedef enum {
  FALSE,
  TRUE,
} BOOL;

/// <summary>
/// ヘッダ部の情報を表示する関数
/// </summary>
/// <param name="title">タイトル名</param>
/// <param name="version">バージョン名</param>
void Show_Headder(char title[], char version[]);

/// <summary>
/// 入力を1文字キーボードから受け取る関数
/// </summary>
/// <param name="">void型</param>
/// <returns>int型</returns>
int Get_Input(void);