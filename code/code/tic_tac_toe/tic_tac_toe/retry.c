#include <stdio.h>
#include "enum.h"
#include "retry.h"
#include "error.h"

JUDGE Retry(void)
{
	int input;

	do {
		printf("���g���C�c�P�A�I���c2\n");
		printf("����:");
		scanf_s("%2d", &input);
		scanf_s("%*[^\n]");
	} while (InputErrorRetry(input) == ERROR);
	if (input == 1) {
		return RETRY;
	} else {
		return FINISH;
	}
}
