#include <stdio.h>
#include "board.h"

char board[BOARD_SIZE][BOARD_SIZE];	// �Ֆʂ��O���[�o���ϐ��Œ�`�ichar�^�j

void print_now_board(void) { // �Ֆʂ̏󋵂�\��

		int row, column; //�s�A��
		for (column = 0; column < BOARD_SIZE; column++) {
			printf("   %d", column + 1);
		}
		printf("\n");
		for (row = 0; row < BOARD_SIZE; row++) {
			printf(" -------------\n");
			printf("%d|", row + 1);
			for (column = 0; column < BOARD_SIZE; column++) {
				printf(" %c |", board[row][column]);
			}
			printf("\n");
		}
		printf(" -------------\n");
}

int put_piece(int row, int column, PLAYER player) {
	row--; // 1����n�܂���͂�0����n�܂�C���f�b�N�X�ɕϊ�
	column--;
	if (((row >= 0) && (row < BOARD_SIZE)) && ((column >= 0) && (column < BOARD_SIZE)) && (board[row][column] == ' ')) {
		board[row][column] = player.piece;
		return TRUE; //���z�u�o�����ꍇ�ɂ�TRUE(1)
	}
	else {
		return FALSE;// �z�u�o���Ȃ������ꍇ�i���W���s���܂��͋���ɔz�u����Ă���j�ɂ�FALSE(0)��߂�l�Ƃ��ĕԂ��B
	}
}

RESULT judge_game(void) {
	for (int row = 0; row < BOARD_SIZE; row++) {
		if ((board[row][0] == board[row][1]) && (board[row][1] == board[row][2]) && (board[row][0] != ' ')) {
			return WIN; //�@�s���`�F�b�N����OX��������Ă���Ƃ�
		}
	}
	for (int column = 0; column < BOARD_SIZE; column++) {
		if ((board[0][column] == board[1][column]) && (board[1][column] == board[2][column]) && (board[0][column] != ' ')) {
			return WIN; //�@����`�F�b�N����OX��������Ă���Ƃ�
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' ')) {
		return WIN; //�@�E�΂߂�������Ă���Ƃ�
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != ' ')) {
		return WIN; // ���΂߂�������Ă���Ƃ�
	}
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			if (board[row][column] == ' ') {
				return NONE; // �܂��󂫃X�y�[�X������Ȃ�NONE
			}
		}
	}
	return DRAW; // �S�ẴX�y�[�X�����܂��Ă���Ȃ�DRAW
}

void clean_board(void) { // �Ֆʂ�������
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			board[row][column] = ' ';
		}
	}
}
