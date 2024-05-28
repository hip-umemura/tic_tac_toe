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
	printf("%sのターン\n", player_name);
	printf("0〜8の数字を入力してください : ");
}

void DisplayResult(char winner_name[], BOOL judge)
{
	if (judge == TRUE) {
		printf("%sの勝利!", winner_name);
	}
	else if (judge == FALSE) {
		printf("引き分け");
	}
}