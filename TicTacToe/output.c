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
		printf("\b \n");
		printf("-----------------\n");
	}
}

// �ՖʂƂǂ���̃^�[������\������֐�
void Output_Turn(char symbol)
{
	printf("%c�̃^�[���ł��B\n", symbol);
}

// �ՖʂƏ��s�̌��ʂ�\������֐�
void Output_Result(char symbol, RESULT result_info)
{
	if (result_info == WIN) {
		printf("%c�̏����ł��B\n", symbol);
	}
	else if (result_info  == DRAW){
		printf("���������ł��B\n");
	}
}


