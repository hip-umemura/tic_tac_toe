// �o�͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// �Ֆʂ�\������֐�
void Output_Grid(char board_info_array[3][3])
{
	printf("-----------------\n");
	for (int column = 0; column < GRID_HEIGHT; column++) {
		for (int row = 0; row < GRID_WIDTH; row++) {
			printf("  %c  ", board_info_array[column][row]);
			printf("|");
		}
		printf("\b \b\n");
		printf("-----------------\n");
	}
}

// �ՖʂƂǂ���̃^�[������\������֐�
void Output_Turn(TURN current_turn)
{
	if (current_turn == O_TURN) {
		printf("%c�̃^�[���ł��B\n", O_MARK);
	}
	else {
		printf("%c�̃^�[���ł��B\n", X_MARK);
	}
}

// �ՖʂƏ��s�̌��ʂ�\������֐�
void Output_Result(TURN current_turn, RESULT result_info)
{
	switch (result_info) {
	case WIN:
		if (current_turn == O_TURN) {
			printf("%c", O_MARK);
		}
		else {
			printf("%c", X_MARK);
		}
		printf("�̏����ł��B\n");
		break;
	case DRAW:
		printf("���������ł��B\n");
		break;
	default:
		printf("�G���[�F���ʂ𔻒�ł��܂���ł����B\n");
		break;
	}
}