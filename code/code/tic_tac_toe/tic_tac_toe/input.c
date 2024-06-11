#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "board.h"
#include "error.h"

char Input(PLAYER player)
{
	char input;
	char buffer = '\0';
	
		printf("1～9の数字を入力してください\n");

		if (player == PLAYER1) {
			printf("プレイヤー１(o)　入力：");
		} else {
			printf("プレイヤー２(x)　入力：");
		}

		input = getchar();
		while (getchar() != '\n') {
			input = '\0';
		}

	return input;
}

char InputRetry(void)
{
	char input;
	char buffer = '\0';

		printf("リトライ…１、終了…2\n");
		printf("入力:");

		input = getchar();
		while (getchar != '\n') {
			input = '\0';
		}

		return input;
}
