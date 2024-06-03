#include <stdio.h>
#include "sanmoku.h"
#include "board.h"
#include "input_num.h"
#include "decision_count.h"

int turn_counter;
BOOL ischeck = FALSE;
BOOL range = FALSE;
TURN  turn_symbol;
JUDGE win_result;
CONTINUE draw_result;
RETRY iscontinue;				// ここが？状態
int get_circle = 0;
int get_cross = 0;
char input_num = 0;
char square[ELEMENT];		

int main(void) {
	
	while (iscontinue != QUIT) {
		turn_counter = 0;
		turn_symbol = CIRCLE;
		win_result = UNKNOWN;
		draw_result = EXTEND; 
		ischeck = FALSE;
		range = FALSE;
				
		InitBoard(square);
		ShowBoard(square);
			
		while (win_result == UNKNOWN && draw_result == EXTEND) {
			range = FALSE;
			ischeck = FALSE;	
			turn_symbol =	CheckTurn(turn_counter);

			while (range != TRUE || ischeck != TRUE) {
				input_num = PushNum(turn_symbol);
				range = RangeNum(input_num);
				if (range == TRUE) {
					ischeck = CheckNum(input_num, square);
					// ここ追加
					if (ischeck == FALSE) {
						printf("既に入力されています。\n");
					}
				}
				if (range == FALSE) {
					printf("範囲内の値を入力してください。\n");
				}
				// ここまで
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
		}
		iscontinue = PlayEnd(get_circle, get_cross);
	}
}


