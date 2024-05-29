#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "display.h"

/// <summary>
/// 三目並べのマス表示、ルール表示、ゲーム進行を行う関数
/// </summary>
/// <param name="">void型</param>
/// <returns>SHOW_RESULT_INSTRUCTION</returns>
SHOW_RESULT_INSTRUCTION Play_Tic_Tac_Toe(void);

/// <summary>
/// マス目の指定が正しいかどうかを判定する関数
/// </summary>
/// <param name="mono_input">int型:マス目</param>
/// <param name="board">int*型:盤面</param>
/// <returns>BOOL</returns>
BOOL isCorrectInput(int mono_input,int* board);

/// <summary>
/// マス目の入力が正しくないことを提示してプレイヤーに再入力を求める関数
/// </summary>
/// <param name="">void型</param>
void Suggest_Reinput(void);

/// <summary>
/// ゲームを開始するか終了するかを判定する関数
/// </summary>
/// <param name="mono_input">int型:文字コード</param>
/// <returns>GAME_CONTINUE_INSTRUCTION</returns>
GAME_CONTINUE_INSTRUCTION isGameStart(int mono_input);

/// <summary>
/// ゲーム終了条件を満たして終了するか、ゲームを続行するか判定する関数
/// </summary>
/// <param name="player">int型:手番</param>
/// <param name="board">int*型:盤面</param>
/// <returns>SHOW_RESULT_INSTRUCTION</returns>
SHOW_RESULT_INSTRUCTION isGameEnded(int player,int *board);