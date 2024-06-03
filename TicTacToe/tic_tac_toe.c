// main�֐����L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"
#include "define.h"

// main�֐��̍쐬
int main(void)
{
  // �ϐ��̐錾
  int     input_info  = 0;
  RESULT  win_info    = CONTINUE;
  int     turn_count  = 0;
  int     turn_info   = 0;
  char    input_array[INPUT_LEN] = "\0";
  // �z��̐錾
  char board_info_array[GRID_HEIGHT][GRID_WIDTH];
  char symbol_array[PLAYER_NUM] = {'x','o'};
  // �\���̂̐錾
  INDEX index = { 0,0 };

  // �z��̏�����
  for (int i = GRID_HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      board_info_array[i][j] = '7' - i * GRID_WIDTH + j;
    }
  }

  // ���s���o��܂Ń��[�v(A���[�v)
  while (win_info == CONTINUE) {
    turn_count++;
    turn_info = TURN_PLAYER(turn_count);

    Output_Turn(symbol_array[turn_info]);
    Output_Grid(board_info_array);

    // ���͂Ɋ֐����[�v(B���[�v)
    BOOL is_open = FALSE;
    while (is_open == FALSE) {
      Input(symbol_array[turn_info], input_array);
      if (Judge_Input(input_array) == TRUE) {
        input_info = atoi(input_array);
        index = Search(input_info, board_info_array);
        if (index.x != ERROR) {
          is_open = Judge_Grid(board_info_array[index.y][index.x], symbol_array);
        }
      }
    }

    Insert(&board_info_array[index.y][index.x], symbol_array[turn_info]);

    win_info = Judge_Result(board_info_array, symbol_array[turn_info], index, turn_count);
  }

  Output_Grid(board_info_array);
  Output_Result(symbol_array[turn_info], win_info);

  return 0;
}