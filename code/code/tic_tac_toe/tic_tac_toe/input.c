#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "board_output.h"
#include "error.h"

void BoardInitialize(char board[][INDEX])
{
	char init_value[INDEX][INDEX] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

	for (int x = 0; x < INDEX; x++) {
		for (int y = 0; y < INDEX; y++) {
			board[x][y] = init_value[x][y];
		}
	}
}


int PlayerInput(char board[INDEX][INDEX], PLAYER player)
{
	char input;
	
	do {
		printf("1�`9�̐�������͂��Ă�������\n");

		if (player == PLAYER1) {
			printf("�v���C���[�P(o)�@���́F");
		} else {
			printf("�v���C���[�Q(x)�@���́F");
		}
		scanf_s("%c", &input,2);
		/*
		if (getchar() != '\n') {
		  while (getchar() != '\n');
		}
		*/
	
	} while (InputErrorBoard(input, board) == ERROR);
	return input;
}

void BoardUpdate(PLAYER player, int input, char board[][INDEX])
{
  int i, j;
  char mark;

  if (player == PLAYER1) {
	mark = 'o';
  }
  else {
	mark = 'x';
  }

  for (i = 0; i < INDEX; i++) {
	for (j = 0; j < INDEX; j++) {
	  if (input == board[i][j]) {
		board[i][j]= mark;
	  }
	}
  }
}
