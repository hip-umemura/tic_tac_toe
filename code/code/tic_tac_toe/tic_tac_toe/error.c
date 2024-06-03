#include <stdio.h>
#include "enum.h"
#include "error.h"

JUDGE InputErrorBoard(char input, char board[INDEX][INDEX])
{
	int i, j;

	if (getchar() != '\n') {
	  return ERROR;
	}
	if ((input < '1') || (input > '9')) {
		printf("エラー：適切な数字を入力してください\n");
		return ERROR;
	} 

	for (i = 0; i < INDEX; i++) {
      for (j = 0; j < INDEX; j++) {
		if (input == board[i][j]) {
	      return CONTINUE;
		}
	  }
     }

	return ERROR;
	
}

JUDGE InputErrorRetry(char input)
{
  if (getchar() != '\n') {
	while (getchar() != '\n');
	return ERROR;
  }
	if ((input == '1') || (input == '2')) {
		return CONTINUE;
	} else {
		printf("エラー：適切な数字を入力してください\n");
		return ERROR;
	}
}
