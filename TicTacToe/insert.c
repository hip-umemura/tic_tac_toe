// �f�[�^�̑}�������̒�`���L�q����\�[�X�t�@�C��

#include "define.h"

// �w�肳�ꂽ�O���b�h�ɐ}����������֐�
void Insert(char* board_element_info, TURN turn_info)
{
	switch (turn_info) {
	case O_TURN:
		*board_element_info = O_MARK;
		break;
	case X_TURN:
		*board_element_info = X_MARK;
		break;
	default:
		exit(ERROR);
	}
}