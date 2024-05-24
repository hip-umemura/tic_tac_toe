#pragma once

#include <stdio.h>
#include <conio.h>

#include"game_start.h"
#include"game_finish.c"
#include"game_playing.c"
#include"game_start.c"


#define PLAYER_MEM 2
#define NAME_SIZE 21
#define BOARD_SIZE_X 3
#define BOARD_SIZE_Y 3

int main(void) {

	int player_turn = PLAYER_ONE;//��ԕϐ�
	char input_board[BOARD_SIZE_X][BOARD_SIZE_Y];//���͗p�Ֆ�
	char display_board[BOARD_SIZE_X][BOARD_SIZE_Y]; //�\���p�Ֆ�

	//�v���C���[���i�[�̍\���̔z��
	PLAYER player_info[PLAYER_MEM] = {
		{.player_name = "", .turn = FIRST},
		{.player_name = "", .turn = FIRST}
	};

	for (int i = 0; i < BOARD_SIZE_X; i++) {
		//���͗p�Ֆʂ�'-',�\���p��1~9���
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			input_board[i][j] = '0';
			display_board[i][j] = '0' + ((i * BOARD_SIZE_X) + (j + 1));
		}
	}

	/* �ʒu����*/
	input_board[1][1] = '1';
	char show_result = "";

	InputName(player_info);
	do {
		ChoiceFirstAttack(&player_turn, player_info);
		do {
			int chose_position = "";//Input�֐��̓��͂��i�[����ϐ�			
			//system("cls");
			printf("�N���A\n");
			ShowPlayer(*( & player_info+player_turn));
			ShowBoard(display_board, input_board);
			chose_position = Input();
			if (chose_position == 'a' ||
				chose_position == 'w' ||
				chose_position == 's' ||
				chose_position == 'd') {
				PlayerMove(input_board,chose_position);
			}
			else if (Input() == ' ') {
				ChoicePosition(player_info[player_turn], input_board, display_board);
				show_result = ShowResult(GameDecision(display_board, player_info), player_info);
				if (show_result == 'F') {
					ChangePlay(player_turn);
				}

			}
			else
				continue;

		} while (show_result != 'D');
		Retry_Game();
	} while (Retry_Game() == TRUE); {

	}
}



//
//typedef enum  {FALSE,TRUE}BOOL;
//void InputName(PLAYER *player_info )
//{
//	printf("InputName\n");
//}
//void ChoiceFirstAttack(int *player_info,PLAYER *player_turn) {
//	printf("ChoiceFirstAttack\n");
//}
//
//void ShowPlayer(PLAYER player_info) {
//	printf("ShowPlayer\n");
//}
//
//void ShowBoard(char display_board, char input_board) {
//	printf("ShowBoard\n");
//
//}
//
//int Input()
//{
//	int a;
//	a = _getch();
//	printf("Input���͂��āAwasd��%c\n",a);
//	
//	
//	return a;
//}
//
//void PlayerMove(char *a)
//{
//	printf("PlayerMove\n");
//
//}
//
//void ChoicePosition(PLAYER player_info, char a, char b) {
//	printf("ChoicePosition\n");
//}
//
//char GameDecision(char a, PLAYER player_info[]) {
//	char b;
//	printf("GameDecision���͂��āAO,X,D,F\n");
//	scanf_s("%c",&b);
//	return b;
//}
//
//char ShowResult(char a,PLAYER b[]) {
//	char c;
//	printf("ShowResult�AF,D���͂���\n");
//	scanf_s("%c", &c);
//	return c;
//}
//
//int ChangePlay(int a) {
//	int p = a;
//	printf("ChangePlay\n");
//	if (a == 1)
//		p = PLAYER_ONE;
//	else
//		p = PLAYER_TWO;
//	return p;
//}
//
//int Retry_Game() {
//
//	int  a;
//	printf("Retry_Game���͂���0�Ȃ�I���\n");
//	a = _getch();
//	if (a == 0)
//		return FALSE;
//	else
//		return TRUE;
//}


