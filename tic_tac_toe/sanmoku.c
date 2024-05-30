#include <stdio.h>
#include "sanmoku.h"
#include "board.h"
#include "input_num.h"
#include "decision_count.h"

int main(void) {
	
	int get_circle = 0;
	int get_cross = 0;
	char square[9];
	char input_num = 0;
	RETRY iscontinue = ERROR;
		while (iscontinue != QUIT) {
			int turn_counter = 0;
			TURN  turn_symbol = CIRCLE;
			JUDGE win_result = UNKNOWN;
			CONTINUE draw_result = EXTEND;
			
			
			InitBoard(square);
			ShowBoard(square);
			
			while (win_result == UNKNOWN && draw_result == EXTEND) {
				BOOL range = FALSE;
				BOOL ischeck = FALSE;	
				turn_symbol =	CheckTurn(turn_counter);


				while (range != TRUE || ischeck != TRUE) {
					input_num = PushNum(turn_symbol);
					range = RangeNum(input_num);
					if (range == TRUE) {
						ischeck = CheckNum(input_num, square);
					}
					
				}

				ChangeState(input_num, square, turn_symbol);
				ShowBoard(square);
			
				win_result = CheckWin(square, turn_symbol);
				if (win_result == UNKNOWN) {
					draw_result = CheckDraw(turn_counter);
				
				}
				turn_counter++;	
			}

			if (win_result == CIRCLE_WIN || win_result == CROSS_WIN) {
				CountWin(win_result,	&get_circle,	&get_cross);
			//	printf("%d,%d", get_circle, get_cross);
			}
			iscontinue = PlayEnd(get_circle, get_cross);
	
		}
	}


