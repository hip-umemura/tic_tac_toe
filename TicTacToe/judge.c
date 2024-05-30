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
	char 	standard_symbol = board_info[grid_element_designation.y][grid_element_designation.x];

	if (((board_info[(grid_element_designation.y + 1) % GRID_HEIGHT][grid_element_designation.x] == standard_symbol)
				&& (board_info[(GRID_HEIGHT + grid_element_designation.y - 1) % GRID_HEIGHT][grid_element_designation.x] == standard_symbol))
			|| ((board_info[grid_element_designation.y][(grid_element_designation.x + 1) % GRID_WIDTH] == standard_symbol)
				&& (board_info[grid_element_designation.y][(GRID_WIDTH + grid_element_designation.x - 1) % GRID_WIDTH] == standard_symbol))
			|| ((board_info[0][0] == board_info[1][1]) && (board_info[1][1] == board_info[2][2]))
			|| ((board_info[0][2] == board_info[1][1]) && (board_info[1][1] == board_info[2][0]))) {
		if (turn_info == O_TURN) {
			return O_WIN;
		}
		else {
			return X_WIN;
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
