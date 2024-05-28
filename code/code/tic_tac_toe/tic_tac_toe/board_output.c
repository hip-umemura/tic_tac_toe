#include <stdio.h>
#include "enum.h"
#include "board_output.h"

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
