#include<stdio.h>
#include<conio.h>
#include"game_finish.c"

#define M 3
#define N 3

#define FOWARD 'w'
#define BACK 's'
#define RIGHT 'a'
#define LEFT 'd'
#define DECISION ' '

#define PLAYER_1 1
#define PLAYER_2 -1

typedef enum {
	FALSE,
	TRUE,
}BOOL;

typedef enum {
	REINPUT,
	FIRST_INPUT,
}FLAG;

// game_playing.cからのinclude
BOOL Operate_Exception(int move_operator, int *now_operator_x, int *now_operator_y);
BOOL isGameFinished(int now_game_field[3][3]);

int Input_OX(char player_name_now[], int player_symbol) {
	int now_operator_x = 1;
	int now_operator_y = 1;
	int display_field[M][N];
	int operate_field[M][N];
	BOOL isgame_continue = TRUE;
	FLAG display_tutorial = FIRST_INPUT;

	// display_fieldとinput_fieldの初期化
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			display_field[i][j] = 0;
			operate_field[i][j] = 0;
		}
	}

	// 最初に操作子を中央においておく
	operate_field[now_operator_y][now_operator_x] = 1;
	while (isgame_continue) {

		// 入力エラーの場合表示をしない
		if (display_tutorial) {
			// 画面表示
			printf("%sの番です。3マス×3マスの中から好きな場所を選択してください。\n", player_name_now);
			printf("△の場所が%sを入力する場所になります。\n", (player_symbol > 0) ? "〇" : "×");
			printf("△の移動方法は、「A：左、W：上、S：下、 D：右」です。\n");
			printf("移動完了後スペースキーを押してください。\n");
		}
		printf("〇×表示用盤面　　　 　　〇×入力用盤面\n");
		for (int i = 0; i < N; i++) {
			printf("　　");
			for (int j = 0; j < N; j++) {
				printf("%s", (display_field[i][j] == 1) ? "〇" : ((display_field[i][j] == 0) ? "ー" : "×"));
				if (j != 2) {
					printf(" ");
				}
			}
			printf("　　　　|　　　　");
			for (int j = 0; j < N; j++) {
				printf("%s", (operate_field[i][j] == 1) ? "△" : "ー");
				if (j != 2) {
					printf(" ");
				}
			}
			printf("\n");
		}

		// 正常入力を期待して次回の入力を初回入力とする
		display_tutorial = FIRST_INPUT;

		// 入力を受け取る
		int key_operataor = _getch();
		if (((key_operataor == FOWARD) || (key_operataor == RIGHT)) || ((key_operataor == BACK) || (key_operataor == LEFT))) {
				int before_x = now_operator_x;
				int before_y = now_operator_y;
			if (Operate_Exception(key_operataor, operate_field, &now_operator_x, &now_operator_y)) {
				operate_field[before_y][before_x] = 0;
				operate_field[now_operator_y][now_operator_x] = 1;
			}
		}
		else if (key_operataor == DECISION) {
			// 入力可能かの判定
			if (display_field[now_operator_y][now_operator_x] == 0) {
				// どちらのプレイヤーの入力かの判定
				if (player_symbol == PLAYER_1) {
					display_field[now_operator_y][now_operator_x] = 1;
				}
				else {
					display_field[now_operator_y][now_operator_x] = -1;
				}
				//ゲーム終了判定
				if (isGameFinished(display_field)) {
					isgame_continue = FALSE;
				}
			}
			// エラー処理
			else {
				printf("そのマスは既に入力されています。再入力をお願いします。\n");
				display_tutorial = REINPUT;
			}
		}
	}
	return 0;
}

int main() {
	Input_OX("Yuki Nakajima", -1);
}