#pragma once
void InitBoard(char* square);

char PushNum(TURN turn_symbol);

void CountWin(JUDGE result, int* get_circle, int* get_cross);

RETRY PlayEnd(int get_circle, int get_cross);
