#include <stdio.h>
#include <ctype.h>

#include "tutorial.h"
#include "board.h"

TURN change_turn(TURN now){
	printf("先手と後手のターンを交代します")
	if (now == FIRST_TURN) {
		return SECOND_TURN;
	}
	else {
		return FIRST_TURN;
	}
}

void print_result(RESULT result) {
	if (result == DRAW) {
		printf("引き分け！");
	}
	else if (result == WIN) {
		print("%pさんの勝利！\n, player");
	}
}

int retry_game(void) {
	char userInput;
	printf("再プレイしま'すか(YES...1 / No...1以外):");
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

void game_progress(char* name1, char* name2) {

	PLAYER game_player_name1;				// 先攻プレイヤー名
	PLAYER game_player_name2;				// 後攻プレイヤー名

	TURN player_game_turn = FIRST_TURN;		// 先攻プレイヤーのターン（初期値）

	RESULT game_result = NONE;						// ゲームの結果を格納する

	// 先攻プレイヤー
	game_player_name1.name  = name1;
	game_player_name1.piece = 'O';

	// 後攻プレイヤー
	game_player_name2.name  = name2;
	game_player_name2.piece = 'X';

	first_game_turn  = FIRST_TURN;

	clean_board();

	print_now_board();

	printf("%sさん、駒を置く座標を入力してください：");
	scanf("%d", )
	scanf()
	put_piece(int row, int column, PLAYER player);

	judge_game();

	change_turn(TURN now);

	print_result(RESULT result, PLAYER player);
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

  return 0;
}