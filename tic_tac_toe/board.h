#pragma once
#ifdef BOARD

void ShowBoard(wchar_t square[9]);

int CheckTurn(int turn);

int DisplayWin(JUDGE judge);

int ChangeState(int input, MARK mark);

#endif // BOARD
