// ���͕����̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <conio.h>
#include "define.h"

// ���͂��󂯕t����֐�
void Input(char symbol, char input_info_array[INPUT_LEN])
{
	char input = '0';

	printf("%c��u���O���b�h��I�����Ă��������B\n�F", symbol);

	scanf_s("%s", input_info_array, (unsigned)INPUT_LEN);

	// ���̓o�b�t�@���N���A
	while (getchar() != '\n');
}
