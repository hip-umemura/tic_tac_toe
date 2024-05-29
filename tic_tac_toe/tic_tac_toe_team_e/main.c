#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "output.h"
#include "judge.h"

int main(void) {
  int row;
  int column;
  int game_end = FALSE;
  TURN player_turn = TURN_PLAYER1;
  RESULT result = RESULT_NONE;
  // �Ֆʂ̏�����
  BoardInit();
  // �Ֆʕ\��
  PrintBoard();
  do {
    // ���͂����߂�
    PlayerInput(&row, &column, player_turn);
    // �L�����i�[
    BoardUpdate(row, column, player_turn);
    // �Ֆʕ\��
    PrintBoard();
    // ���s����
    result = ResultJudge(player_turn);
    // ��Ԃ�i�s
    if (result == RESULT_NONE) {
      player_turn = NextTurn(player_turn);
    } else {
      game_end = TRUE;
    }
  } while (game_end == FALSE);
  // ���s�̌��ʂ�\��
  PrintResult(result);

  return 0;
}