#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "board.h"
#include "error.h"

char Input(PLAYER player)
{
	char input;
	char buffer = '\0';
	
		printf("1�`9�̐�������͂��Ă�������\n");

		if (player == PLAYER1) {
			printf("�v���C���[�P(o)�@���́F");
		} else {
			printf("�v���C���[�Q(x)�@���́F");
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

		printf("���g���C�c�P�A�I���c2\n");
		printf("����:");

		input = getchar();
		while (getchar != '\n') {
			input = '\0';
		}

		return input;
}
