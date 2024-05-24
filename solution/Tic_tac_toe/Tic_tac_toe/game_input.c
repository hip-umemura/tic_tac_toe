#include <stdio.h>
#include "data.h"
#include "game_input.h"

void InputByPlayer(char input[4])
{

	for (int i = 0; i < 4; i++) {
		input[i] = '\0';
	}

	scanf_s("%3[^\n]", input, (unsigned)sizeof(input));

	while ((input = getchar()) != '\n' && input != EOF) {
	}
}

int InputToValue(char input[4])
{
	if (input < '0' || input > '8') {
		printf("0�`8����͂��Ă��������B\n");
	}
	return INPUT_ERR;
}

int InputProcess(char input[4])
{
	int serial_number;

	InputByPlayer(input);
	serial_number = InputToValue(input);

	return serial_number;
}

BOOL isDuplicate(char game_board[BOARD_HEIGHT][BOARD_WIDTH], COORDINATES a)
{
	if (game_board[a.x][a.y] == 'o' || game_board[a.x][a.y] == 'x') {
		printf("���ɖ��܂��Ă��܂�\n");
		return TRUE;
	}

	return FALSE;
}