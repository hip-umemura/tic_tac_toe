#pragma once
#include<stdio.h>
#include<conio.h>
#include "game_start.h"

void ShowPlayer(PLAYER now_player) {
	printf("%s�̔Ԃł��B%d�}�X�~%d�}�X�̒�����D���ȏꏊ��I�����Ă��������B\n",
		now_player.player_name, BOARD_SIZE_X, BOARD_SIZE_Y);
	printf("���̏ꏊ���Z����͂���ꏊ�ɂȂ�܂��B\n");
	printf("���̈ړ����@�́A�uA�F���A W�F��AS�F���AD�F�E�v�ł��B\n");
	printf("�ړ�������X�y�[�X�L�[���������������B\n");
	printf("\n");
}

void ShowBoard(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y],
	char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y]) {

	// �{�[�h�̐�����\��
	printf("�Z�~�\���p�Ֆ�");
	for (int i = 0; i < 6; i++) {
		printf("�@");
	}
	printf("�Z�~���͗p�Ֆ�\n");

	// �Z�~�\���p�ՖʂƁZ�~���͗p�Ֆʂ���ׂĕ\��
	for (int i = 0; i < BOARD_SIZE_X; i++) {
		for (int j = 0; j < 2; j++) {
			printf("�@");
		}
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			printf("%s", (display_ox_board[i][j] == 'o') ? "�Z\0" :
				((display_ox_board[i][j] == 'x') ? "�~\0" : "�[\0"));
		}
		for (int j = 0; j < 4; j++) {
			printf("�@");
		}
		printf("|");
		for (int j = 0; j < 6; j++) {
			printf("�@");
		}
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			printf("%s", (input_ox_board[i][j] == '0') ? "�[\0" : "��");
		}
		printf("\n");
	}
}

int Input(void) {
	return _getch();
}

void ChoicePosition(PLAYER now_player, char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], char* p_dispaly_ox_board) {
	for (int i = 0; i < BOARD_SIZE_X; i++) {
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			if (input_ox_board[i][j] == '1') {
				if (*(p_dispaly_ox_board + ((BOARD_SIZE_X * i) + j)) == 'o' ||
					*(p_dispaly_ox_board + ((BOARD_SIZE_X * i) + j)) == 'x') {
					printf("���̃}�X�͂��łɓ��͂���Ă��܂��B�ē��͂����肢���܂��B\n");
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
}

// �C���҂�
void PlayerMove(char* p_input_ox_board, int move_direction) {
	if (OperatingException(p_input_ox_board, move_direction) == FALSE) {

		switch (move_direction) {
		case 'w':
			for (int i = 0; i < BOARD_SIZE_X; i++) {
				for (int j = 0; j < BOARD_SIZE_Y; j++) {
					if (*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) == '1') {
						*(p_input_ox_board - 3) = '1';
						*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) = '-';
					}
				}
			}
			break;
		case 'a':
			for (int i = 0; i < BOARD_SIZE_X; i++) {
				for (int j = 0; j < BOARD_SIZE_Y; j++) {
					if (*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) == '1') {
						*(p_input_ox_board - 1) = '1';
						*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) = '-';
					}
				}
			}
			break;
		case 's':
			for (int i = 0; i < BOARD_SIZE_X; i++) {
				for (int j = 0; j < BOARD_SIZE_Y; j++) {
					if (*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) == '1') {
						*(p_input_ox_board + 3) = '1';
						*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) = '-';
					}
				}
			}
			break;
		case 'd':
			for (int i = 0; i < BOARD_SIZE_X; i++) {
				for (int j = 0; j < BOARD_SIZE_Y; j++) {
					if (*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) == '1') {
						*(p_input_ox_board + 1) = '1';
						*(p_input_ox_board + ((BOARD_SIZE_X * i) + j)) = '-';
					}
				}
			}
			break;
		}
	}
}

BOOL OperatingException(char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], int move_direction) {
	for (int i = 0; i < BOARD_SIZE_Y; i++) {
		if ((input_ox_board[0][i] == '1') && (move_direction == 'w')) {
			return FALSE;
		}
		else if ((input_ox_board[i][0] == '1') && (move_direction == 'a')) {
			return FALSE;
		}
		else if ((input_ox_board[BOARD_SIZE_X - 1][i] == '1') && (move_direction == 's')) {
			return FALSE;
		}
		else if ((input_ox_board[i][BOARD_SIZE_Y - 1] == '1') && (move_direction == 'd')) {
			return FALSE;
		}
	}
	return TRUE;
}