#include <stdio.h>
#include <conio.h>

typedef struct BOARD_XY {
  int x;
  int y;
} BOARD_XY;

typedef enum {
  FALSE,
  TRUE
} BOOL;

BOARD_XY Player_Input(const char* board) {
  BOARD_XY input_xy = { 0, 0 };
  BOOL input_finish = FALSE;

  printf("�ǂ��Ɉ���L�����܂����H\n");

  while (input_finish == FALSE) {
    BOOL x_check = FALSE;
    while (x_check == FALSE) {
      printf("x(0-2)�F");
      char x_input = _getch();
      printf("%c", x_input);

      int is_flow = _kbhit();
      if ((is_flow != 0) || ((x_input != '0') && (x_input != '1') && (x_input != '2'))) {
        while (is_flow != 0) {
          char flowed = _getch();
          printf("%c", flowed);
          is_flow = _kbhit();
        }
        printf("\n\n���̓G���[�F������x���͂��Ă�������\n");
      }
      else {
        printf("\n");
        input_xy.x = x_input - '0';
        x_check = TRUE;
      }
    }

    BOOL y_check = FALSE;
    while (y_check == FALSE) {
      printf("y(0-2)�F");
      char y_input = _getch();
      printf("%c", y_input);

      int is_flow = _kbhit();
      if ((is_flow != 0) || ((y_input != '0') && (y_input != '1') && (y_input != '2'))) {
        while (is_flow != 0) {
          char flowed = _getch();
          printf("%c", flowed);
          is_flow = _kbhit();
        }
        printf("\n\n���̓G���[�F������x���͂��Ă�������\n");
      }
      else {
        printf("\n");
        input_xy.y = y_input - '0';
        y_check = TRUE;
      }
    }

    if (*(board + (input_xy.y * 3) + input_xy.x) != ' ') {
      printf("\n���̓G���[�F���łɖ��܂��Ă���}�X�ł�\n");
    }
    else {
      input_finish = TRUE;
    }
  }

  return input_xy;
}