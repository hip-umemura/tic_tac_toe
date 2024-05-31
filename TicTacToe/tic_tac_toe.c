// main�֐����L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "tic_tac_toe.h"
#include "define.h"

// main�֐��̍쐬
int main(void)
{
  // �ϐ��̐錾
  char    input_info = '0';
  RESULT  win_info = CONTINUE;
  int     turn_count = 0;
  TURN    turn_info = O_TURN;
  // �z��̐錾
  char board_info[GRID_HEIGHT][GRID_WIDTH];
  // �\���̂̐錾
  INDEX index = { 0,0 };

  // �z��̏�����
  for (int i = GRID_HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      board_info[i][j] = '7' - i * GRID_WIDTH + j;
    }
  }

  // A���[�v
  while (win_info == CONTINUE) {

    turn_count++;

    if (turn_count % 2 == 0) {
      turn_info = X_TURN;
    }
    else {
      turn_info = O_TURN;
    }

    Output_Turn(turn_info);
    Output_Grid(board_info);

    // B���[�v
    BOOL is_open = FALSE;
    while (is_open == FALSE) {
      input_info = Input(turn_info);
      if (Judge_Input(input_info) == TRUE) {
        index = Search(input_info, board_info);
        is_open = Judge_Grid(board_info[index.y][index.x]);
      }
    }

    Insert(&board_info[index.y][index.x], turn_info);

    win_info = Judge_Result(board_info, turn_info, index, turn_count);
  }

  Output_Grid(board_info);
  Output_Result(win_info);

  return 0;
}