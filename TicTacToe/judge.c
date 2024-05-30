// ���蕔���̊֐��̒�`���L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "define.h"

// Judge_Grid�֐��̐錾
BOOL Judge_Grid(char board_info)
{
	if (board_info == 'o' || board_info == 'x') {
		printf("�󂢂Ă���O���b�h��I�����Ă��������B\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

// ���͂����������𔻒肷��֐�
BOOL Judge_Input(char input_possess)
{
	if (input_possess < '1' || input_possess > '9') {
		printf("1�`9�̔��p����������͂��Ă��������B");
		return FALSE;
	}
	else {
		return TRUE;
	}

}

// �O�ڕ��ׂ̏��s�̔��������֐�
RESULT Judge_Result(char board_info[GRID_HEIGHT][GRID_WIDTH], TURN turn_info, INDEX grid_element_designation, int turn_count)
{
	int		loop_count;
	int		line_count;
	char 	standard_symbol = board_info[grid_element_designation.y][grid_element_designation.x];

	INDEX current_element_designation[] = {
		{grid_element_designation.x,0},
		{0,grid_element_designation.y},
		{0,0},
		{2,0}
	};

	INDEX diff_element_designation[] = {
		{0,1},
		{1,0},
		{1,1},
		{-1,1}
	};
	
	for (loop_count = 0; loop_count < 4; loop_count++) {
		line_count = 0;
		while (current_element_designation[loop_count].x < 3 && current_element_designation[loop_count].y < 3) {
			if (board_info[current_element_designation[loop_count].y][current_element_designation[loop_count].x] == standard_symbol) {
				line_count++;
			}
			else {
				break;
			}
			current_element_designation[loop_count].x += diff_element_designation[loop_count].x;
			current_element_designation[loop_count].y += diff_element_designation[loop_count].y;
		}
		if (line_count >= 3) {
			if (turn_info == O_TURN) {
				return O_WIN;
			}
			else {
				return X_WIN;
			}
		}
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
