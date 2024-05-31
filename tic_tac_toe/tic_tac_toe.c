#include <stdio.h>
#include <string.h>
#include "define.h"
#include "game_ready.h"
#include "get_input.h"
#include "get_output.h"
#include "get_result.h"


int main(void) {

	int game[2];
	char game_board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };

	int count = 0;
	int range = FALSE;
	int checker = FALSE;
	int try = CONTINUE;
	char result = UNKNOWN;

	while (try == CONTINUE) {

		count = 0;
		result = UNKNOWN;
		try = CONTINUE;
		result = UNKNOWN;

		InitSquare(game_board);

		PreScreen(game_board);
		
		while (1) {

			range = FALSE;
			checker = FALSE;

			while (range == FALSE || checker == FALSE){

				
				SquareNumber(count, game);

				range = NumRange(game);

				checker = MarkChecker(game_board, game);

			}
	
			PrintMark(count, game, game_board);

			result = Bingo(game_board, count);

			if (result == O_WIN || result == X_WIN) {
				break;
			}
			
			result = SquareFull(count);

			if (result == DROW) {
				break;
			}

			count++;

		}

		GameResult(result);

		try = PlayAgain();

	}

		return 0;

}