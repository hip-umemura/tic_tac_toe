// �T�������̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "define.h"

// ���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(int input_info, char board_info_array[3][3])
{
	// �J�E���^�ϐ��̐錾
	int x = 0;
	int y = 0;
	int count = 0;

	// ���[�v�𔲂������
	BOOL match = FALSE;

	for (y = GRID_HEIGHT - 1; y >= 0; y--) {
		for (x = 0; x < GRID_WIDTH; x++) {
			count++;
			if (input_info == count) {
				INDEX index = { x, y };
				return index;
			}
		}
	}
	printf("�G���[�F���͂���蒼���Ă��������B");
}