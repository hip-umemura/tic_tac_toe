#pragma once
void InitBoard(char* board);

char PushNum();

void CountWin(JUDGE now_turn, int* count_circle_win, int* count_cross_win);

RETRY PlayEnd(int count_circle_win, int count_cross_win);

void ChangeState(char player_input, char* board, JUDGE now_turn);