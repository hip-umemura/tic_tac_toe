﻿#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>

#include "tutorial.h"
#include "board.h"

TURN change_turn(TURN now) {
	printf("先手と後手のターンを交代します\n");
	if (now == FIRST_TURN) {
		now = SECOND_TURN;
		return now;
	}
	else {
		now = FIRST_TURN;
		return now;
	}
}

void print_result(RESULT result, PLAYER player) {
	if (result == DRAW) {
		printf("引き分け！\n");
	}
	else if (result == WIN) {
		printf("%sさんの勝利！\n", player.name);
	}
}

int retry_game(void) {
	char userInput;
	printf("再プレイしますか(YES...1 / No...1以外):");
	scanf_s("%c", &userInput, 1);
	if (userInput == '1') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// 三目並べ全体の処理
void game_progress(char* name1, char* name2)
{
	PLAYER game_player1;				// 先手プレイヤー
	PLAYER game_player2;				// 後手プレイヤー
	PLAYER now_game_player;				// 現在のプレイヤー

	game_player1.name = name1;
	game_player1.piece = 'O';

	game_player2.name = name2;
	game_player2.piece = 'X';

	TURN player_game_turn = FIRST_TURN;					// プレイヤーのターン（初期値）

	RESULT game_result = NONE;							// ゲームの結果を格納する

	int  game_horizontal_axis;						// 盤面の横軸（int型）
	int  game_vertical_axis;						// 盤面の縦軸（int型）
	char len_game_horizontal_axis[LEN_HORIZONTAL_AXIS + 1];	// 盤面の横軸（char型）
	char len_game_vertical_axis[LEN_VERTICAL_AXIS + 1];		// 盤面の縦軸（char型）

	int error_count;

	clean_board();		// 盤面を初期化

	print_now_board();	// 盤面を表示

	while (game_result == NONE) {
		game_horizontal_axis = 0;
		game_vertical_axis = 0;
		error_count = 0;	// 不正な入力した場合にエラー文を出させる条件変数

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
			scanf_s("%s ", len_game_horizontal_axis, LEN_HORIZONTAL_AXIS + 1);
			scanf_s("%s", len_game_vertical_axis, LEN_VERTICAL_AXIS + 1);
			error_count++;

			if ((isdigit(len_game_horizontal_axis[LEN_HORIZONTAL_AXIS - 1]) != 0) &&
				(isdigit(len_game_vertical_axis[LEN_VERTICAL_AXIS - 1]) != 0)) {
				game_horizontal_axis = atoi(len_game_horizontal_axis);
				game_vertical_axis = atoi(len_game_vertical_axis);
			}

		} while (((game_horizontal_axis < 1) || (game_horizontal_axis > 3)) ||
			((game_vertical_axis < 1) || (game_vertical_axis > 3)));

		if (put_piece(game_horizontal_axis, game_vertical_axis, now_game_player) == TRUE) {

			print_now_board();									// 駒配置後、再度盤面を表示

			printf("駒を配置しました。\n");

			game_result = judge_game();							// ゲームの結果を代入

			if (game_result == NONE) {
				player_game_turn = change_turn(player_game_turn);//　現在のプレイヤー情報を入れ替える
			}
		}
		else {
			printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
		}
	}
	print_result(game_result, now_game_player);					// ゲームの結果を表示する
}

int main(void) {
	int start_tutorial;
	char name[PLAYERS][NAME_LEN];
	int name_array;
	int player_count = 0;

	printf("チュートリアルを見ますか(YES...1 / NO...1以外)：");
	scanf_s("%d", &start_tutorial);
	while (getchar() != '\n')
	  ;

	if (start_tutorial == TRUE) {
		view_tutorial();
	}

	printf("ゲーム開始！\n");

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
			printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
			break;
		  }
		  name_array++;
		} while (name[player_count][name_array] != '\0');

		while (getchar() != '\n')
		  ;

	  } while ((name[player_count][name_array] != '\0') || (name_array == 0));
	  player_count++;
	} while (player_count != PLAYERS);

	do
	{
		game_progress(name[0], name[1]);
		while (getchar() != '\n')
		  ;
	} while (retry_game() == TRUE);

	printf("ゲーム終了！");

	return 0;
}
