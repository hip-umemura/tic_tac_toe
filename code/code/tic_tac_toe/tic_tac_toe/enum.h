#pragma once

typedef enum
{
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW,
    CONTINUE
} GAME_JUDGE;

typedef enum
{
    RETRY,
    FINISH
} RETRY_JUDGE;

typedef enum
{
    ERROR,
    NONE_ERROR
} ERROR_JUDGE;

typedef enum
{
    PLAYER1,
    PLAYER2
} PLAYER;

#define INDEX (3)
