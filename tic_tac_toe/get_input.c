#include <stdio.h>
#include "define.h"


//�c���̃}�X�������
void SquareNumber(int count, char *game) {

	if (count % 2 == 0) {
		printf("�Z�̔Ԃł�\n");
	}
	else {
		printf("�~�̔Ԃł�\n");
	}

	printf("�c�̒l�𔼊p��1�`3�̐����l�œ��͂��Ă��������F");
	scanf_s(" %c", &game[0], 1);
	
	printf("���̒l�𔼊p��1�`3�̐����l�œ��͂��Ă��������F");
	scanf_s(" %c", &game[1], 1);
	
}

//���͂����l�͋K��l����
BOOL NumRange(char game[]) {

	int range = 0;

	if (isdigit(game[0]) == 0 || isdigit(game[1]) == 0) {
		printf("�����l����͂��Ă��������B\n");
		return range = FALSE;
	}
	
	game[0] -= '1';
	game[1] -= '1';

	if (game[0] < 0 || game[0] > 3 || game[1] < 0 || game[1] > 3) {
		printf("�����l����͂��Ă��������B\n");
		range =  FALSE;
	}

	range = TRUE;

	return range;

}

//���ɓ��͂���Ă��Ȃ���
BOOL MarkChecker(char game_board[3][3],char game[]) {

	int a = game[0];
	int b = game[1]; 
	int checker = 0;


	if (game_board[a][b] != ' ') {
		printf("���͍ς݂̃}�X�ł��B���̃}�X��I��ł��������B\n");
		checker = FALSE;
	}
	checker = TRUE;

	return checker;

}
