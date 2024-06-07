#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "board.h"
#include "player_change.h"
#include "error.h"
#include "result.h"
#include "retry.h"


int main(void)
{
	int input_retry;
	char board[INDEX][INDEX];
	char input;
	PLAYER player;
	GAME_JUDGE result;
	RETRY_JUDGE retry;
	int turn;

	do {
		turn = 0;
		player = PLAYER1;
		BoardInitialize(board);
		printf("～三目並べ～\n\n");
		printf("― ゲーム開始 ―\n\n");
		turn++;
		do {
				BoardOutput(board);
				input = Input(player);
				BoardUpdate(player, input, board);
				result = ResultJudge(board, player, turn);
				if (result == CONTINUE) {
					player = PlayerChange(player);
				}
			} while (result == CONTINUE);
			BoardOutput(board);
			ResultOutput(result);
			retry = Retry(input);
		} while (Retry(input)== FINISH);

		printf("\n― 終了 ―\n");

		return 0;
	}
