//���蕔���̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "define.h"

//�֐��̐錾
BOOL Judge_Grid(char board_info)
{
	if (board_info == 'o' || board_info == 'x') {
		printf("�󂢂Ă���O���b�h��I�����Ă��������B\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

//
BOOL Judge_Input(char input_possess)
{
	if (input_possess ) {

	}

}
