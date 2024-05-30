// �o�͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// �Ֆʂ�\������֐�
void Output_Grid(char board_info[3][3])
{
	printf("-----------------\n");
	for (int column = 0; column < GRID_HEIGHT; column++) {
		for (int row = 0; row < GRID_WIDTH; row++) {
			printf("  %c  ", board_info[column][row]);
			printf("|");
		}
		printf("\b \n");
		printf("-----------------\n");
	}
}

// �ՖʂƂǂ���̃^�[������\������֐�
void Output_Turn(TURN turn_info)
{
	if (turn_info == O_TURN) {
		printf("���̃^�[���ł��B\n");
	}
	else {
		printf("�~�̃^�[���ł��B\n");
	}
}

// �ՖʂƏ��s�̌��ʂ�\������֐�
void Output_Result(RESULT result_info)
{
	if (result_info == O_WIN) {
		printf("�Z�̏����ł��B\n");
	}
	else if (result_info == X_WIN){
		printf("�~�̏����ł��B\n");
	}
	else if (result_info  == DRAW){
		printf("���������ł��B\n");
	}
}


