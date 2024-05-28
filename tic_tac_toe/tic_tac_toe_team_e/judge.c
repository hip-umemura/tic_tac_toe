#include "enum.h"
#include "judge.h"
// 勝敗判定
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
	// プレイヤーの判定
	if (player_turn == TURN_PLAYER1) {
		mark = 'o';
		win_player = PLAYER1_WIN;
	}
	else {
		mark = 'x';
		win_player = PLAYER2_WIN;
	}
	//行、列、斜めの判定
	for (i = 0; i < NUM; i++) {
		for (j = 0; j < NUM; j++) {
			if (g_board[i][j] == mark) {// 行の走査
				mark_count_row++;
			}
			if (g_board[j][i] == mark) {// 列の走査
				mark_count_column++;
			}
		}
		// 行と列の結果判定
		if ((mark_count_row == NUM) || (mark_count_column == NUM)) {
			return win_player;
		}
		else {
			mark_count_row = 0;// 行カウントの初期化
			mark_count_column = 0;// 列カウントの初期化
		}
		// 斜めの走査
		if (g_board[i][i] == mark) {// 右下がり方向
			mark_count_lower_right++;
		}
		if (g_board[i][(NUM - 1) - i] == mark) {// 左下がり方向
			mark_count_lower_left++;
		}
	}
	// 斜めの結果判定
	if ((mark_count_lower_left == NUM) || (mark_count_lower_right == NUM)) {
		return win_player;
	}
	// 勝負中か引き分けの判定
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
	// 勝負がつかなかった場合
	return RESULT_NONE;
}
// 手番を進行
TURN NextTurn(TURN player_turn) {
	if (player_turn == TURN_PLAYER1) {
		return TURN_PLAYER2;
	}
	else {
		return TURN_PLAYER1;
	}
}