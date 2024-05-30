#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "board_func.h"

#define PLAYER_NAME_LENGTH (15)
#define NULL_CHARACTER (1)
#define ADD_CHARCTER_BYTE (1)
#define ADD_ERROR_CHECK_EXTRA_BYTE (1)
#define INPUT_NAME_SIZE (PLAYER_NAME_LENGTH + ADD_CHARCTER_BYTE + ADD_ERROR_CHECK_EXTRA_BYTE)
typedef enum
{
	PLAYER1_TURN,
	PLAYER2_TURN
} TURN;

int isHalf_width_alphanumeric(const char* name) {
	for (int i = 0; i < strlen(name); i++) {
		if (!(('a' <= name[i] && name[i] <= 'z') || ('A' <= name[i] && name[i] <= 'Z') || ('0' <= name[i] && name[i] <= '9'))) {
			return FALSE;
		}
	}
	return TRUE;
}


void get_input_player_name(char* input_player_name, size_t size, int player_number) {
	int is_input_name_flag = FALSE;

	do {
		// プレイヤーの名前を入力
		printf("プレイヤー%dの名前：", player_number);
		fgets(input_player_name, size, stdin);

		// 入力が改行のみの場合
		if (input_player_name[0] == '\n') {
			printf("名前を入力してください\n");
			is_input_name_flag = FALSE;
#ifdef DEBUG
			printf("FALSE\n");
#endif // DEBUG
		}
		else {
			if (input_player_name[strlen(input_player_name) - 1] == '\n') {
				input_player_name[strlen(input_player_name) - 1] = '\0';
			}
			else {
				int character;
				character = getchar();
				while (character != '\n') {
					character = getchar();
				}
			}
			if (isHalf_width_alphanumeric(input_player_name) == FALSE) {
				printf("名前は半角英数字で入力してください\n");
				is_input_name_flag = FALSE;
#ifdef DEBUG
				printf("FALSE\n");
#endif // DEBUG
			}
			else if (strlen(input_player_name) > PLAYER_NAME_LENGTH) {
				printf("名前は15文字以内で入力してください\n");
				is_input_name_flag = FALSE;
#ifdef DEBUG
				printf("FALSE\n");
#endif // DEBUG
			}
			else {
				is_input_name_flag = TRUE;
#ifdef DEBUG
				printf("TRUE\n");
#endif // DEBUG
			}
		}
	} while (is_input_name_flag == FALSE);
}

int main(void) {

	char player1_name[PLAYER_NAME_LENGTH + NULL_CHARACTER];
	char player2_name[PLAYER_NAME_LENGTH + NULL_CHARACTER];
	char input_name_player1[INPUT_NAME_SIZE];
	char input_name_player2[INPUT_NAME_SIZE];
	int is_input_name_flag = FALSE;
	int board_number;
	int board_check_flag = FALSE;
	int row, col;


	// ゲーム盤を初期化
	MARK board[SIDE_LONG][SIDE_LONG];
	for (int i = 0; i < SIDE_LONG; i++) {
		for (int j = 0; j < SIDE_LONG; j++) {
			board[i][j] = BLANK;
		}
	}

	// ゲームの終了状態の変数(result)を初期化、ゲーム開始時は未終了(NONE)
	RESULT result = NONE;

	//現在の手番
	TURN current_turn = PLAYER1_TURN;

	get_input_player_name(input_name_player1, sizeof(input_name_player1), 1);
	get_input_player_name(input_name_player2, sizeof(input_name_player2), 2);

	strncpy_s(player1_name, PLAYER_NAME_LENGTH + NULL_CHARACTER, input_name_player1, _TRUNCATE);
	strncpy_s(player2_name, PLAYER_NAME_LENGTH + NULL_CHARACTER, input_name_player2, _TRUNCATE);

	printf("%sさんは先攻、マークは〇です\n", player1_name);
	printf("%sさんは後攻、マークは×です\n", player2_name);

	do {
		//マスの状態を表示
		PrintBoard(board);

		//どちらかのプレイヤーが勝利条件を満たしているかの判定
		result = CheckBoard(board);
		if (result != NONE) {
			break;
		}

		//手番プレイヤーの名前を表示
		if (current_turn == PLAYER1_TURN) {
			printf("%sさんのターン\n", player1_name);
		}
		else {
			printf("%sさんのターン\n", player2_name);
		}

		printf("マークを書き込むマスの番号を入力してください：");
		board_check_flag = FALSE;
		do {
			// マークを書き込むマスの番号の入力
			board_number = ScanInput();

			//入力されたマスにマークが書き込まれていないか
			row = (board_number - 1) / SIDE_LONG;	//行
			col = (board_number - 1) % SIDE_LONG;	//列

			if (board[row][col] == BLANK) {
				board_check_flag = TRUE;
			}
			else {
				printf("マークが書き込まれていないマス番号を入力してください：");
			}
		} while (board_check_flag == FALSE);

		//入力されたマスにマークを書き込む
		if (current_turn == PLAYER1_TURN) {
			board[row][col] = PLAYER1_MARK;
		}
		else {
			board[row][col] = PLAYER2_MARK;
		}


		//手番を交代
		if (current_turn == PLAYER1_TURN) {
			current_turn = PLAYER2_TURN;
		}
		else {
			current_turn = PLAYER1_TURN;
		}


	} while (result == NONE);

	//結果を表示する
	switch (result) {
	case PLAYER1_WIN:
		printf("%sさんの勝利\n", player1_name);
		break;
	case PLAYER2_WIN:
		printf("%sさんの勝利\n", player2_name);
		break;
	case DRAW:
		printf("引き分けです\n");
		break;
	default:
		printf("判定なし\n");
		break;
	}

	return 0;
}