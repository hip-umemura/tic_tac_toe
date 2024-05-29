#include "display.h"

GAME_CONTINUE_INSTRUCTION Show_GameTitle(void) {
	Show_Headder(TITLE, VERSION);
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf("|                               %s                               |\n", TITLE);
	printf("|                                                                            |\n");
	printf("|                            Press Y to Start Game                           |\n");
	printf("|                            Press N to Exit  Game                           |\n");
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf(" ---------------------------------------------------------------------------- \n");
	GAME_CONTINUE_INSTRUCTION continue_instruction = RE_INPUT;
	while (continue_instruction == RE_INPUT) {
		continue_instruction = isGameStart(Get_Input());
		system("cls");
		if (continue_instruction == GAME_END) {
			continue_instruction = GAME_END;
			return continue_instruction;
		}
		else {
			if (continue_instruction == GAME_START) {
				continue_instruction = GAME_START;
				return continue_instruction;
			}
			else {
				continue_instruction = RE_INPUT;
			}
		}
	}
}

int Show_ExitGame(void) {
	int check_game_end = 0;
	Show_Headder(TITLE, VERSION);
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf("|                            本当に終了しますか？                            |\n");
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf("|                            はい : Y   いいえ : N                           |\n");
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
    printf("|                                                                            |\n");
	printf(" ---------------------------------------------------------------------------- \n");
	check_game_end = Get_Input();
	system("cls");
	return check_game_end;
}

void Show_GameInfo(int player_info,int* board) {
	printf("|                                                                            |\n");
	printf("|  -----現在の盤面-----   |     -----------------ルール-----------------     |\n");
	printf("|     -------------       |     1. 終了条件                                  |\n");

	printf("|     ");
	for (int i = ZHU_SIZE * 2; i < ZHU_SIZE*ZHU_SIZE; i++) {
	  if (board[i] == PLAYER1_MARK || board[i] == PLAYER2_MARK) {
		printf("| %c ", board[i]);
	  } else {
		printf("| %d ", i + 1);
	  }
	}
	printf("|       |        一列・一行・斜めにoかxが揃うと勝ち        | \n");

	printf("|     -------------       |        9マス全て揃い勝者がいなければ引き分け     |\n");

	printf("|     ");
	for (int i = ZHU_SIZE * 1; i < ZHU_SIZE*(ZHU_SIZE-1); i++) {
	  if (board[i] == PLAYER1_MARK || board[i] == PLAYER2_MARK) {
		printf("| %c ", board[i]);
	  }
	  else {
		printf("| %d ", i + 1);
	  }
	}
	printf("|       |                                                  |\n");

	printf("|     -------------       |     2. 入力方法                                  |\n");

	printf("|     ");
	for (int i = 0; i < ZHU_SIZE; i++) {
	  if (board[i] == PLAYER1_MARK || board[i] == PLAYER2_MARK) {
		printf("| %c ", board[i]);
	  }
	  else {
		printf("| %d ", i + 1);
	  }
	}
	printf("|       |        左のマスの数字を入力してください          | \n");

	printf("|     -------------       |        oとxが入っているマスは既に入力済みです    |\n");
	printf("|                                                                            |\n");
	printf("|                                                                            |\n");
	printf(" ---------------------------------------------------------------------------- \n");
	switch (player_info) {
	case PLAYER1:
		printf("\nプレイヤー1 ( o )の入力 : ");
		break;
	case PLAYER2:
		printf("\nプレイヤー2 ( x )の入力 : ");
		break;
	}
}

void Show_GameResult(SHOW_RESULT_INSTRUCTION result_instruction, int* board) {
	char game_result[STR_SIZE] = "";
	int back_title = 0;
	if (result_instruction == GAME_DRAW) {
		strcpy_s(game_result, STR_SIZE, "        引き分け        ");
	}
	else {
		if (result_instruction == GAME_WIN_1) {
			strcpy_s(game_result, STR_SIZE, "プレイヤー1 ( o ) の勝利");
		}
		else if (result_instruction == GAME_WIN_2) {
			strcpy_s(game_result, STR_SIZE, "プレイヤー2 ( x ) の勝利");
		}
	}
	while (back_title != '\r') {
		Show_Headder(TITLE, VERSION);
		printf("|                                                                            |\n");
		printf("|  -----現在の盤面-----   |                                                  |\n");
		printf("|     -------------       |                                                  |\n");
		printf("|     | %c | %c | %c |       |                                                  |\n",
		  (board[6] == 0 ? ' ' : board[6]), (board[7] == 0 ? ' ' : board[7]), (board[8] == 0 ? ' ' : board[8]));
		printf("|     -------------       |                %s          |\n", game_result);
		printf("|     | %c | %c | %c |       |                                                  |\n",
		  (board[3] == 0 ? ' ' : board[3]), (board[4] == 0 ? ' ' : board[4]), (board[5] == 0 ? ' ' : board[5]));
		printf("|     -------------       |               Press Enter to back Title          |\n");
		printf("|     | %c | %c | %c |       |                                                  |\n",
		  (board[0] == 0 ? ' ' : board[0]), (board[1] == 0 ? ' ' : board[1]), (board[2] == 0 ? ' ' : board[2]));
		printf("|     -------------       |                                                  |\n");
		printf("|                                                                            |\n");
		printf("|                                                                            |\n");
		printf(" ---------------------------------------------------------------------------- \n");
		back_title = Get_Input();
		system("cls");
	}
}

