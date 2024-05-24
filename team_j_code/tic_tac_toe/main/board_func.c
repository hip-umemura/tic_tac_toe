#include <stdio.h>
#include <ctype.h>
#include "board_func.h"

//#define DEBUG
#define LINE_UP_NUM 3
#define ORIGIN_POINT(list, row, column) list[row][column]
#define ONE_RIGHT(list, row, column) list[row][column + 1]
#define DOUBLE_RIGHT(list, row, column) list[row][column + 2]
#define ONE_LOWER(list, row, column) list[row + 1][column]
#define DOUBLE_LOWER(list, row, column) list[row + 2][column]
#define ONE_LOWER_RIGHT(list, row, column) list[row + 1][column + 1]
#define DOUBLE_LOWER_RIGHT(list, row, column) list[row + 2][column + 2]
#define ONE_LOWER_LEFT(list, row, column) list[row + 1][column - 1]
#define DOUBLE_LOWER_LEFT(list, row, column) list[row + 2][column - 2]

int ScanInput(void) {
  int recive_char;
  int input_num = 0;
  int input_str_length = 0;
  int input_roop_flag = TRUE;

  do
  {
    printf("ƒ}[ƒN‚ğ‘‚«‚Şƒ}ƒX‚Ì”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
    input_str_length = 0;
    do
    {
      recive_char = getchar();
      input_str_length++;

      if (input_str_length == 1) {
        if ((isdigit(recive_char)) && (recive_char != '0')) {
          recive_char = recive_char - '0';
          input_num = recive_char;
          input_roop_flag = FALSE;
        }
        else {
          input_roop_flag = TRUE;
        }
      }
      else if ((input_str_length == 2) && recive_char != '\n') {
        input_roop_flag = TRUE;
      }
    } while (recive_char != '\n');
    if (input_roop_flag == TRUE) {
      printf("1`%d‚Ìƒ}ƒX”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n", SIDE_LONG * SIDE_LONG);
    }
  } while (input_roop_flag);

  return input_num;

}

void PrintBoard(MARK* pt_playerboard) {
  int board_number = 0;
  char multibyte_num_str[SIDE_LONG * SIDE_LONG][3] = { {"‚P"},{"‚Q"},{"‚R"},{"‚S"},{"‚T"},{"‚U"},{"‚V"},{"‚W"},{"‚X"} };

  for (int i = 0; i < SIDE_LONG; i++) {
    for (int j = 0; j < SIDE_LONG; j++) {
      switch (*pt_playerboard) {
      case BLANK:printf("%s", multibyte_num_str[board_number]);
        pt_playerboard++;
        board_number++;
        break;
      case PLAYER1_MARK:printf("Z");
        pt_playerboard++;
        board_number++;
        break;
      case PLAYER2_MARK:printf("~");
        pt_playerboard++;
        board_number++;
        break;
      default:
        break;
      }
      if (j != SIDE_LONG - 1)
      {
        printf("b");
      }
      else
      {
        printf("\n[{[{[");
      }
    }
    printf("\n");
  }
}

RESULT CheckBoard(const MARK player_board[SIDE_LONG][SIDE_LONG]) {
  int blank_flag = FALSE;
  int PLAYER1_win_flag = FALSE;
  int PLAYER2_win_flag = FALSE;

  for (int i = 0; i < SIDE_LONG; i++) {
    for (int j = 0; j < SIDE_LONG; j++) {
      if (player_board[i][j] == BLANK)
      {
        blank_flag = TRUE;
      }
    }
  }

  for (int column = 0; column < SIDE_LONG - LINE_UP_NUM + 1; column++) {
    for (int row = 0; row < SIDE_LONG; row++)
    {
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER1_MARK) && ((ONE_RIGHT(player_board, row, column)) == PLAYER1_MARK) && ((DOUBLE_RIGHT(player_board, row, column)) == PLAYER1_MARK)) {
        PLAYER1_win_flag = TRUE;
      }
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER2_MARK) && ((ONE_RIGHT(player_board, row, column)) == PLAYER2_MARK) && ((DOUBLE_RIGHT(player_board, row, column)) == PLAYER2_MARK)) {
        PLAYER2_win_flag = TRUE;
      }
    }
  }

  for (int row = 0; row < SIDE_LONG - LINE_UP_NUM + 1; row++) {
    for (int column = 0; column < SIDE_LONG; column++)
    {
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER1_MARK) && ((ONE_LOWER(player_board, row, column)) == PLAYER1_MARK) && ((DOUBLE_LOWER(player_board, row, column)) == PLAYER1_MARK)) {
        PLAYER1_win_flag = TRUE;
      }
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER2_MARK) && ((ONE_LOWER(player_board, row, column)) == PLAYER2_MARK) && ((DOUBLE_LOWER(player_board, row, column)) == PLAYER2_MARK)) {
        PLAYER2_win_flag = TRUE;
      }
    }
  }

  for (int column = 0; column < SIDE_LONG - LINE_UP_NUM + 1; column++) {
    for (int row = 0; row < SIDE_LONG - LINE_UP_NUM + 1; row++)
    {
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER1_MARK) && ((ONE_LOWER_RIGHT(player_board, row, column)) == PLAYER1_MARK) && ((DOUBLE_LOWER_RIGHT(player_board, row, column)) == PLAYER1_MARK)) {
        PLAYER1_win_flag = TRUE;
      }
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER2_MARK) && ((ONE_LOWER_RIGHT(player_board, row, column)) == PLAYER2_MARK) && ((DOUBLE_LOWER_RIGHT(player_board, row, column)) == PLAYER2_MARK)) {
        PLAYER2_win_flag = TRUE;
      }
    }
  }

  for (int column = SIDE_LONG - 1; column >= SIDE_LONG - 1; column--) {
    for (int row = 0; row < SIDE_LONG - LINE_UP_NUM + 1; row++)
    {
      if (((ORIGIN_POINT(player_board, row, column)) == PLAYER1_MARK) && ((ONE_LOWER_LEFT(player_board, row, column)) == PLAYER1_MARK) && ((DOUBLE_LOWER_LEFT(player_board, row, column)) == PLAYER1_MARK)) {
        PLAYER1_win_flag = TRUE;
      }
      else if (((ORIGIN_POINT(player_board, row, column)) == PLAYER2_MARK) && ((ONE_LOWER_LEFT(player_board, row, column)) == PLAYER2_MARK) && ((DOUBLE_LOWER_LEFT(player_board, row, column)) == PLAYER2_MARK)) {
        PLAYER2_win_flag = TRUE;
      }
    }
  }

  if (PLAYER1_win_flag) {
    return PLAYER1_WIN;
  }
  else if (PLAYER2_win_flag) {
    return PLAYER2_WIN;
  }
  else if (blank_flag) {
    return NONE;
  }
  else {
    return DRAW;
  }
}