#include <stdio.h>
#include<stdlib.h>
#include "data.h"

BOOL CheckInputViolation(char input[INPUT_LEN_MAX])
{
	int index = 0;
	while(input[index] != '\n') {
		if ((input[index] < '0') || (input[index] > '8') || (index >= INPUT_LEN_MAX)) {
			printf("0`8‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
			return TRUE;
		}
		index++;
	}
	return FALSE;
}

BOOL isDuplicate(char game_board){
	if (game_board == 'o' || game_board == 'x') {
		printf("Šù‚É–„‚Ü‚Á‚Ä‚¢‚Ü‚·\n");
		printf("‚à‚¤ˆê“x“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
		return TRUE;
	}
	return FALSE;
}

int InputProcess()
{
	char input[INPUT_LEN_MAX] = "\0";
	int input_number = INPUT_ERR;
	int index = 0;

	for (int i = 0; i < INPUT_LEN_MAX; i++) {
		input[i] = '\0';
	}

	do {
		if (index >= INPUT_LEN_MAX) {
			while (getchar() != '\n')
				;
			break;
		}
		input[index] = getchar();
		index++;
	} while (input[index - 1] != '\n');

	if (CheckInputViolation(input) == TRUE) {
		return INPUT_ERR;
	}

	return atoi(input);

}

