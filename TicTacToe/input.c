// ���͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <conio.h>
#include "define.h"

// ���͂��󂯕t����֐�
void Input(TURN turn, char input_info_array[INPUT_LEN])
{
	if (turn == O_TURN) {
		printf("%c", O_MARK);
	}
	else {
		printf("%c", X_MARK);
	}
	printf("��u���O���b�h��I�����Ă��������B\n�F");

	scanf_s("%s", input_info_array, (unsigned)INPUT_LEN);

	// ���̓o�b�t�@���N���A
	while (getchar() != '\n');
}