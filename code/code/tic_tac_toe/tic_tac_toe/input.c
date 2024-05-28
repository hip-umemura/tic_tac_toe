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
	int input;
	
	do {
		printf("1�`9�̐�������͂��Ă�������\n");

		if (player == PLAYER1) {
			printf("�v���C���[�P(o)�@���́F");
		} else {
			printf("�v���C���[�Q(x)�@���́F");
		}
		scanf_s("%2d", &input);
		scanf_s("%*[^\n]");
	} while (InputErrorBoard(input, board) == ERROR);
	return input;
}

void BoardUpdate(PLAYER player, int input, char board[INDEX][INDEX])
{
	int x;
	int y;

	x = (input - 1) / INDEX;
	y = (input - 1) % INDEX;

	if (player == PLAYER1) {
		board[x][y] = 'o';
	} else if (player == PLAYER2) {
		board[x][y] = 'x';
	}
}
