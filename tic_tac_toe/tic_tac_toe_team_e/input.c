#include <stdio.h>
#include "enum.h"
#include "input.h"
#include <assert.h>
// �Ֆʂ̏�����
void BoardInit(void) {
  int i;
  int j;
  for (i = 0; i < NUM; i++) {
    for (j = 0; j < NUM; j++) {
      g_board[i][j] = ' ';
    }
  }
}
// ���͂����߂�
void PlayerInput(int* row, int* column, TURN player_turn) {
  int player_input;
  int input_result;
  do {
    do {
      input_result = TRUE;
      if (player_turn == TURN_PLAYER1) {
        printf("��s�̔Ԃł��B\n");
        printf("�ԍ�����͂��Ă��������B\n");
        printf("�ԍ��F");
      }
      else {
        printf("��U�̔Ԃł��B\n");
        printf("�ԍ�����͂��Ă��������B\n");
        printf("�ԍ��F");
      }
      // �L�[�{�[�h����
      player_input = getchar();
      // ���͗�O����
      if ((char)player_input == '\n') {
        printf("���͂��������Ȃ��ł��B\n");
        input_result = FALSE;
      }else if (getchar() != '\n') {
        printf("���͂��������Ȃ��ł��B\n");
        while (getchar() != '\n');
        input_result = FALSE;
      }
    } while (input_result == FALSE);

    player_input = player_input - '0';

    if ((player_input < 1) && (player_input > (NUM * NUM))) {
      printf("���͂��������Ȃ��ł��B\n");
      input_result = FALSE;
    }
    // ���͒l����s�Ɨ���v�Z�ŎZ�o
    *row = (player_input - 1) / NUM;
    *column = (player_input - 1) % NUM;
    // �z��̒��g���m�F
    if (g_board[*row][*column] != ' ') {
      printf("���͂��������Ȃ��ł��B\n");
      input_result = FALSE;
    }
    else {
      input_result = TRUE;
    }
  } while (input_result == FALSE);
}
// �L�����i�[
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
