#pragma once

BOOL RangeNum(char input_num);

BOOL CheckNum(char input_num, char* square);

JUDGE CheckWin(char square[9], TURN turn_symbol);

CONTINUE CheckDraw(int turn_counter);