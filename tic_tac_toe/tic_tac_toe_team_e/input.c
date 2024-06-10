#include <stdio.h>
#include "enum.h"
#include "input.h"
#include <assert.h>
// 盤面の初期化
void BoardInit(void) {
  int i;
  int j;
  for (i = 0; i < NUM; i++) {
    for (j = 0; j < NUM; j++) {
      g_board[i][j] = ' ';
    }
  }
}
// 入力を求める
void PlayerInput(int* row, int* column, TURN player_turn) {
  int player_input;
  int input_result;
  do {
    do {
      input_result = TRUE;
      if (player_turn == TURN_PLAYER1) {
        printf("先行の番です。\n");
        printf("番号を入力してください。\n");
        printf("番号：");
      }
      else {
        printf("後攻の番です。\n");
        printf("番号を入力してください。\n");
        printf("番号：");
      }
      // キーボード入力
      player_input = getchar();
      // 入力例外処理
      if ((char)player_input == '\n') {
        printf("入力が正しくないです。\n");
        input_result = FALSE;
      }else if (getchar() != '\n') {
        printf("入力が正しくないです。\n");
        while (getchar() != '\n');
        input_result = FALSE;
      }
    } while (input_result == FALSE);

    player_input = player_input - '0';

    if ((player_input < 1) && (player_input > (NUM * NUM))) {
      printf("入力が正しくないです。\n");
      input_result = FALSE;
    }
    // 入力値から行と列を計算で算出
    *row = (player_input - 1) / NUM;
    *column = (player_input - 1) % NUM;
    // 配列の中身を確認
    if (g_board[*row][*column] != ' ') {
      printf("入力が正しくないです。\n");
      input_result = FALSE;
    }
    else {
      input_result = TRUE;
    }
  } while (input_result == FALSE);
}
// 記号を格納
void BoardUpdate(int row, int column, TURN player_turn) {
  assert(row >= 0 && row <= 2);
  assert(column >= 0 && column <= 2);
  
  if (player_turn == TURN_PLAYER1) {
    g_board[row][column] = 'o';
  }
  else {
    g_board[row][column] = 'x';
  }
}
