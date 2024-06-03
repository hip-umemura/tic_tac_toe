// ���蕔���̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "define.h"

// Judge_Grid�֐��̐錾
BOOL Judge_Grid(char board_info_array, char symbol_array[PLAYER_NUM])
{
	for (int i = 0; i < PLAYER_NUM; i++) {
		if (board_info_array == symbol_array[i]) {
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
RESULT Judge_Result(char board_info_array[GRID_HEIGHT][GRID_WIDTH], char symbol, INDEX grid_element_designation, int turn_count)
{
	int count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[(grid_element_designation.y + 1 + i) % GRID_HEIGHT][grid_element_designation.x] == symbol) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}
	count = 0;
	for (int i = 0; i < LINE_NUM; i++) {
		if (board_info_array[grid_element_designation.y][(grid_element_designation.x + 1 + i) % GRID_WIDTH] == symbol) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}
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
		if (board_info_array[i][GRID_WIDTH - 1 - i] == board_info_array[i + 1][GRID_WIDTH -2 - i]) {
			count++;
		}
	}
	if (count >= LINE_NUM) {
		return WIN;
	}

	// �O���b�h�������ׂ��Ė��܂��Ă���ꍇ�ADRAW��Ԃ��B
	// �Q�[���̏I�������肳��Ă��Ȃ��ꍇ�ACONTINUE��Ԃ��B
	if (turn_count >= 9) {
		return DRAW;
	}
	else {
		return CONTINUE;
	}
}