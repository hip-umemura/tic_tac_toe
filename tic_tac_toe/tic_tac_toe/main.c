#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tutorial.h"
#include "board.h"

TURN change_turn(TURN now){
	printf("先手と後手のターンを交代します");
	if (now == FIRST_TURN) {
		now = SECOND_TURN;
		return now;
	}
	else {
		now = SECOND_TURN;
		now = FIRST_TURN;
		return now;
	}
}

void print_result(RESULT result, PLAYER player) {
	if (result == DRAW) {
		printf("引き分け！");
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
		//printf("1");
		return TRUE;
	}
	else {
		//printf("0");
		return FALSE;
	}
}

// 三目並べ全体の処理
void game_progress(char* name1, char* name2) {

	PLAYER game_player1;				// 先手プレイヤー
	PLAYER game_player2;				// 後手プレイヤー
	PLAYER now_game_player;				// 現在のプレイヤー情報

	game_player1.name = name1;
	game_player1.piece = 'O';

	game_player2.name = name2;
	game_player2.piece = 'X';

	TURN player_game_turn = FIRST_TURN;					// プレイヤーのターン（初期値）

	RESULT game_result = NONE;							// ゲームの結果を格納する

	int  game_horizontal_axis = 0;							// 盤面の横軸（int型）
	int  game_vertical_axis   = 0;							// 盤面の縦軸（int型）
	char len_game_horizontal_axis[LEN_HORIZONTAL_AXIS];	// 盤面の横軸（char型）
	char len_game_vertical_axis[LEN_VERTICAL_AXIS];		// 盤面の縦軸（char型）

	clean_board();		// 盤面を初期化

	print_now_board();	// 盤面を表示

	while (game_result == NONE) {

		int error_count = 0;	// 不正な入力した場合にエラー文を出させる条件変数

		// 現在のプレイヤーを代入
		if (player_game_turn == FIRST_TURN) {
			now_game_player = game_player1;
		}
		else
		if (player_game_turn == SECOND_TURN) {
			now_game_player = game_player2;
		}

		// 盤面の座標を入力
		do {
			if (error_count > 0) {
				printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
			} 
			printf("%sさん、駒を置く座標を入力してください：", now_game_player.name);
			scanf_s("%s", len_game_horizontal_axis, 10);
			scanf_s("%s", len_game_vertical_axis, 10);
			error_count++;

			if ((isdigit(len_game_horizontal_axis[LEN_HORIZONTAL_AXIS - 1]) == 0) ||
				(isdigit(len_game_vertical_axis[LEN_VERTICAL_AXIS - 1]) == 0)) {

				continue;
			}

			game_horizontal_axis = atoi(len_game_horizontal_axis);
			printf("%d", game_horizontal_axis);
			game_vertical_axis   = atoi(len_game_vertical_axis);

		} while (((game_horizontal_axis < 1) || (game_horizontal_axis > 3)) ||
				 ((game_vertical_axis < 1) || (game_vertical_axis > 3)));

		// 盤面に駒が配置出来なかった場合の処理
		if (put_piece(game_horizontal_axis, game_vertical_axis, now_game_player) == FALSE) {
			continue;
		}

		print_now_board();						// 駒配置後、再度盤面を表示

		// ゲームの結果がNONE以外の処理
		if (judge_game() != NONE) {
			break;
		}
		player_game_turn = change_turn(player_game_turn);			//　現在のプレイヤー情報を入れ替える
	}
	print_result(game_result, now_game_player);	// ゲームの結果を表示する
}

int main(void) {
  int start_tutorial;
  char name1[NAME_LEN];
  char name2[NAME_LEN];
  int name_array;

  printf("チュートリアルを見ますか(YES...1 / NO...1以外)：");
  scanf_s("%d", &start_tutorial);
  fflush(stdin);

  if (start_tutorial == TRUE) {
	view_tutorial();
  }

  printf("ゲーム開始！");

  do{
	name_array = 0;

	printf("先手のプレイヤー名を入力してください：");
	scanf_s("%s", name1, NAME_LEN);

	do {
	  if (!islower(name1[name_array])) {
		printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
		break;
	  }
	  name_array++;
	} while (name1[name_array] != '\0');

	while (getchar() != '\n')
	  ;

  } while (name1[name_array] != '\0' || name_array == 0);

  do {
	name_array = 0;

	printf("後手のプレイヤー名を入力してください：");
	scanf_s("%s", name2, NAME_LEN);

	do {
	  if (!islower(name2[name_array])) {
		printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
		break;
	  }
	  name_array++;
	} while (name2[name_array] != '\0');

	while (getchar() != '\n')
	  ;

  } while (name2[name_array] != '\0' || name_array == 0);

  do
  {
	game_progress(name1, name2);
  } while (retry_game() == TRUE);

  printf("ゲーム終了！");

  return 0;
}