#include <stdio.h>
#include "data.h"
#include "game_output.h"

void DisplayBoard(char game_board[BOARD_HEIGHT][BOARD_WIDTH], int count)
{
	int row = 0;
	int column = 0;

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		printf("--+---+--\n");

		for (int j = 0; j < BOARD_WIDTH; j++) {

			if (j < 2) {
				printf("%c | ", game_board[i][j]);
			}

			if (j == 2) {
				printf("%c", game_board[i][j]);
			}
		}

		printf("\n");
	}
}

void DisplayStatus(char player_name[])
{
	if (count % 2 == 0) {
		player_name[] = "プレイヤー2";
		printf("%cのターンです。", player_name);
	}
	else
		player_name[] = "プレイヤー1";
	printf("%cのターンです。", player_name);
}

void DisplayResult(char winner_name[], int judge)
{
	printf("0～8の数字を入力してください : ");

	if (〇三つ並んでたら) {
		printf("プレイヤー1の勝利!");
	}
	else if (×三つ並んでたら) {
		printf("プレイヤー2の勝利!");
	}
	else
		printf("引き分け");
}



