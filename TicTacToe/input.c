// ���͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <conio.h>
#include "define.h"

// ���͂��󂯕t����֐�
char Input(TURN turn_info)
{
	char input = '0';
	if (turn_info == O_TURN) {
		printf("�Z��u���O���b�h��I�����Ă��������B\n");
	}
	else {
		printf("�~��u���O���b�h��I�����Ă��������B\n");
	}
	input = getch();

	return input;
}
