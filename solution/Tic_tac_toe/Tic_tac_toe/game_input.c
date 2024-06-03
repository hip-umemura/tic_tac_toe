#include <stdio.h>
#include<stdlib.h>
#include "data.h"

BOOL CheckInputViolation(char input[INPUT_LEN_MAX])
{
	int index = 0;
	do{
		if ((input[index] < VAL_TO_ASCII(INPUT_VAL_MIN)) ||
				(input[index] > VAL_TO_ASCII(INPUT_VAL_MAX)) ||
				(index >= INPUT_LEN_MAX) || (input[index] == '\n')) {
			printf("0`8‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ : ");
			return TRUE;
		}
		index++;
	} while (input[index] != '\n');

	return FALSE;
}

BOOL isDuplicate(char square)
{
	if (square == 'o' || square == 'x') {
		printf("Šù‚É–„‚Ü‚Á‚Ä‚¢‚Ü‚·\n");
		printf("‚à‚¤ˆê“x“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ : ");
		return TRUE;
	}
	return FALSE;
}

int InputProcess()
{
	char input[INPUT_LEN_MAX] = {'\0'};
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