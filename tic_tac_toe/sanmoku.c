#include <stdio.h>
#include "sanmoku.h"
#include "board.h"
#include "input_num.h"
#include "decision_count.h"

int main(void) {
	
	int turn = 0;
	int get_circle = 0;
	int get_cross = 0;
	//int circle = 0;
	//int cross = 0;
	int input;
	int square[9];
	TURN mark = 0;
	JUDGE win_result = UNKNOWN;
	
	while (PlayEnd() != QUIT) {	
	
		while (1) {
			 InitBoard(square);
			 ShowBoard(square);
			while (win_result == EXTEND) {
				CheckTurn();
				while (RangeNum(input) == FALSE || CheckNum(input,square) == FALSE) {
					PushNum(turn);
					RangeNum(input);
					CheckNum(input, square);
				}
				ChangeState(square, input, mark);
				ShowBoard(square);
				win_result = CheckWin(square, turn);
				win_result=CheckDraw(turn);	
				turn++;
			}
			CountWin(win_result,	get_circle,	get_cross);
			PlayEnd();
	
		}
	}
}


