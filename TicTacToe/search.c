//�T�������̊֐��̒�`���L�q����\�[�X�t�@�C��

#include "define.h"

// ���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(char input_info, char board_info[3][3]) {
	// �J�E���^�ϐ��̐錾
	int x = 0;
	int y = 0;

	// ���`�T��
	for (y = GRID_HEIGHT - 1; y >= 0; y--) {
		BOOL match = FALSE;
		for (x = 0; x < GRID_WIDTH; x++) {
			if (input_info == ('1' + (GRID_HEIGHT - y - 1) * GRID_WIDTH + x)) {
				match = TRUE;
				break;
			}
		}
		if (match) {
			break;
		}
	}

	INDEX index = { x, y };
	return index;
}