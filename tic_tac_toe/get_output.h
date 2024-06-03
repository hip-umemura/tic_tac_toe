#pragma once
#ifndef GET_OUTPUT_H
#define GET_OUTPUT_H

void PrintMark(int count, char game[], char(*game_board)[TWODIMENTION]);
WIN Bingo(char game_board[TWODIMENTION][TWODIMENTION], int count);
WIN SquareFull(int count_num);

#endif