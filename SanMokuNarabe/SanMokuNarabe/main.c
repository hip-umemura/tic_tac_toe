#include<stdio.h>

int main(void) {

  char boad[3][3] = { {' ','o',' '},{' ',' ',' '}, {'g','h','i'} };
  printf("\n");
  printf("\n");
  printf("y.x| 0 | 1 | 2 \n");
  printf("---|---|---|---\n");
  printf(" 0 | %c | %c | %c \n", boad[1][0], boad[1][1], boad[1][2]);
  printf("---|---|---|---\n");
  printf(" 1 | %c | %c | %c \n", boad[1][0], boad[1][1], boad[1][2]);
  printf("---|---|---|---\n");
  printf(" 2 | %c | %c | %c \n", boad[1][0], boad[1][1], boad[1][2]);
  printf("---|---|---|---\n");
  printf("\n");
  //printf("\n");

  printf("player1のターン\n");
  printf("どこに印を記入しますか？\n");
  printf("x(0-2):1\n");
  printf("y(0-2):0\n");

  printf("\n");
  printf("y.x| 0 | 1 | 2 \n");
  printf("---|---|---|---\n");
  printf(" 0 | %c | %c | %c \n", boad[0][0], boad[0][1], boad[0][2]);
  printf("---|---|---|---\n");
  printf(" 1 | %c | %c | %c \n", boad[1][0], boad[1][1], boad[1][2]);
  printf("---|---|---|---\n");
  printf(" 2 | %c | %c | %c \n", boad[1][0], boad[1][1], boad[1][2]);
  printf("---|---|---|---\n");
  printf("\n");

  printf("\n");
  printf("y.x| 0 | 1 | 2 \n");
  printf("---|---|---|---\n");
  printf(" 0 | x | o | x \n");
  printf("---|---|---|---\n");
  printf(" 1 | %c | o | %c \n", boad[1][0], boad[1][1]);
  printf("---|---|---|---\n");
  printf(" 2 | %c | o | %c \n", boad[1][0], boad[1][1]);
  printf("---|---|---|---\n");
  printf("\n");

  printf("player1の勝利!!!\n");
  printf("retry?[Yes/No]:N\n");
}