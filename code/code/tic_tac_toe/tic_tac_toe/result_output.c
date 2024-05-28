#include<stdio.h>
#include"enum.h"
#include"result_output.h"
#include"board_output.h"

JUDGE ResultJudge(char board[][INDEX], PLAYER player, int turn)
{
    int count;
    int x;
    int y;
    int k;
    char mark = player == PLAYER1 ? 'o' : 'x';

    for (y = 0; y < INDEX; y++)
    {
        // 記入された印が横方向に３つ並んでいるかを確認
        count = 0;
        for (x = 0; x < INDEX; x++)
        {
            if (board[x][y] == mark)
            {
                count++;
            }
        }
        if (count == INDEX)
        {
            return player == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
        }

    }

    for (x = 0; x < INDEX; x++)
    {
        // 記入された印が縦方向に３つ並んでいるかを確認
        count = 0;
        for (y = 0; y < INDEX; y++)
        {
            if (board[x][y] == mark)
            {
                count++;
            }
        }
        if (count == INDEX)
        {
            return player == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // 記入された印が右下方向に３つ並んでいるかを確認
    count = 0;
    for (k = 0; k < INDEX; k++)
    {
        if (board[k][k] == mark)
        {
            count++;
        }
    }
    if (count == INDEX)
    {
        return player == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // 記入された印が左下方向に３つ並んでいるかを確認
    count = 0;
    for (k = 0; k < INDEX; k++)
    {
        if (board[INDEX - 1 - k][k] == mark)
        {
            count++;
        }
    }
    if (count == INDEX)
    {
        return player == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // マスが全て埋まったかどうかを確認
    if (turn == INDEX * INDEX)
    {
        return DRAW;
    }

    // まだ勝敗が決定していない
    return CONTINUE;
}

void ResultOutput(JUDGE result)
{
    if (result == PLAYER1_WIN)
    {
        puts("プレイヤー１の勝利！");
    }
    if (result == PLAYER2_WIN)
    {
        puts("プレイヤー２の勝利！");
    }
    if (result == DRAW)
    {
        puts("引き分け");
    }
}
