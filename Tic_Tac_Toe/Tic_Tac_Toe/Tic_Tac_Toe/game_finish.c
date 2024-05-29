#include "tic_tac_toe.h"

char GameDecision(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], PLAYER now_player) {
	if (isMatchedCondition(display_ox_board)) {
		if (now_player.turn == FIRST) {
			return 'O';
		}
		else {
			return 'X';
		}
	}
	else {
		if (isFilledBOARD(display_ox_board)) {
			return 'D';
		}
		else {
			return 'F';
		}

	}
}

char ShowGameResult(char game_state, PLAYER player_info[PLAYER_MEM]) {
	if (game_state == 'O') {
		if (player_info[PLAYER_ONE].turn == FIRST) {
			printf("%s����̏���\n", player_info[PLAYER_ONE].player_name);
		}
		else
			printf("%s����̏���\n", player_info[PLAYER_TWO].player_name);
		return 'D';
	}
	else if (game_state == 'X') {
		if (player_info[PLAYER_ONE].turn == FIRST) {
			printf("%s����̏���\n", player_info[PLAYER_TWO].player_name);
		}
		else
			printf("%s����̏���\n", player_info[PLAYER_ONE].player_name);
		return 'D';
	}
	else if (game_state == 'D') {
		printf("���������ł��B\n");
		return 'D';
	}
	else
		return 'F';

}
BOOL Retry_Game() {
	printf("������x�V�т܂����H\n Yes�F0�ȊO�̃L�[ or No�F0\n");
	int retry = Input();
	if (retry == '0') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
