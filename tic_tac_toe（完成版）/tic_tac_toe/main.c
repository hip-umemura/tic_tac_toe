#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>
#include <assert.h>

#include "tutorial.h"
#include "board.h"

// 現在のプレイヤーの交代を行う
TURN change_turn(TURN now) {
	assert(now == FIRST_TURN || now == SECOND_TURN);
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

// 勝敗の表示を行う
void print_result(RESULT result, PLAYER player) {

	assert(result != NONE);

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
	while (getchar() != '\n')
	  ;

	if (userInput == '1') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// ゲーム全体の進行を行う。
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

	int   input_error;					// 入力エラーを表示する条件変数

	int   board_horizontal_axis;		// 入力した盤面の横軸
	int   board_vertical_axis;			// 入力した盤面の縦軸
	char  array_board_axis[4];			// 入力した盤面の軸

	clean_board();		// 盤面を初期化

	print_now_board();	// 盤面を表示

	// ゲームの勝敗が決するまでループする。
	while (game_result == NONE) {

		input_error = 0;
		board_horizontal_axis = 0;
		board_vertical_axis   = 0;

		// 現在のプレイヤーを代入
		if (player_game_turn == FIRST_TURN) {
			now_game_player = game_player1;
		} else {
			now_game_player = game_player2;
		}

		// 盤面の座標を入力
		do {

			printf("%sさん、駒を置く座標を入力してください：", now_game_player.name);
			scanf_s("%[^\n]s", array_board_axis, 4);
			while (getchar() != '\n');

			if (((isdigit(array_board_axis[0])!= 0) && (array_board_axis[1] == ' ')) && (isdigit(array_board_axis[2]) != 0)){
				input_error           = TRUE;
				board_horizontal_axis = array_board_axis[0] - '0';
				board_vertical_axis   = array_board_axis[2] - '0';
			} else {
				input_error = FALSE;
				printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
			} 
		} while (input_error != TRUE);

		// 入力された盤面の座標に駒を配置し、プレイヤーの交代を行う
		if (put_piece(board_horizontal_axis, board_vertical_axis, now_game_player) == TRUE) {

			print_now_board();				// 駒配置後、再度盤面を表示

			printf("駒を配置しました。\n");

			game_result = judge_game();		// ゲームの結果を代入

			if (game_result == NONE) {
				player_game_turn = change_turn(player_game_turn);	// 現在のプレイヤーを交代する
			}
		}
		else {
			printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
		}
	}
	print_result(game_result, now_game_player);	// ゲームの結果を表示する
}

int main(void) {

	int start_tutorial;
	char name[MEMBERS][NAME_LEN];
	int name_array;
	int player_count = 0;

	printf("チュートリアルを見ますか(YES...1 / NO...1以外)：");
	scanf_s("%d", &start_tutorial);
	while (getchar() != '\n');

	// チュートリアルを表示する
	if (start_tutorial == TRUE) {
		view_tutorial();
	}

	printf("ゲーム開始！\n");

	// プレイヤー名を入力
	do {
		do {
			name_array = 0;

			if (player_count == 0) {
				printf("先手のプレイヤー名を入力してください：");
			}
			else {
				printf("後手のプレイヤー名を入力してください：");
			}
			scanf_s("%s", name[player_count], NAME_LEN);
			do {
				if (((iswprint(name[player_count][name_array])) && (!iswcntrl(name[player_count][name_array])) &&
					(!iswascii(name[player_count][name_array]))) || (iswpunct(name[player_count][name_array]))) {
					printf("\x1b[31m半角英数字9字以内で入力してください！\x1b[39m\n");
					break;
				}
				name_array++;
			} while (name[player_count][name_array] != '\0');

			while (getchar() != '\n')
				;
		} while ((name[player_count][name_array] != '\0') || (name_array == 0));
		player_count++;
	} while (player_count != MEMBERS);

	// ゲームを始める
	do
	{
		game_progress(name[0], name[1]);
	} while (retry_game() == TRUE);

	printf("ゲーム終了！");

	return 0;
}
