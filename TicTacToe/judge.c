// ���蕔���̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include <stdlib.h>
#include "define.h"

// Judge_Grid�֐��̐錾
BOOL Judge_Grid(char board_info_array)
{
	for (int i = 0; i < PLAYER_NUM; i++) {
		if (board_info_array == O_MARK || board_info_array == X_MARK) {
			printf("�O���b�h����̔ԍ���I�����Ă��������I\n");
			return FALSE;
		}
	}
	return TRUE;
}

// ���͂����������𔻒肷��֐�
BOOL Judge_Input(char input_possess[INPUT_LEN])
{
	if (input_possess[1] != '\0' && input_possess[1] != '\n' || input_possess[0] < '1' || input_possess[0] > '9') {
		printf("1�`9�̔��p������I�����Ă��������I\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

// �O�ڕ��ׂ̏��s�̔��������֐�
RESULT Judge_Result(char board_info_array[GRID_HEIGHT][GRID_WIDTH], INDEX grid_element_designation, int turn_count)
{
	// INDEX�̃����o�̒l���A�v�f�w��ł��Ȃ��l�̏ꍇ�A�����I��������
	if (grid_element_designation.x < 0 || grid_element_designation.x >= GRID_WIDTH ||
			grid_element_designation.y < 0 || grid_element_designation.y >= GRID_HEIGHT) {
		abort();
	}

	// �c�����āA�����}����3����ł��邩�m�F����B
	int count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[(grid_element_designation.y + i) % GRID_HEIGHT][grid_element_designation.x] ==
				board_info_array[(grid_element_designation.y + 1 + i) % GRID_HEIGHT][grid_element_designation.x]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// �������āA�����}����3����ł��邩�m�F����B
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[grid_element_designation.y][(grid_element_designation.x + i) % GRID_WIDTH] ==
				board_info_array[grid_element_designation.y][(grid_element_designation.x + 1 + i) % GRID_WIDTH]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// �΂߂����āA�����}����3����ł��邩�m�F����B
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[i][i] == board_info_array[i + 1][i + 1]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[i][GRID_WIDTH - 1 - i] == board_info_array[i + 1][GRID_WIDTH - 2 - i]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// �O���b�h�������ׂ��Ė��܂��Ă���ꍇ�ADRAW��Ԃ��B
	// �Q�[���̏I�������肳��Ă��Ȃ��ꍇ�ACONTINUE��Ԃ��B
	if (turn_count >= GRID_WIDTH * GRID_HEIGHT) {
		return DRAW;
	}
	else {
		return CONTINUE;
	}
}