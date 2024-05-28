#include <stdio.h>
#include "enum.h"
#include "result.h"
#include "board_output.h"

JUDGE ResultJudge(char board[][INDEX], PLAYER player, int turn)
{
    int row_count;
    int col_count;
    int diag1_count;
    int diag2_count;
    char mark;

    if (player == PLAYER1) {
        mark = 'o';
    } else {
        mark = 'x';
    }

    diag1_count = 0;
    diag2_count = 0;
    for (int x = 0; x < INDEX; x++) {
        row_count = 0;
        col_count = 0;
        for (int y = 0; y < INDEX; y++) {
            if (board[x][y] == mark) {
                row_count++;
            }
            if (board[y][x] == mark) {
                col_count++;
            }
        }
        if (board[x][x] == mark) {
            diag1_count++;
        }
        if (board[INDEX - 1 - x][x] == mark) {
            diag2_count++;
        }
        if ((row_count == INDEX) || (col_count == INDEX) || (diag1_count == INDEX) || (diag2_count == INDEX)) {
            if (player == PLAYER1) {
                return PLAYER1_WIN;
            } else if (player == PLAYER2) {
                return PLAYER2_WIN;
            }
        }
    }

    if (turn == 9) {
        return DRAW;
    }

    return CONTINUE;
}

void ResultOutput(JUDGE result)
{
    if (result == PLAYER1_WIN) {
        printf("プレイヤー１の勝利！\n");
    } else if (result == PLAYER2_WIN) {
        printf("プレイヤー２の勝利！\n");
    } else if (result == DRAW) {
        printf("引き分け\n");
    }
}
