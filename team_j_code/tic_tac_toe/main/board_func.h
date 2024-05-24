#pragma once

typedef enum
{
  BLANK,
  PLAYER1_MARK,
  PLAYER2_MARK
} MARK;

typedef enum
{
  NONE,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
} RESULT;

//関数のプロトタイプ宣言
int ScanInput(void);
void PrintBoard(MARK*);
RESULT CheckBoard(MARK*);

#define TRUE 1
#define FALSE 0
#define SIDE_LONG 3