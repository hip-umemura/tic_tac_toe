#include <stdio.h>
#include <ctype.h>
#include "board_func.h"

#define DEBUG
#define SIDE_LONG 3
//#define BOARD_NUM 9
#define I_EVEN (i % 2 == 0)
#define I_ODD (i % 2 == 1)
#define J_EVEN (j % 2 == 0)
#define J_ODD (j % 2 == 1)


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

      #ifdef DEBUG
      printf("%c\n", recive_char);
      #endif // DEBUG

      if (input_str_length == 1) {
        if (isdigit(recive_char)){
          recive_char = recive_char - '0';
          input_num = recive_char;
          input_roop_flag = FALSE;

         #ifdef DEBUG
          printf("1•¶š–Ú%d\n", input_num);
         #endif // DEBUG
        }
        else {
          printf("1`%d‚Ìƒ}ƒX”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n", SIDE_LONG * SIDE_LONG);
          input_roop_flag = TRUE;
        }
      }
      else if ((input_str_length == 2) && recive_char != '\n') {
        input_roop_flag = TRUE;
      }
    } while (recive_char != '\n');

  } while (input_roop_flag);

  return input_num;

}

void PrintBoard(MARK*pt_playerboard) {
  int board_long = SIDE_LONG * 2 - 1;
  int board_number = 0;
  char multibyte_num_str[SIDE_LONG * SIDE_LONG][3] = { {"‚P"},{"‚Q"},{"‚R"},{"‚S"},{"‚T"},{"‚U"},{"‚V"},{"‚W"},{"‚X"} };

#ifdef DEBUG
    printf("board long is %d\n", board_long);
    for (int i = 0; i < SIDE_LONG * SIDE_LONG; i++) {
      printf("‘SŠp%s\n", multibyte_num_str[i]);
    }
#endif // DEBUG

    for (int i = 0; i < board_long; i++) {
      for (int j = 0; j < board_long; j++) {
        if (I_EVEN && J_EVEN) {
          switch (*pt_playerboard) {
          case BLANK:printf("%s", multibyte_num_str[board_number]);
            pt_playerboard++;
            board_number++;
            break;
          case PLAYER1:printf("Z");
            pt_playerboard++;
            board_number++;
            break;
          case PLAYER2:printf("~");
            pt_playerboard++; 
            board_number++;
            break;
          default:
            break;
          }
        }
        else if (I_EVEN && J_ODD){
          printf("b");
        }
      }
      if (I_ODD)
      {
        printf("[{[{[");
      }
      printf("\n");
    }
 }

RESULT CheckBoard(MARK*pt_player_board) {
  MARK* temp_pt = pt_player_board;
  //MARK player_board[3][3];
  //&player_board[0][0] = temp_pt;
  int row_roop = 0;
  int vertical_roop = 0;
  int blank_flag = FALSE;
  int player1_win_flag = FALSE;
  int player2_win_flag = FALSE;

  while (row_roop < SIDE_LONG)
  {
    if ((temp_pt[row_roop] == PLAYER1) && (temp_pt[row_roop + SIDE_LONG] == PLAYER1) && (temp_pt[row_roop + 2 * SIDE_LONG] == PLAYER1))
    {
      player1_win_flag = TRUE;
      break;
    }
    else if ((temp_pt[row_roop] == PLAYER2) && (temp_pt[row_roop + SIDE_LONG] == PLAYER2) && (temp_pt[row_roop + 2 * SIDE_LONG] == PLAYER2))
    {
      player2_win_flag = TRUE;
      break;
    }
    row_roop++;
  }

  while (row_roop < SIDE_LONG)
  {
    if ((temp_pt[row_roop] == PLAYER1) && (temp_pt[row_roop + SIDE_LONG] == PLAYER1) && (temp_pt[row_roop + 2 * SIDE_LONG] == PLAYER1))
    {
      player1_win_flag = TRUE;
      break;
    }
    else if ((temp_pt[row_roop] == PLAYER2) && (temp_pt[row_roop + SIDE_LONG] == PLAYER2) && (temp_pt[row_roop + 2 * SIDE_LONG] == PLAYER2))
    {
      player2_win_flag = TRUE;
      break;
    }
    row_roop++;
  }


  if (player1_win_flag) {
    return PLAYER1_WIN;
  }
  else if (player2_win_flag) {
    return PLAYER2_WIN;
  }
  else if (blank_flag) {
    return NONE;
  }
  else{
    return DRAW;
  }
}

int main(void) {

  RESULT t;
  MARK p[SIDE_LONG][SIDE_LONG] = {{BLANK,BLANK,BLANK},{PLAYER2,BLANK,PLAYER1},{PLAYER1,PLAYER1,PLAYER1}};
  //t = ScanInput();
  //printf("%d\n", t);
  PrintBoard(p);
  t = CheckBoard(p);
  printf("Ÿ”s %d\n", t);
}