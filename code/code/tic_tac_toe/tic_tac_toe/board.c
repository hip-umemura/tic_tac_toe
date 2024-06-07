#include <stdio.h>
#include <assert.h>
#include "enum.h"
#include "input.h"
#include "board.h"
#include "error.h"

void BoardInitialize(char board[INDEX][INDEX])
{
	char init_value[INDEX][INDEX] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

	for (int x = 0; x < INDEX; x++) {
		for (int y = 0; y < INDEX; y++) {
			board[x][y] = init_value[x][y];
		}
	}
}

void BoardUpdate(PLAYER player, char input,char board[INDEX][INDEX])
{
	for (int i = 0; i < INDEX; i++) {
		for (int j = 0; j < INDEX; j++) {
			if (board[i][j] == input) {
				if (player == PLAYER1) {
					board[i][j] = 'o';
				}
				else if (player == PLAYER2) {
					board[i][j] = 'x';
				}
			}
		}
	}
}

void BoardOutput(char board[INDEX][INDEX])
{
	for (int x = 0; x < INDEX; x++) {
		for (int i = 0; i < INDEX; i++) {
			printf("+---");
		}
		printf("+\n");
		for (int y = 0; y < INDEX; y++) {
			printf("| %c ", board[x][y]);
		}
		printf("|\n");
	}
	for (int i = 0; i < INDEX; i++) {
		printf("+---");
	}
	printf("+\n");
}