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
	ERROR_JUDGE error_input;
	ERROR_JUDGE error;
	ERROR_JUDGE error2;
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
			do {
				turn++;
				BoardOutput(board);
				do {
					do {
						input = Input(player);
						error = ErrorInput(input);
					} while (error == ERROR);
					 error2 = ErrorBoardUpdate(input, board);
				} while (error2 == ERROR);
				BoardUpdate(player, input, board);
				result = ResultJudge(board, player, turn);
				if (result == CONTINUE) {
					player = PlayerChange(player);
				}
			} while (result == CONTINUE);
			BoardOutput(board);
			ResultOutput(result);
			do {
				input_retry = InputRetry();
				error_input = ErrorInputRetry(input_retry);
			} while (error_input == ERROR);
			retry = Retry(input_retry);
		} while (retry == RETRY);

		printf("\n― 終了 ―\n");

		return 0;
	}
