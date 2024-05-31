#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "board_func.h"
#define PLAYER_NAME (15) // �v���C���[�����͉\�Ȗ��O�̕�����
#define NAME_INPUT_SIZE (PLAYER_NAME + 2)  // ���͉\�Ȗ��O�̕����� + �������z���G���[����p���� + NULL����
#define NUM_OF_PLAYERS (2)  // �Q�[����V�Ԑl��
#define HALF_WIDTH_ALPHANUMERIC(input_char) (((L'0' <= input_char) && (input_char <= L'9')) || ((L'A' <= input_char) && (input_char <= L'Z')) || ((L'a' <= input_char) && (input_char <= L'z')))  // input_char�͔��p�p������

typedef enum {
	PLAYER1_TURN,
	PLAYER2_TURN,
} TURN;

int IsFullHalfWidth(wchar_t c) {
	if (c < 0) {
		return -1;  // �G���[�R�[�h
	}
	else if (c < 0x100) {
		return 0;  // ���p����
	}
	else {
		return 1;  // �S�p����
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
		printf("�v���C���[%d�̖��O�F", player_number);
		fgetws(player_name, size, stdin);

		if (player_name[0] == L'\n') {
			printf("���O����͂��Ă�������\n");
			no_error_flag = FALSE;
		}
		
		if (player_name[(wcslen(player_name)) - 1] == L'\n') {
			player_name[(wcslen(player_name)) - 1] = L'\0';         // ���s������NULL�����Œu��������
		}
		else {                                                  // ���s�������܂܂�Ă��Ȃ��ꍇ�A���̓o�b�t�@���N���A����
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
			printf("���O��%d�����ȓ��œ��͂��Ă�������\n", PLAYER_NAME);
			no_error_flag = FALSE;
		}
		else {
			int i = 0;
			while (player_name[i] != L'\0') {
				wchar_t is_half_width = player_name[i];
				if (HALF_WIDTH_ALPHANUMERIC(is_half_width)) {  // ���p�p������
					no_error_flag = TRUE;
				}
				else {
					printf("���O�͔��p�p�����œ��͂��Ă�������\n");
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
			if (input_num == board_place_num) {  // ScanInput����board�̏ꏊ������
				switch (board[i][j])
				{
				case BLANK:  // board�Ɏ�Ԃ̃v���C���[�uPLAYER1_MARK�v�A�uPLAYER2_MARK�v������
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
					printf("�}�[�N���������܂�Ă��Ȃ��}�X�ԍ�����͂��Ă��������F");  // �}�[�N�������Ă���ꏊ�̓G���[
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

	if (setlocale(LC_CTYPE, "japanese") == NULL) {  // LC_CTYPE ��japanese�ɕύX
		fputs("���P�[���̐ݒ�Ɏ��s���܂����B\n", stderr);
		return EXIT_FAILURE;
	}

	InputPlayerName(player1_name, NAME_INPUT_SIZE, 1);  // InputPlayerName(���O���i�[����z��, �T�C�Y,�v���C���[�̔ԍ�)
	InputPlayerName(player2_name, NAME_INPUT_SIZE, 2);

	wprintf(L"%ls����͐�U�A�}�[�N�́Z�ł�\n", player1_name);
	wprintf(L"%ls����͌�U�A�}�[�N�́~�ł�\n", player2_name);

	do {
		PrintBoard(board); // �}�X�\��
		result = CheckBoard(board);  // �I������
		if (result == NONE) {

			if (turn == PLAYER1_TURN) {
				wprintf(L"%ls����̃^�[��\n", player1_name);  // �N�̃^�[�����\��
			}
			else {
				wprintf(L"%ls����̃^�[��\n", player2_name);  // �N�̃^�[�����\��
			}

			printf("�}�[�N���������ރ}�X�̔ԍ�����͂��Ă��������F");

			do {
				player_input_num = ScanInput();
				search_board_flag = SearchToChangeBoard(player_input_num, turn, board);
			} while (search_board_flag == FALSE);

			if (turn == PLAYER1_TURN) {  // ��Ԃ̌��
				turn = PLAYER2_TURN;
			}
			else {
				turn = PLAYER1_TURN;
			}

			play_end_flag = FALSE;
		}
		else {
			switch (result)  // ���ʕ\��
			{
			case PLAYER1_WIN:  // �v���C���[1�̏���
				wprintf(L"%s����̏���", player1_name);
				break;
			case PLAYER2_WIN:  // �v���C���[2�̏���
				wprintf(L"%s����̏���", player2_name);
				break;
			case DRAW:  // ��������
				printf("���������ł�");
				break;
			default:
				break;
			}
			play_end_flag = TRUE;
		}
	} while (play_end_flag == FALSE);

	return 0;
}