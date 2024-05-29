#include <stdio.h>
#include<stdlib.h>
#include "data.h"

BOOL CheckInputViolation(char input[INPUT_LEN_MAX])
{
	int index = 0;
	do{
		if ((input[index] < VAL_TO_ASCII(INPUT_VAL_MIN)) || (input[index] > VAL_TO_ASCII(INPUT_VAL_MAX)) || (index >= INPUT_LEN_MAX) || (input[index] == '\n')) {
			printf("0〜8を入力してください : ");
			return TRUE;
		}
		index++;
	} while (input[index] != '\n');

	return FALSE;
}

BOOL isDuplicate(char game_board) {
	if (game_board == 'o' || game_board == 'x') {
		printf("既に埋まっています\n");
		printf("もう一度入力してください : ");
		return TRUE;
	}
	return FALSE;
}

int InputProcess()
{
	char input[INPUT_LEN_MAX] = { '\0' };
	int input_number = INPUT_ERR;
	int index = 0;

	do {
		if (index >= INPUT_LEN_MAX) {
			while (getchar() != '\n')
				;
			break;
		}
		input[index] = getchar();
		index++;
	} while (input[index - 1] != '\n');

	if (CheckInputViolation(input) == FALSE) {
		input_number = atoi(input);
	}

	return input_number;

}