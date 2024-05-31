#pragma once
#ifndef GET_OUTPUT_H
#define GET_OUTPUT_H

void PrintMark(int count, char game[], char(*game_board)[3]);
WIN Bingo(char game_board[3][3], int count);
WIN SquareFull(int count_num);

#endif