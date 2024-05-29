#include <stdio.h>
#include "data.h"

BOOL BoardJudgement(char game_board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int count = 0;
    int row;
    int col;

    // Check rows
    for (row = 0; row < BOARD_HEIGHT; row++) {
        count = 0;
        for (col = 1; col < BOARD_WIDTH; col++) {
            if (game_board[row][col] == game_board[row][col - 1]) {
                count++;
            }
        }
        if (count >= CONNECTED_NUM_FOR_END) {
            return TRUE;
        }
    }

    // Check columns
    for (col = 0; col < BOARD_WIDTH; col++) {
        count = 0;
        for (row = 1; row < BOARD_HEIGHT; row++) {
            if (game_board[row][col] == game_board[row - 1][col]) {
                count++;
            }
        }
        if (count >= CONNECTED_NUM_FOR_END) {
            return TRUE;
        }
    }

    // Check diagonals1
    count = 0;
    for (row = 1, col = 1; ((row < BOARD_HEIGHT) && (col < BOARD_WIDTH)); row++, col++) {
        if (game_board[row][col] == game_board[row - 1][col - 1]) {
            count++;
        }
        if (count >= CONNECTED_NUM_FOR_END) {
            return TRUE;
        }
    }

    // Check diagonals2
    count = 0;
    for (row = 1, col = 1; ((row < BOARD_HEIGHT) && (col >= 0)); row++, col--) {
        if (game_board[row][col] == game_board[row - 1][col + 1]) {
            count++;
        }
        if (count >= CONNECTED_NUM_FOR_END) {
            return TRUE;
        }
    }

    return FALSE;
}