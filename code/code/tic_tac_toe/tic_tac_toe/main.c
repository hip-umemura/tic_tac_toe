#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "board_output.h"
#include "error.h"
#include "result.h"
#include "retry.h"

PLAYER PlayerChange(PLAYER player)
{
	if (player == PLAYER1) {
		return PLAYER2;
	} else {
		return PLAYER1;
	}
}

int main(void)
{
	char board[INDEX][INDEX];
	int input;
	PLAYER player = PLAYER1;
	JUDGE result;

	do {
		int turn = 1;

		BoardInitialize(board);
		printf("�`�O�ڕ��ׁ`\n\n");
		printf("�\ �Q�[���J�n �\\n\n");
		do {
			BoardOutput(board);
			input = PlayerInput(board, player);
			BoardUpdate(player, input, board);
			result = ResultJudge(board, player, turn);
			player = PlayerChange(player);
			turn++;
		} while (result == CONTINUE);
		BoardOutput(board);
		ResultOutput(result);
	} while (Retry() == RETRY);
	printf("�\ �I�� �\\n");

	return 0;
}
