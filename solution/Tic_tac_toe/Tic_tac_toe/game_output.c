#include <stdio.h>
#include "data.h"
#include "game_output.h"

void DisplayBoard(char game_board[BOARD_HEIGHT][BOARD_WIDTH])
{
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		printf("--+---+--\n");

		for (int j = 0; j < BOARD_WIDTH; j++) {
			printf("%c ", game_board[i][j]);

			if (j < BOARD_WIDTH - 1) {
				printf("| ");
			}
		}

		printf("\n");
	}

	printf("--+---+--\n");
}

void DisplayStatus(char player_name[])
{
	printf("%s�̃^�[��\n", player_name);
	printf("0�`8�̐�������͂��Ă������� : ");
}

void DisplayResult(char winner_name[], BOOL judge)
{
	if (judge == TRUE) {
		printf("%s�̏���!", winner_name);
	}
	else if (judge == FALSE) {
		printf("��������");
	}
}