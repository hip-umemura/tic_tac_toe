//�f�[�^�̑}�������̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "define.h"

//
void Insert(char* board_element_info, TURN turn_info)
{
	if (turn_info == O_TURN) {
		*board_element_info = 'o';
	}
	else {
		*board_element_info = 'x';
	}
}