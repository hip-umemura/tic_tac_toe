#include <stdio.h>
#include "define.h"


//縦横のマス数を入力
void SquareNumber(int count, char *game) {

	if (count % 2 == 0) {
		printf("〇の番です\n");
	}
	else {
		printf("×の番です\n");
	}

	printf("縦の値を半角で1～3の整数値で入力してください：");
	scanf_s(" %c", &game[0], 1);
	
	printf("横の値を半角で1～3の整数値で入力してください：");
	scanf_s(" %c", &game[1], 1);
	
}

//入力した値は規定値内か
BOOL NumRange(char game[]) {

	int range = 0;

	if (isdigit(game[0]) == 0 || isdigit(game[1]) == 0) {
		printf("整数値を入力してください。\n");
		return range = FALSE;
	}
	
	game[0] -= '1';
	game[1] -= '1';

	if (game[0] < 0 || game[0] > 3 || game[1] < 0 || game[1] > 3) {
		printf("整数値を入力してください。\n");
		range =  FALSE;
	}

	range = TRUE;

	return range;

}

//既に入力されていないか
BOOL MarkChecker(char game_board[3][3],char game[]) {

	int a = game[0];
	int b = game[1]; 
	int checker = 0;


	if (game_board[a][b] != ' ') {
		printf("入力済みのマスです。他のマスを選んでください。\n");
		checker = FALSE;
	}
	checker = TRUE;

	return checker;

}
