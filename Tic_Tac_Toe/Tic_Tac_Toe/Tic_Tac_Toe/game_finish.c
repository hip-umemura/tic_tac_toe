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
			printf("%sさんの勝ち\n", player_info[PLAYER_ONE].player_name);
		}
		else
			printf("%sさんの勝ち\n", player_info[PLAYER_TWO].player_name);
		return 'D';
	}
	else if (game_state == 'X') {
		if (player_info[PLAYER_ONE].turn == FIRST) {
			printf("%sさんの勝ち\n", player_info[PLAYER_TWO].player_name);
		}
		else
			printf("%sさんの勝ち\n", player_info[PLAYER_ONE].player_name);
		return 'D';
	}
	else if (game_state == 'D') {
		printf("引き分けです。\n");
		return 'D';
	}
	else
		return 'F';

}
BOOL Retry_Game() {
	printf("もう一度遊びますか？\n Yes：0以外のキー or No：0\n");
	int retry = Input();
	if (retry == '0') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
