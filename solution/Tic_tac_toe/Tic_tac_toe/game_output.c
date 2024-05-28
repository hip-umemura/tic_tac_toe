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

void UpdateBoard(char* square, char mark)
{
	*square = mark;
	//game_info.game_board[board_index.y][board_index.x] = game_info.marks[game_info.player_index];
}

COORDINATES ToIndexOfBoard(int input_number)
{
	COORDINATES index;
	index.y = input_number % BOARD_WIDTH;
	index.x = input_number / BOARD_WIDTH;

	return index;
}