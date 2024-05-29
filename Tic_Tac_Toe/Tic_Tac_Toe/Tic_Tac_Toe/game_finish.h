#pragma once

#include "tic_tac_toe.h"

char GameDecision(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], PLAYER now_player);
char ShowGameResult(char game_state, PLAYER player_info[PLAYER_MEM]);
BOOL Retry_Game();
