//�o�͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <stdlib.h>

//Output_Info�֐��̐錾
//int tern_info	�^�[���̏������ϐ�
//char board_info	�{�[�h�̏������ϐ�
void Output_Info(int tern_info, char board_info [3][3])
{
	if (tern_info % 2 == 0) {
		printf("���̃^�[���ł��B\n");
	}
	else {
		printf("�~�̃^�[���ł��B\n");
	}
	printf("-----------------\n");
	for (int column = 2; column >= 0; column--) {
		for (int row = 0; row <= 2; row++) {
			printf("  %c  ", board_info[column][row]);
			printf("|");
		}

		//�o�b�N�X�y�[�X����͂��A���p�X�y�[�X�ŏ㏑��
		printf("\b \n");
		printf("-----------------\n");
	}

}