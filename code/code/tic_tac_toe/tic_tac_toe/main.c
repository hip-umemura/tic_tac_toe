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
	char input;
	PLAYER player;
	JUDGE result;
	JUDGE retry;
	int turn;

	do {
		turn = 1;
		player = PLAYER1;

		BoardInitialize(board);
		printf("～三目並べ～\n\n");
		printf("― ゲーム開始 ―\n\n");
		do {
			BoardOutput(board);
			input = PlayerInput(board, player);
			BoardUpdate(player, input, board);
			result = ResultJudge(board, player, turn);
			if (result == CONTINUE) {
			  player = PlayerChange(player);
			  turn++;
			}
		} while (result == CONTINUE);
		BoardOutput(board);
		ResultOutput(result);
		retry = Retry();
	} while (retry!= FINISH);

	printf("― 終了 ―\n");

	return 0;
}
