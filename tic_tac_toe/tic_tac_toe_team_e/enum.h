#pragma

#define NUM 3
#define TRUE 1
#define FALSE 0

char g_board[NUM][NUM];

typedef enum {
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW,
  RESULT_NONE
}RESULT;

typedef enum {
  TURN_PLAYER1,
  TURN_PLAYER2
}TURN;
