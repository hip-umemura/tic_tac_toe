#pragma once

void ShowBoard(char square[ELEMENT]);

TURN CheckTurn(int turn_counter);

CONTINUE DisplayWin(JUDGE win_result);

void ChangeState(char input_num, char *square, TURN turn_symbol);


