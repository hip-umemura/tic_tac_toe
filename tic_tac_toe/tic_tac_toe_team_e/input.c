#include <stdio.h>
#include "enum.h"
#include "input.h"
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
  int input_result = TRUE;
  do {
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

    scanf_s("%d", &player_input);
    // ���͗�O����(���͒l�������ȊO�̏ꍇ)
    if (getchar() != '\n') {
      printf("���͂��������Ȃ��ł��B\n\n");
      while (getchar() != '\n');
      input_result = FALSE;
      continue;
    }
    // ���͒l����s�Ɨ���v�Z�ŎZ�o
    *row = (player_input - 1) / NUM;
    *column = (player_input - 1) % NUM;
    // ���͒l�̐��딻��
    if ((player_input < 1) && (player_input > (NUM * NUM))) {
      printf("���͂��������Ȃ��ł��B\n\n");
      input_result = FALSE;
    }
    else if (g_board[*row][*column] != ' ') {
      printf("���͂��������Ȃ��ł��B\n\n");
      input_result = FALSE;
    }
    else {
      input_result = TRUE;
    }
  } while (input_result == FALSE);
}
// �L�����i�[
void BoardUpdate(int row, int column, TURN player_turn) {
  if (player_turn == TURN_PLAYER1) {
    g_board[row][column] = 'o';
  }
  else {
    g_board[row][column] = 'x';
  }
}
