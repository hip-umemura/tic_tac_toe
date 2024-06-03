#include <stdio.h>
#include "enum.h"
#include "retry.h"
#include "error.h"

JUDGE Retry(void)
{
	char input;

	do {
		printf("リトライ…１、終了…2\n");
		printf("入力:");
		input = getchar();
		
		//scanf_s("%*[^\n]");
	} while (InputErrorRetry(input) == ERROR);
	if (input == '1') {
		return RETRY;
	} else {
		return FINISH;
	}
}
