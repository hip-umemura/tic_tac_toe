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
        // �L�����ꂽ�󂪉������ɂR����ł��邩���m�F
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
        // �L�����ꂽ�󂪏c�����ɂR����ł��邩���m�F
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

    // �L�����ꂽ�󂪉E�������ɂR����ł��邩���m�F
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

    // �L�����ꂽ�󂪍��������ɂR����ł��邩���m�F
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

    // �}�X���S�Ė��܂������ǂ������m�F
    if (turn == INDEX * INDEX)
    {
        return DRAW;
    }

    // �܂����s�����肵�Ă��Ȃ�
    return CONTINUE;
}

void ResultOutput(JUDGE result)
{
    if (result == PLAYER1_WIN)
    {
        puts("�v���C���[�P�̏����I");
    }
    if (result == PLAYER2_WIN)
    {
        puts("�v���C���[�Q�̏����I");
    }
    if (result == DRAW)
    {
        puts("��������");
    }
}
