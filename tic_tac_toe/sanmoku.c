#include <stdio.h>
#include "sanmoku.h"
#include "board.h"
#include "input_num.h"
#include "decision_count.h"

int main(void) {
	int count_turn;
	BOOL duplication;
	BOOL input_error;	
	JUDGE  now_turn;	
	JUDGE result;
	/*JUDGE draw_result;*/	
	char player_input;	
	RETRY retry = TRY;
	int count_circle_win = 0;
	int count_cross_win = 0;
	char board[ELEMENT];

	while (retry == TRY) {
		count_turn = 0;
		result = UNKNOWN;
		//draw_result = UNKNOWN;
			
		InitBoard(board);
		ShowBoard(board);
			
		while (result == UNKNOWN) {
			duplication = FALSE;
			input_error = FALSE;	
			now_turn =	CheckTurn(count_turn);

			while (duplication != TRUE || input_error != TRUE) {
				DisplayNum(now_turn);
				player_input = PushNum(now_turn);
				duplication = RangeNum(player_input);

				if (duplication == TRUE) {
					input_error = CheckNum(player_input, board);
				}
			}

			ChangeState(player_input, board, now_turn);
			ShowBoard(board);
			result = CheckWin(board, now_turn, count_turn);
			
				count_turn++;	
		
		}
	
		if (result == CIRCLE_WIN || result == CROSS_WIN) {
				
			CountWin(result, &count_circle_win, &count_cross_win);
		}

		retry = PlayEnd(count_circle_win, count_cross_win);
	
	}
}


