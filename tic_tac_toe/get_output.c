#include<stdio.h>
#include "define.h"
#include "get_output.h"

//�O�ڕ��ׂ̉�ʂ̃}�X�Ɂu�Z�v�u�~�v���o��
void PrintMark(int count, char game[], char(*game_board)[3]) {

	char mark = (count % 2 == 0) ? 'O' : 'X';

	int a = game[0];
	int b = game[1];

	if (game_board[a][b] == ' ') {
		game_board[a][b] = mark;
	}

	printf("  �Z�@��U\n");
	printf("  �~�@��U\n");

	printf("  ");
	for (int x = 1; x <= 3; x++) {
		printf("| %1d", x);
	}
	printf("|");
	printf("\n");
	for (int y = 0; y < 3; y++) {
		printf("% d|", y + 1);
		for (int x = 0; x < 3; x++) {
			printf("% 2c|", game_board[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}


//�꒼�������ׂāu�Z�v�A�܂��́u�~�v�ł���
WIN Bingo(char game_board[3][3], int count) {

	char mark = (count % 2 == 0) ? 'O' : 'X';

	for (int i = 0; i < 3; i++) {
		if (game_board[i][0] != ' ' && game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
			return (game_board[i][0] == mark) ? O_WIN : X_WIN;
		}
			
	}

	for (int j = 0; j < 3; j++) {
		if (game_board[0][j] != ' ' && game_board[0][j] == game_board[1][j] && game_board[1][j] == game_board[2][j]) {
			return (game_board[0][j] == mark) ? O_WIN : X_WIN;
		}
			
	}

	if (game_board[0][0] != ' ' && game_board[0][0] ==  game_board[1][1] && game_board[1][1] == game_board[2][2]) {
		return (game_board[0][0] == mark) ? O_WIN : X_WIN;
	}
	

	if (game_board[2][0] != ' ' && game_board[2][0] == game_board[1][1] && game_board[1][1] == game_board[0][2]) {
		return (game_board[2][0] == mark) ? O_WIN : X_WIN;
	}
	
	return UNKNOWN;

}

//������������
WIN SquareFull(int count) {

	int full = 0;

	if (count == CAPACITY_FULL) {
		full =  DROW;
	}
	else {
		full = UNKNOWN;
	}
	return full;
}