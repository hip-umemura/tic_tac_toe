#include <stdio.h>
#include "enum.h"
#include "error.h"

JUDGE InputErrorBoard(int input, char board[INDEX][INDEX])
{
	int x;
	int y;

	x = (input - 1) / INDEX;
	y = (input - 1) % INDEX;

	if ((input < 1) || (input > 9)) {
		printf("�G���[�F�K�؂Ȑ�������͂��Ă�������\n");
		return ERROR;
	} else if ((board[x][y] == 'o') || (board[x][y] == 'x')) {
		printf("�G���[�F�K�؂Ȑ�������͂��Ă�������\n");
		return ERROR;
	} else {
		return CONTINUE;
	}
}

JUDGE InputErrorRetry(int input)
{
	if ((input == 1) || (input == 2)) {
		return CONTINUE;
	} else {
		printf("�G���[�F�K�؂Ȑ�������͂��Ă�������\n");
		return ERROR;
	}
}
