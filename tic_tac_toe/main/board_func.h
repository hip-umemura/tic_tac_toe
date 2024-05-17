#pragma once

typedef enum
{
  BLANK,
  PLAYER1,
  PLAYER2
} MARK;

typedef enum
{
  NONE,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
} RESULT;

//�֐��̃v���g�^�C�v�錾
int ScanInput(void);
void PrintBoard(MARK*);
RESULT CheckBoard(MARK*);

#define TRUE 1
#define FALSE 0