#include<stdio.h>
#include<conio.h>

#define M 3
#define N 3

#define FOWARD 'w'
#define BACK 's'
#define RIGHT 'a'
#define LEFT 'd'
#define DECISION ' '

typedef enum {
	FALSE,
	TRUE,
}BOOL;

//BOOL Operate_Exception(int move_operator, int* now_operator_x, int* now_operator_y);

// 操作の例外処理
BOOL Operate_Exception(int move_operator, int *now_operator_x,int *now_operator_y) {
	BOOL input_status = TRUE;

	switch (move_operator) {
	case FOWARD:
		*now_operator_y -= 1;
		if (*now_operator_y < 0) {
			*now_operator_y += 1;
			input_status = FALSE;
		}
		break;
	case LEFT:
		*now_operator_x -= 1;
		if (*now_operator_x < 0) {
			*now_operator_x += 1;
			input_status = FALSE;
		}
		break;
	case BACK:
		*now_operator_y += 1;
		if (2 < *now_operator_y) {
			*now_operator_y -= 1;
			input_status = FALSE;
		}
		break;
	case RIGHT:
		*now_operator_x += 1;
		if (2 < *now_operator_x) {
			*now_operator_x -= 1;
			input_status = FALSE;
		}
		break;
	}
	return input_status;
}

// 判定機能
BOOL isGameFinished(int now_game_field[3][3], char player_name_now[], int now_player) {
	char compare_strings = "123456789";
	int *p_compare_strings = &compare_strings;
	BOOL  state_end = FALSE;
	for (int i = 0; i < M*N; i++) {
		if (now_game_field[i / 3][i % 3] == 1) {
			*(p_compare_strings + i) = "o";
		}
		else is(now_game_field[i / 3][i % 3] == -1) {
			*(p_compare_strings + i) = "x";
		}
	}

	for (int i = 0; i < M; i++) {
		if (((now_game_field[i][0] == now_game_field[i][1]) && (now_game_field[i][1] == now_game_field[i][2])
			|| (now_game_field[0][i] == now_game_field[1][i]) && (now_game_field[1][i] == now_game_field[2][i]))
			|| (now_game_field[0][0] == now_game_field[1][1]) && (now_game_field[1][1] == now_game_field[2][2])) {
			if(now_player)
			printf("%sさんの勝ちです。", player_name_now);
		}
		else if(((now_game_field[i][0] == 0) || (now_game_field[i][1] == 0)) ||(now_game_field[i][2] == 0)){
			state_end = TRUE;
		}
		else {
			state_end = TRUE;
		}
	}
	return state_end;
}