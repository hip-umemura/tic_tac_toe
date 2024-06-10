#include <stdio.h>
#include <assert.h>
#include "enum.h"
#include "error.h"

ERROR_JUDGE ErrorInput(char input)
{

	if ((input < '1') || (input > '9')) {
		printf("エラー：適切な数字を入力してください\n\n");
		return ERROR;
	}

	return NONE_ERROR;
	
}

ERROR_JUDGE ErrorInputRetry(char input)
{
	if ((input != '1') && (input != '2')) {
		printf("エラー：適切な数字を入力してください\n\n");
		return ERROR;
	} 
	else {
		return NONE_ERROR;
	}
}

ERROR_JUDGE ErrorBoardUpdate(char input,char board[INDEX][INDEX])
{

	assert((input >= '1') && (input <= '9'));

	for (int i = 0; i < INDEX; i++) {
		for (int j = 0; j < INDEX; j++) {
			if (board[i][j] == input) {
				return NONE_ERROR;
			}
		}
	}
	printf("エラー：適切な数字を入力してください\n\n");
	return ERROR;
}
