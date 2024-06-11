#pragma once

BOOL RangeNum(char player_input);

BOOL CheckNum(char player_input, char board[ELEMENT]);

JUDGE CheckWin(char board[ELEMENT], JUDGE now_turn, int count_turn);

