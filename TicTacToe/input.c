// ���͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <conio.h>
#include "define.h"

// ���͂��󂯕t����֐�
void Input(TURN turn, char input_info_array[INPUT_LEN])
{
	switch (turn) {
	case O_TURN:
		printf("%c", O_MARK);
		break;
	case X_TURN:
		printf("%c", X_MARK);
		break;
	default:
		exit(ERROR);
	}
	printf("��u���O���b�h��I�����Ă��������B\n�F");

	scanf_s("%s", input_info_array, (unsigned)INPUT_LEN);

	// ���̓o�b�t�@���N���A
	while (getchar() != '\n');
}