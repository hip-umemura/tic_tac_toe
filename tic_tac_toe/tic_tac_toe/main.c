// ゲーム（三目並べ）全体を管理するファイル
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>

#include "tutorial.h"
#include "board.h"

// 現在のプレイヤーの交代を行う
TURN change_turn(TURN now) {
	printf("先手と後手のターンを交代します\n");

	if (now == FIRST_TURN) {
		now = SECOND_TURN;	// 先手→後手
		return now;
	}
	else {
		now = FIRST_TURN;	// 後手→先手
		return now;
	}
}

// 勝敗の表示を行う。
void print_result(RESULT result, PLAYER player) {
	if (result == DRAW) {
		printf("引き分け！\n");
	}
	else if (result == WIN) {
		printf("%sさんの勝利！\n", player.name);
	}
}

// ゲーム終了後、再度ゲームをプレイするか否か
int retry_game(void) {

	char userInput;	// プレイヤーが入力した値

	printf("再プレイしますか(YES...1 / No...1以外):");
	scanf_s("%c", &userInput, 1);

	if (userInput == '1') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// チュートリアルとプレイヤー名の入力終了後、ゲーム全体の進行を行う。
void game_progress(char* name1, char* name2)
{

	PLAYER game_player1;		// 先手のプレイヤー情報
	PLAYER game_player2;		// 後手のプレイヤー情報
	PLAYER now_game_player;		// 現在のプレイヤー情報

	game_player1.name = name1;
	game_player1.piece = 'O';

	game_player2.name = name2;
	game_player2.piece = 'X';

	TURN player_game_turn = FIRST_TURN;	// プレイヤーのターン（初期値）

	RESULT game_result = NONE;			// ゲームの結果（初期値）

	int  game_horizontal_axis;								// 盤面の横軸（int型）
	int  game_vertical_axis;								// 盤面の縦軸（int型）
	char len_game_horizontal_axis[LEN_HORIZONTAL_AXIS + 1];	// 盤面の横軸（char型）
	char len_game_vertical_axis[LEN_VERTICAL_AXIS + 1];		// 盤面の縦軸（char型）

	int error_count;	// 不正な入力した場合にエラー文を出させる条件式用変数

	clean_board();		// 盤面を初期化

	print_now_board();	// 盤面を表示

	// ゲームの勝敗が決するまでループする。
	while (game_result == NONE) {
		game_horizontal_axis = 0;
		game_vertical_axis   = 0;
		error_count          = 0;

		// 現在のプレイヤーを代入
		if (player_game_turn == FIRST_TURN) {
			now_game_player = game_player1;
		}
		else if (player_game_turn == SECOND_TURN) {
				now_game_player = game_player2;
			}

		// 盤面の座標を入力
		do {
			if (error_count > 0) {
				printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
			}

			printf("%sさん、駒を置く座標を入力してください：", now_game_player.name);
			scanf_s("%s", len_game_horizontal_axis, LEN_HORIZONTAL_AXIS + 1 );
			scanf_s("%s", len_game_vertical_axis, LEN_VERTICAL_AXIS + 1);
			while (getchar() != '\n');	// バッファをクリアにしている
			error_count++;

			// 入力された値が数字か数字以外か判断
			if ((isdigit(len_game_horizontal_axis[LEN_HORIZONTAL_AXIS - 1]) != 0) &&
				(isdigit(len_game_vertical_axis[LEN_VERTICAL_AXIS - 1]) != 0)) {
				game_horizontal_axis = atoi(len_game_horizontal_axis);
				game_vertical_axis = atoi(len_game_vertical_axis);
			}

		} while (((game_horizontal_axis < 1) || (game_horizontal_axis > 3)) ||
			((game_vertical_axis < 1) || (game_vertical_axis > 3)));

		// 入力された盤面の座標に駒を配置し、プレイヤーの交代を行う
		if (put_piece(game_horizontal_axis, game_vertical_axis, now_game_player) == TRUE) {

			print_now_board();				// 駒配置後、再度盤面を表示

			printf("駒を配置しました。\n");

			game_result = judge_game();		// ゲームの結果を代入

			if (game_result == NONE) {
				player_game_turn = change_turn(player_game_turn);	// 現在のプレイヤーを交代する
			}
		} else {
			printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
		}
	}
	print_result(game_result, now_game_player);	// ゲームの結果を表示する
}

int main(void) {

	int start_tutorial;		// チュートリアルを表示する条件変数
	char name1[NAME_LEN];	// 先手のプレイヤー名
	char name2[NAME_LEN];	// 後手のプレイヤー名
	int name_array;			// プレイヤー名の要素数

	printf("チュートリアルを見ますか(YES...1 / NO...1以外)：");
	scanf_s("%d", &start_tutorial);
	while (getchar() != '\n');

	// チュートリアルを表示する
	if (start_tutorial == TRUE) {
		view_tutorial();
	}

	printf("ゲーム開始！\n");

	// 先手のプレイヤー名を入力
	do {
		name_array = 0;

		printf("先手のプレイヤー名を入力してください：");
		scanf_s("%s", name1, NAME_LEN);

		do {
			if (((iswprint(name1[name_array])) && (!iswcntrl(name1[name_array])) &&
			  (!iswascii(name1[name_array]))) || (iswpunct(name1[name_array]))) {
				printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
				break;
			}
			name_array++;
		} while(name1[name_array] != '\0');

		while (getchar() != '\n')
			;

	} while ((name1[name_array] != '\0') || (name_array == 0));

	// 後手のプレイヤー名入力
	do {
		name_array = 0;

		printf("後手のプレイヤー名を入力してください：");
		scanf_s("%s", name2, NAME_LEN);

		do {
			if (((iswprint(name2[name_array])) && (!iswcntrl(name2[name_array])) && 
			  (!iswascii(name2[name_array]))) || (iswpunct(name2[name_array]))) {
				printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
				break;
			}
			name_array++;
		} while (name2[name_array] != '\0');

		while (getchar() != '\n')
			;

	} while (name2[name_array] != '\0' || name_array == 0);

	// プレイヤー名入力後、ゲームを行う
	do
	{
		game_progress(name1, name2);
	} while (retry_game() == TRUE);	// 再度ゲームを行うか否か

	printf("ゲーム終了！");

	return 0;
}
