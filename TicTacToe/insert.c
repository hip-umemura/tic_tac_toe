//�f�[�^�̑}�������̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>

void Insert(char* board_element_info, int turn_info)
{
	if (turn_info % 2 == 1) {
		*board_element_info = 'o';
	}
	else {
		*board_element_info = 'x';
	}


}