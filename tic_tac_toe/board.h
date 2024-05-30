#pragma once

void ShowBoard(char square[ELEMENT]);

int CheckTurn(int turn_counter);

int DisplayWin(JUDGE win_result);

void ChangeState(char input_num, char *square, TURN turn_symbol);


