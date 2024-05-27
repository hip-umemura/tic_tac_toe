#include "enum.h"
#include "judge.h"
// ���s����
RESULT ResultJudge(TURN player_turn) {
	int i;
	int j;
	int mark_count_row = 0;
	int mark_count_column = 0;
	int mark_count_lower_right = 0;
	int mark_count_lower_left = 0;
	int mark_count_draw = 0;
	int mark_max = NUM * NUM;
	char mark;
	RESULT win_player;
	// �v���C���[�̔���
	if (player_turn == TURN_PLAYER1) {
		mark = 'o';
		win_player = PLAYER1_WIN;
	}
	else {
		mark = 'x';
		win_player = PLAYER2_WIN;
	}
	//�s�A��A�΂߂̔���
	for (i = 0; i < NUM; i++) {
		for (j = 0; j < NUM; j++) {
			if (g_board[i][j] == mark) {// �s�̑���
				mark_count_row++;
			}
			if (g_board[j][i] == mark) {// ��̑���
				mark_count_column++;
			}
		}
		// �s�Ɨ�̌��ʔ���
		if ((mark_count_row == NUM) || (mark_count_column == NUM)) {
			return win_player;
		}
		else {
			mark_count_row = 0;// �s�J�E���g�̏�����
			mark_count_column = 0;// ��J�E���g�̏�����
		}
		// �΂߂̑���
		if (g_board[i][i] == mark) {// �E���������
			mark_count_lower_right++;
		}
		if (g_board[i][(NUM - 1) - i] == mark) {// �����������
			mark_count_lower_left++;
		}
	}
	// �΂߂̌��ʔ���
	if ((mark_count_lower_left == NUM) || (mark_count_lower_right == NUM)) {
		return win_player;
	}
	// �����������������̔���
	for (i = 0; i < NUM; i++) {
		for (j = 0; j < NUM; j++) {
			if (g_board[i][j] != ' ') {
				mark_count_draw++;
			}
		}
	}
	if (mark_count_draw == mark_max) {
		return DRAW;
	}
	// ���������Ȃ������ꍇ
	return RESULT_NONE;
}
// ��Ԃ�i�s
TURN NextTurn(TURN player_turn) {
	if (player_turn == TURN_PLAYER1) {
		return TURN_PLAYER2;
	}
	else {
		return TURN_PLAYER1;
	}
}