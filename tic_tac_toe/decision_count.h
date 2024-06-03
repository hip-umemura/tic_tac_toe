#pragma once

BOOL RangeNum(char input_num);

BOOL CheckNum(char input_num, char* square);

JUDGE CheckWin(char square[ELEMENT], TURN turn_symbol);

JUDGE CheckDraw(int turn_counter);