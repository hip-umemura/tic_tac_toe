/*
  �O�ڕ���(�݌v�FL�`�[��  �R�[�f�B���O�FC�`�[��)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// �}�N����`
#define TRUE       1
#define FALSE      0
#define WIN        2
#define DRAW       3
#define CONTINUES -1
#define BOARDSIZE  3
#define ARRAYSIZE  2 // �z��T�C�Y 

// ���[������
void DisplayRule() {
  printf("���[������                           \n");
  printf("��������������������������������������������������������������������������\n");
  printf(" ����[1, 2, 3]�{Enter��              \n");
  printf(" �c��[1, 2, 3]�{Enter��              \n");
  printf(" �Z�~��u���ʒu����͂��Ă�������    \n");
  printf("��������������������������������������������������������������������������\n");
  printf("\n\n");
}

// 3*3�̔Ֆʂ̏󋵕\��
void DisplayScreen(char board[BOARDSIZE][BOARDSIZE]) {
  printf("  1   2   3\n");
  printf("-------------\n");
  for (int i = 0; i < BOARDSIZE; i++) {
    for (int j = 0; j < BOARDSIZE; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("| %d\n", i + 1);
    printf("-------------\n");
  }
}

// �c���̓���
char InputVerticalAxis(void) {
  char input[ARRAYSIZE];  // ��������i�[����ϐ�(�v�f��2)
  printf("�I������}�X�̏c������͂��Ă��������F");
  scanf_s("%s", input, (int)sizeof(input));  // ���͂�z��Ɋi�[
  while (getchar() != '\n')
    ;
  return input[0];  // �������0�Ԗڂ𕶎��Ƃ��ĕԂ�
}

// �����̓���
char InputHorizontalAxis(void) {
  char input[ARRAYSIZE];  // ��������i�[����ϐ�(�v�f��2)
  printf("�I������}�X�̉�������͂��Ă��������F");
  scanf_s("%s", input, (int)sizeof(input));
  while (getchar() != '\n')
    ;
  return input[0];
}

// ���͂𐮐��l�ɕϊ�
int ConvertingInputToInt(char input) {       
  int input_to_int;
  if ((input == '1') || (input == '2') || (input == '3')) {  // input��1or2or3
    input_to_int = input - '0'; // �����l�ϊ�
    return input_to_int;
  }
  else {
    printf("\033[41m1,2,3�œ��͂��Ă��������I\033[0m\n");   // �w�i�F��Ԃɂ��ĕ\��
    return FALSE;
  }
}

//�Ֆʂ̔z���OX�������Ă��Ȃ����̔���
int isNotAlreadyPlaced(int vertical, int horizontal, char board[BOARDSIZE][BOARDSIZE]) {
  assert(vertical > 0 && vertical < 4 && horizontal > 0 && horizontal < 4); // �����I��

  if (board[vertical - 1][horizontal - 1] == ' ') { // �w�肵�����W���󂢂Ă���
    return TRUE;
  }
  else {
    printf("\033[41m���łɒu����Ă��܂��I\033[0m\n");      // �w�i�F��Ԃɂ��ĕ\��
    return FALSE;
  }
  
}

// OX��z�u����
void StoringInput(int vertical, int horizontal, char turn, char *board) {
  assert(vertical > 0 && vertical < 4 && horizontal > 0 && horizontal < 4); // �����I��

  board[(vertical - 1) * BOARDSIZE + (horizontal - 1)] = turn;
}

// �����A���������A���s�̔���
int isWinDrawContinues(int vertical, int horizontal, char board[BOARDSIZE][BOARDSIZE]) {
  assert(vertical > 0 && vertical < 4 && horizontal > 0 && horizontal < 4); // �����I��

  int count_free = 0; // �󂢂Ă���}�X�̐�
  // �c�܂��͉���OX�������Ă��邩
  if ((board[vertical - 1][1] != ' ') && (board[vertical - 1][0] == board[vertical - 1][1]) && (board[vertical - 1][1] == board[vertical - 1][2])) {  // ���ɑ����Ă��邩
    return WIN;
  }
  if ((board[1][horizontal - 1] != ' ') && (board[0][horizontal - 1] == board[1][horizontal - 1]) && (board[0][horizontal - 1] == board[2][horizontal - 1])) {  // �c�ɑ����Ă��邩
    return WIN;
  }
  if ((board[1][1] != ' ') && (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) ||
    board[0][2] == board[1][1] && board[1][1] == board[2][0])) {  // �΂߂ɑ����Ă��邩
    return WIN;
  }

  // �󂢂Ă���}�X�̐����v�Z
  for (int i = 0; i < BOARDSIZE; i++) {
    for (int j = 0; j < BOARDSIZE; j++) {
      if (board[i][j] == ' ') {
        count_free++;
      }
    }
  }
  if (count_free == 0) {  // �S�Ẵ}�X�����܂��Ă���
    return DRAW;
  }
  else {
    return CONTINUES;
  }

}

// �v���C���[�̃^�[�������ւ���
char PlayerChange(char turn) {
  char player_turn; // ���݂̃^�[��
  if (turn == 'O') {
    player_turn = 'X';
  }
  else {
    player_turn = 'O';
  }
  return player_turn;
}

// ���������\��
void DrowOutput(void) {
  printf("Draw\n");
}

// �v���C���[�^�[���\��
void PlayerTurnOutput(char turn) {
  printf("Player:%c\n", turn);
}

// �����\��
void WinnerOutput(char turn) {
  PlayerTurnOutput(turn);
  printf("WIN!\n");
}

// ���s�p�֐�
int main(void)
{
  int flag = FALSE;         // �I���t���O
  char turn = 'O';         // �v���C���[�^�[��
  char board[BOARDSIZE][BOARDSIZE] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} }; // �Ֆ�
  char input_vertical;     // �c���̓���
  char input_horizontal;   // �����̓���
  int vertical;            // �c���̐���
  int horizontal;          // �����̐���

  printf("\x1b[30;47m");   // �����F�E�w�i�F�ύX
  // ���[���o��
  DisplayRule();
  printf("\x1b[0m");       // �f�t�H���g�ɖ߂�

  while (flag == FALSE) {  // flag��TRUE�ɂȂ�܂Ń��[�v����
    DisplayScreen(board);  // ��ʏo��
    PlayerTurnOutput(turn);                   // �^�[���o��
    input_horizontal = InputHorizontalAxis(); // ��������
    input_vertical = InputVerticalAxis();     // �c������

    printf("\033[8;0H \033[0J\n");            // �J�[�\���̈ʒu�ړ�&��ʃN���A
    
    // �����ϊ������͂������������f
    horizontal = ConvertingInputToInt(input_horizontal);
    if (horizontal == FALSE) {
      continue;
    }
    vertical = ConvertingInputToInt(input_vertical);
    if (vertical == FALSE) {
      continue;
    }
    // ���ɒu����Ă��邩
    if (isNotAlreadyPlaced(vertical, horizontal, board) == FALSE) {
      continue;
    }

    StoringInput(vertical, horizontal, turn, *board); // ���z�u

    // ���s����
    if (isWinDrawContinues(vertical, horizontal, board) == WIN) {           // ��������
      DisplayScreen(board);
      WinnerOutput(turn);
      flag = TRUE;
    }
    else if (isWinDrawContinues(vertical, horizontal, board) == DRAW) {     // ������������
      DisplayScreen(board);
      DrowOutput();
      flag = TRUE;
    }
    else {                                                                  // �p������
      turn = PlayerChange(turn);  // �^�[�������ւ���
    }
  }
  return 0;
}