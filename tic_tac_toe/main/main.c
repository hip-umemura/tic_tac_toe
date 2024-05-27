#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "output.h"
#include "judge.h"

int main(void) {
  int row;
  int column;
  TURN player_turn = TURN_PLAYER1;
  RESULT result = RESULT_NONE;
  // 盤面の初期化
  BoardInit();
  // 盤面表示
  PrintBoard();
  do {
    // 入力を求める
    PlayerInput(&row, &column, player_turn);
    // 記号を格納
    BoardUpdate(row, column, player_turn);
    // 盤面表示
    PrintBoard();
    // 勝敗判定
    result = ResultJudge(player_turn);
    // 手番を進行
    player_turn = NextTurn(player_turn);
  } while (result == RESULT_NONE);
  // 勝敗の結果を表示
  PrintResult(result);

  return 0;
}