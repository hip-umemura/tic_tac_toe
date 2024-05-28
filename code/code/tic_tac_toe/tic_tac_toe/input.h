#pragma once
//bord_input.c
void BoardInitialize(char board[INDEX][INDEX]);
int PlayerInput(char board[INDEX][INDEX], PLAYER player);
void BoardUpdate(PLAYER player, int input, char board[INDEX][INDEX]);