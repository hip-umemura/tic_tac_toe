#include <stdio.h>

#include "tic_tac_toe.h"
#include "game_start.h"
#include "game_playing.h"
#include "game_check.h"
#include "game_finish.h"

int main(void) {
	int operation_input = 0;					
	BOOL iscontinue_game = TRUE;
	char input_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y];
	char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y];

	//�v���C���[���i�[�̍\���̔z��
	PLAYER player_info[PLAYER_MEM] = {
		{.player_name = "", .turn = FIRST},
		{.player_name = "", .turn = FIRST}
	};

	InputName(&player_info);

	// �Q�[�����g���C�Ɋւ��郋�[�v
	while (iscontinue_game) {
		int player_turn = PLAYER_ONE;
		BOOL reinput = FALSE;
		char isgame_finished = 'F';

		for (int i = 0; i < BOARD_SIZE_X; i++) {
			//���͗p�Ֆʂ�'0',�\���p��1~9���
			for (int j = 0; j < BOARD_SIZE_Y; j++) {
				input_ox_board[i][j] = '0';
				display_ox_board[i][j] = '0' + ((i * BOARD_SIZE_X) + (j + 1));
			}
		}
		input_ox_board[1][1] = '1';

		player_turn = ChoiceFirstAttack(&player_info);

		// 1�Q�[���Ɋւ��郋�[�v
		do {
			reinput = FALSE;
			// ���͂Ɋւ��郋�[�v
			do {
				system("cls");
				ShowPlayer(player_info[player_turn]);
				ShowBoard(display_ox_board, input_ox_board);
				operation_input = Input();
				switch (operation_input) {
				case UP_KEY:
				case LEFT_KEY:
				case DOWN_KEY:
				case RIGHT_KEY:
					PlayerMove(&input_ox_board, operation_input);
					break;
				case ' ':
					if (MarkPosition(player_info[player_turn], input_ox_board, &display_ox_board)) {
						isgame_finished = ShowGameResult((GameDecision(display_ox_board, player_info[player_turn])), player_info);
						if (isgame_finished == 'D') {
							iscontinue_game = Retry_Game();
						}
						else {
							player_turn = ChangePlay(player_turn);
						}
					}
					else {
						printf("���̃}�X�͂��łɓ��͂���Ă��܂��B�ē��͂����肢���܂��B\n");
					}
					break;
				default:
					reinput = TRUE;
					// break;
				}
			} while (reinput);
		} while (isgame_finished == 'F');
	}
	return 0;
}