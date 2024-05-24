#include <stdio.h>
#include "data.h"
#include "game_output.h"

void DisplayBoard(char game_board[BOARD_HEIGHT][BOARD_WIDTH])
{
	char game_board[BOARD_HEIGHT][BOARD_WIDTH] = {
		{'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}
	};

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
	printf("0〜8の数字を入力してください : ");
	printf("%sのターン", player_name);
}

void DisplayResult(char winner_name[], int judge)
{
	if (judge == WIN) {
		printf("%sの勝利!", winner_name);
	}
	else
		printf("引き分け");
}