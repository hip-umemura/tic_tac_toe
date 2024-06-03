#include <stdio.h>
#include <string.h>
#include "define.h"
#include "game_ready.h"
#include "get_input.h"
#include "get_output.h"
#include "get_result.h"


int main(void) {

	char game[ONEDIMENTION];
	char game_board[TWODIMENTION][TWODIMENTION];

	int count;
	int range;
	int checker;
	int try = CONTINUE;
	char result;

	while (try == CONTINUE) {

		result = UNKNOWN;
		count = 0;

		InitSquare(game_board);

		PreScreen(game_board);
		
		while (result == UNKNOWN) {

			range = FALSE;
			checker = FALSE;

			while (range == FALSE || checker == FALSE){

				
				SquareNumber(count, game);

				range = NumRange(game);

				checker = MarkChecker(game_board, game);

			}
	
			PrintMark(count, game, game_board);

			result = Bingo(game_board, count);

			if (result == UNKNOWN) {
				result = SquareFull(count);
			}

			count++;

		}

		GameResult(result);

		try = PlayAgain();

	}

		return 0;

}