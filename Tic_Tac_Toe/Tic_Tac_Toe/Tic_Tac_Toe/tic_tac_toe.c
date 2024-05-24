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

	int player_turn = PLAYER_ONE;//手番変数
	char input_board[BOARD_SIZE_X][BOARD_SIZE_Y];//入力用盤面
	char display_board[BOARD_SIZE_X][BOARD_SIZE_Y]; //表示用盤面

	//プレイヤー情報格納の構造体配列
	PLAYER player_info[PLAYER_MEM] = {
		{.player_name = "", .turn = FIRST},
		{.player_name = "", .turn = FIRST}
	};

	for (int i = 0; i < BOARD_SIZE_X; i++) {
		//入力用盤面に'-',表示用に1~9代入
		for (int j = 0; j < BOARD_SIZE_Y; j++) {
			input_board[i][j] = '0';
			display_board[i][j] = '0' + ((i * BOARD_SIZE_X) + (j + 1));
		}
	}

	/* 位置注意*/
	input_board[1][1] = '1';
	char show_result = "";

	InputName(player_info);
	do {
		ChoiceFirstAttack(&player_turn, player_info);
		do {
			int chose_position = "";//Input関数の入力を格納する変数			
			//system("cls");
			printf("クリア\n");
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
//	printf("Input入力して、wasd空白%c\n",a);
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
//	printf("GameDecision入力して、O,X,D,F\n");
//	scanf_s("%c",&b);
//	return b;
//}
//
//char ShowResult(char a,PLAYER b[]) {
//	char c;
//	printf("ShowResult、F,D入力して\n");
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
//	printf("Retry_Game入力して0なら終わり\n");
//	a = _getch();
//	if (a == 0)
//		return FALSE;
//	else
//		return TRUE;
//}


