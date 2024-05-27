#include <stdio.h>
#include "data.h"
#include "game_judgement.h"

BOOL BoardJudgement(char game_board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int o_count = 0;
    int x_count = 0;
    int row;
    int col;

    // Check rows
    for (row = 0; row < BOARD_HEIGHT; row++) {
        o_count = 0;
        x_count = 0;
        for (col = 0; col < BOARD_WIDTH; col++) {
            if (game_board[row][col] == 'o') {
                o_count++;
            }
            else if (game_board[row][col] == 'x') {
                x_count++;
            }
        }
        if (o_count >= 3 || x_count >= 3) {
            return TRUE;
        }
    }

    // Check columns
    for (col = 0; col < BOARD_WIDTH; col++) {
        o_count = 0;
        x_count = 0;
        for (row = 0; row < BOARD_HEIGHT; row++) {
            if (game_board[row][col] == 'o') {
                o_count++;
            }
            else if (game_board[row][col] == 'x') {
                x_count++;
            }
        }
        if (o_count >= 3 || x_count >= 3) {
            return TRUE;
        }
    }

    // Check diagonals1
    o_count = 0;
    x_count = 0;
    for (row = 0, col = 0; ((row < BOARD_HEIGHT) && (col < BOARD_WIDTH)); row++, col++) {
        if (game_board[row][col] == 'o') {
            o_count++;
        }
        else if (game_board[row][col] == 'x') {
            x_count++;
        }
        if (o_count >= 3 || x_count >= 3) {
            return TRUE;
        }
    }

    // Check diagonals2
    o_count = 0;
    x_count = 0;
    for (row = 0, col = 2; ((row < 3) && (col < 0)); row++, col--) {
        if (game_board[row][col] == 'o') {
            o_count++;
        }
        else if (game_board[row][col] == 'x') {
            x_count++;
        }
        if (o_count >= 3 || x_count >= 3) {
            return TRUE;
        }
    }

    return FALSE;
}