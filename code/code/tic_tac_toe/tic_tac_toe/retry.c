#include <stdio.h>
#include "enum.h"
#include "retry.h"
#include "error.h"

JUDGE Retry(void)
{
	char input;

	do {
		printf("���g���C�c�P�A�I���c2\n");
		printf("����:");
		input = getchar();
		
		//scanf_s("%*[^\n]");
	} while (InputErrorRetry(input) == ERROR);
	if (input == '1') {
		return RETRY;
	} else {
		return FINISH;
	}
}
