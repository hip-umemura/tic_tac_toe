#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "board_func.h"
#define PLAYER_NAME (15) // プレイヤーが入力可能な名前の文字数
#define NAME_INPUT_SIZE (PLAYER_NAME + 2)  // 入力可能な名前の文字数 + 文字数越えエラー判定用文字 + NULL文字
#define NUM_OF_PLAYERS (2)  // ゲームを遊ぶ人数
#define HALF_WIDTH_ALPHANUMERIC(input_char) (((L'0' <= input_char) && (input_char <= L'9')) || ((L'A' <= input_char) && (input_char <= L'Z')) || ((L'a' <= input_char) && (input_char <= L'z')))  // input_charは半角英数字か

typedef enum {
	PLAYER1_TURN,
	PLAYER2_TURN,
} TURN;

int IsFullHalfWidth(wchar_t c) {
	if (c < 0) {
		return -1;  // エラーコード
	}
	else if (c < 0x100) {
		return 0;  // 半角文字
	}
	else {
		return 1;  // 全角文字
	}
}

int CountFullWidth(wchar_t* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (IsFullHalfWidth(str[i]) == 1) {
			count++;
		}
	}
	return count;
}

int CountHalfWidth(wchar_t* str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (IsFullHalfWidth(str[i]) == 0) {
			count++;
		}
	}
	return count;
}

void InputPlayerName(wchar_t *player_name, int size, int player_number) {
	int no_error_flag = FALSE;
	do
	{
		int all_char_count = 0;
		int full_char_count = 0;
		int hulf_char_count = 0;
		no_error_flag = TRUE;
		printf("プレイヤー%dの名前：", player_number);
		fgetws(player_name, size, stdin);

		if (player_name[0] == L'\n') {
			printf("名前を入力してください\n");
			no_error_flag = FALSE;
		}
		
		if (player_name[(wcslen(player_name)) - 1] == L'\n') {
			player_name[(wcslen(player_name)) - 1] = L'\0';         // 改行文字をNULL文字で置き換える
		}
		else {                                                  // 改行文字が含まれていない場合、入力バッファをクリアする
			int clear_buffer;
			clear_buffer = getchar();
			while (clear_buffer != L'\n') {
				clear_buffer = getchar();
			}
		}

		full_char_count = CountFullWidth(player_name);
		hulf_char_count = CountHalfWidth(player_name);
		all_char_count = full_char_count + hulf_char_count;
		
		if ((no_error_flag == TRUE) && (PLAYER_NAME < all_char_count)) {
			printf("名前は%d文字以内で入力してください\n", PLAYER_NAME);
			no_error_flag = FALSE;
		}
		else {
			int i = 0;
			while (player_name[i] != L'\0') {
				wchar_t is_half_width = player_name[i];
				if (HALF_WIDTH_ALPHANUMERIC(is_half_width)) {  // 半角英数字か
					no_error_flag = TRUE;
				}
				else {
					printf("名前は半角英数字で入力してください\n");
					no_error_flag = FALSE;
					break;
				}
				++i;
			}
		}
	} while (no_error_flag == FALSE);
}

int SearchToChangeBoard(int input_num, TURN turn, MARK board[BOARD_CELL][BOARD_CELL]) {
	int board_place_num = 0;
	for (int i = 0; i < BOARD_CELL; i++) {
		for (int j = 0; j < BOARD_CELL; j++) {
			board_place_num++;
			if (input_num == board_place_num) {  // ScanInputからboardの場所を検索
				switch (board[i][j])
				{
				case BLANK:  // boardに手番のプレイヤー「PLAYER1_MARK」、「PLAYER2_MARK」を入れる
					if (turn == PLAYER1_TURN) {
						board[i][j] = PLAYER1_MARK;
						return TRUE;
						break;
					}
					else {
						board[i][j] = PLAYER2_MARK;
						return TRUE;
						break;
					}
				default:
					printf("マークが書き込まれていないマス番号を入力してください：");  // マークが書いてある場所はエラー
					return FALSE;
					break;
				}
			}
		}
	}
}

int main(void) {
	MARK board[BOARD_CELL][BOARD_CELL];
	for (int i = 0; i < BOARD_CELL; i++) {
		for (int j = 0; j < BOARD_CELL; j++) {
			board[i][j] = BLANK;
		}
	}
	RESULT result = NONE;
	TURN turn = PLAYER1_TURN;
	wchar_t player1_name[NAME_INPUT_SIZE];
	wchar_t player2_name[NAME_INPUT_SIZE];
	int player_input_num;
	int no_error_flag = FALSE;
	int play_end_flag = FALSE;
	int search_board_flag = FALSE;

	if (setlocale(LC_CTYPE, "japanese") == NULL) {  // LC_CTYPE をjapaneseに変更
		fputs("ロケールの設定に失敗しました。\n", stderr);
		return EXIT_FAILURE;
	}

	InputPlayerName(player1_name, NAME_INPUT_SIZE, 1);  // InputPlayerName(名前を格納する配列, サイズ,プレイヤーの番号)
	InputPlayerName(player2_name, NAME_INPUT_SIZE, 2);

	wprintf(L"%lsさんは先攻、マークは〇です\n", player1_name);
	wprintf(L"%lsさんは後攻、マークは×です\n", player2_name);

	do {
		PrintBoard(board); // マス表示
		result = CheckBoard(board);  // 終了判定
		if (result == NONE) {

			if (turn == PLAYER1_TURN) {
				wprintf(L"%lsさんのターン\n", player1_name);  // 誰のターンか表示
			}
			else {
				wprintf(L"%lsさんのターン\n", player2_name);  // 誰のターンか表示
			}

			printf("マークを書き込むマスの番号を入力してください：");

			do {
				player_input_num = ScanInput();
				search_board_flag = SearchToChangeBoard(player_input_num, turn, board);
			} while (search_board_flag == FALSE);

			if (turn == PLAYER1_TURN) {  // 手番の交代
				turn = PLAYER2_TURN;
			}
			else {
				turn = PLAYER1_TURN;
			}

			play_end_flag = FALSE;
		}
		else {
			switch (result)  // 結果表示
			{
			case PLAYER1_WIN:  // プレイヤー1の勝利
				wprintf(L"%sさんの勝利", player1_name);
				break;
			case PLAYER2_WIN:  // プレイヤー2の勝利
				wprintf(L"%sさんの勝利", player2_name);
				break;
			case DRAW:  // 引き分け
				printf("引き分けです");
				break;
			default:
				break;
			}
			play_end_flag = TRUE;
		}
	} while (play_end_flag == FALSE);

	return 0;
}