#pragma once

#include "tic_tac_toe.h"

void ShowPlayer(PLAYER now_player) {
	printf("%sの番です。%dマス×%dマスの中から好きな場所を選択してください。\n",
		now_player.player_name, BOARD_SIZE_X, BOARD_SIZE_Y);
	printf("△の場所が〇を入力する場所になります。\n");
	printf("△の移動方法は、「A：左、 W：上、S：下、D：右」です。\n");
	printf("移動完了後スペースキーを教えください。\n");
	printf("\n");
}

void ShowBoard(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y],
	char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y]) {
	// ボードの説明を表示
	printf("〇×表示用盤面");
	for (int i = 0; i < 6; i++) {
		printf("　");
	}
	printf("〇×入力用盤面\n");

	// 〇×表示用盤面と〇×入力用盤面を並べて表示
	for (int i = 0; i < BOARD_SIZE_X; i++) {
		for (int j = 0; j < 2; j++) {
			printf("　");
		}
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			printf("%s", (display_ox_board[i][j] == 'o') ? "〇\0" : ((display_ox_board[i][j] == 'x') ? "×\0" : "ー\0"));
		}
		for (int j = 0; j < 4; j++) {
			printf("　");
		}
		printf("|");
		for (int j = 0; j < 6; j++) {
			printf("　");
		}
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			printf("%s", (input_ox_board[i][j] == '0') ? "ー\0" : "△");
		}
		printf("\n");
	}
}

int Input(void) {
	return _getch();

}

void RangeJudgeException(int* p_move_x, int* p_move_y, int direction) {
	switch (direction) {
	case UP_KEY:
		if (*p_move_x) {
			*(p_move_x) -= 1;
		}
		break;
	case LEFT_KEY:
		if (*p_move_y) {
			*(p_move_y) -= 1;
		}
		break;
	case DOWN_KEY:
		if (*(p_move_x) - (BOARD_SIZE_X - 1)) {
			*(p_move_x) += 1;
		}
		break;
	case RIGHT_KEY:
		if (*(p_move_y) - (BOARD_SIZE_Y - 1)) {
			*(p_move_y) += 1;
		}
		break;
	}
}

BOOL MarkPosition(PLAYER now_player, char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], char* p_dispaly_ox_board) {
	for (int i = 0; i < BOARD_SIZE_X; i++) {
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			if (input_ox_board[i][j] == '1') {
				if (*(p_dispaly_ox_board + ((BOARD_SIZE_X * i) + j)) == 'o' ||
					*(p_dispaly_ox_board + ((BOARD_SIZE_X * i) + j)) == 'x') {

					return FALSE;
				}
				else {
					if (now_player.turn == FIRST) {
						*(p_dispaly_ox_board + ((BOARD_SIZE_X * i) + j)) = 'o';
					}
					else {
						*(p_dispaly_ox_board + ((BOARD_SIZE_X * i) + j)) = 'x';
					}
				}
			}
		}
	}
	return TRUE;
}
void PlayerMove(char* p_input_ox_board, int move_direction) {
	int axis_x = 0;
	int axis_y = 0;

	for (int i = 0; i < BOARD_SIZE_X; i++) {
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			if (*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) - '0') {
				axis_x = i;
				axis_y = j;
			}
		}
	}
	*(p_input_ox_board + ((BOARD_SIZE_X * axis_x) + axis_y)) = '0';
	RangeJudgeException(&axis_x, &axis_y, move_direction);
	*(p_input_ox_board + ((BOARD_SIZE_X * axis_x) + axis_y)) = '1';
}
