#include <stdio.h>
#include <conio.h>

typedef struct BOARD_XY {
  int x;
  int y;
} BOARD_XY;

typedef enum {
  NONE,
  WIN,
  DRAW
} RESULT;

typedef enum {
  FALSE,
  TRUE
} BOOL;

void Print_Grid(const char* board);
BOARD_XY Player_Input(const char* board);
RESULT Game_Judge(const int turn_count, const BOARD_XY board_xy, const char* board);

int main(void) {
  int turn_count = 1;
  char player_mark;
  int player_number;
  char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
  BOARD_XY input_xy = { 0, 0 };
  RESULT game_result = NONE;

  while (game_result == NONE) {
    if (turn_count == 1) {
      Print_Grid(*board);
      printf("\n");
    }

    if ((turn_count % 2) == 1) {
      player_mark = 'o';
      player_number = 1;
    }
    else {
      player_mark = 'x';
      player_number = 2;
    }
    printf("player%dのターン\n", player_number);

    input_xy = Player_Input(*board);

    board[input_xy.y][input_xy.x] = player_mark;

    printf("\n");
    Print_Grid(*board);
    printf("\n");

    game_result = Game_Judge(turn_count, input_xy, *board);

    if (game_result == NONE) {
      turn_count++;
    }
    else {
      if (game_result == WIN) {
        printf("player%dの勝利!!!\n", player_number);
      }
      else {
        printf("引き分け\n");
      }

      BOOL input_check = FALSE;
      while (input_check == FALSE) {
        printf("retry?[Y/N]：");
        char retry_or_not = _getch();
        printf("%c", retry_or_not);
        
        int is_flow = _kbhit();
        if ((is_flow != 0) || (retry_or_not != 'Y' && retry_or_not != 'N')) {
          while (is_flow != 0) {
            char flowed = _getch();
            printf("%c", flowed);
            is_flow = _kbhit();
          }
          printf("\n入力エラー：YまたはNを入力してください\n");
        }
        else if (retry_or_not == 'Y') {
          turn_count = 1;
          for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
              board[i][j] = ' ';
            }
          }
          game_result = NONE;

          printf("\n\n");
          input_check = TRUE;
        }
        else {
          printf("\n");
          input_check = TRUE;
        }
      }
    }
  }

  return 0;
}