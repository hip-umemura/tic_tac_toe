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
		// �v���C���[�̖��O�����
		printf("�v���C���[%d�̖��O�F", player_number);
		fgets(input_player_name, size, stdin);

		// ���͂����s�݂̂̏ꍇ
		if (input_player_name[0] == '\n') {
			printf("���O����͂��Ă�������\n");
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
				printf("���O�͔��p�p�����œ��͂��Ă�������\n");
				is_input_name_flag = FALSE;
#ifdef DEBUG
				printf("FALSE\n");
#endif // DEBUG
			}
			else if (strlen(input_player_name) > PLAYER_NAME_LENGTH) {
				printf("���O��15�����ȓ��œ��͂��Ă�������\n");
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


	// �Q�[���Ղ�������
	MARK board[SIDE_LONG][SIDE_LONG];
	for (int i = 0; i < SIDE_LONG; i++) {
		for (int j = 0; j < SIDE_LONG; j++) {
			board[i][j] = BLANK;
		}
	}

	// �Q�[���̏I����Ԃ̕ϐ�(result)���������A�Q�[���J�n���͖��I��(NONE)
	RESULT result = NONE;

	//���݂̎��
	TURN current_turn = PLAYER1_TURN;

	get_input_player_name(input_name_player1, sizeof(input_name_player1), 1);
	get_input_player_name(input_name_player2, sizeof(input_name_player2), 2);

	strncpy_s(player1_name, PLAYER_NAME_LENGTH + NULL_CHARACTER, input_name_player1, _TRUNCATE);
	strncpy_s(player2_name, PLAYER_NAME_LENGTH + NULL_CHARACTER, input_name_player2, _TRUNCATE);

	printf("%s����͐�U�A�}�[�N�́Z�ł�\n", player1_name);
	printf("%s����͌�U�A�}�[�N�́~�ł�\n", player2_name);

	do {
		//�}�X�̏�Ԃ�\��
		PrintBoard(board);

		//�ǂ��炩�̃v���C���[�����������𖞂����Ă��邩�̔���
		result = CheckBoard(board);
		if (result != NONE) {
			break;
		}

		//��ԃv���C���[�̖��O��\��
		if (current_turn == PLAYER1_TURN) {
			printf("%s����̃^�[��\n", player1_name);
		}
		else {
			printf("%s����̃^�[��\n", player2_name);
		}

		printf("�}�[�N���������ރ}�X�̔ԍ�����͂��Ă��������F");
		board_check_flag = FALSE;
		do {
			// �}�[�N���������ރ}�X�̔ԍ��̓���
			board_number = ScanInput();

			//���͂��ꂽ�}�X�Ƀ}�[�N���������܂�Ă��Ȃ���
			row = (board_number - 1) / SIDE_LONG;	//�s
			col = (board_number - 1) % SIDE_LONG;	//��

			if (board[row][col] == BLANK) {
				board_check_flag = TRUE;
			}
			else {
				printf("�}�[�N���������܂�Ă��Ȃ��}�X�ԍ�����͂��Ă��������F");
			}
		} while (board_check_flag == FALSE);

		//���͂��ꂽ�}�X�Ƀ}�[�N����������
		if (current_turn == PLAYER1_TURN) {
			board[row][col] = PLAYER1_MARK;
		}
		else {
			board[row][col] = PLAYER2_MARK;
		}


		//��Ԃ����
		if (current_turn == PLAYER1_TURN) {
			current_turn = PLAYER2_TURN;
		}
		else {
			current_turn = PLAYER1_TURN;
		}


	} while (result == NONE);

	//���ʂ�\������
	switch (result) {
	case PLAYER1_WIN:
		printf("%s����̏���\n", player1_name);
		break;
	case PLAYER2_WIN:
		printf("%s����̏���\n", player2_name);
		break;
	case DRAW:
		printf("���������ł�\n");
		break;
	default:
		printf("����Ȃ�\n");
		break;
	}

	return 0;
}