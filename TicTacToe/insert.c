// �f�[�^�̑}�������̒�`���L�q����\�[�X�t�@�C��

#include "define.h"

// �w�肳�ꂽ�O���b�h�ɐ}����������֐�
void Insert(char* board_element_info, TURN turn_info)
{
	if (turn_info == O_TURN) {
		*board_element_info = O_MARK;
	}
	else {
		*board_element_info = X_MARK;
	}
}