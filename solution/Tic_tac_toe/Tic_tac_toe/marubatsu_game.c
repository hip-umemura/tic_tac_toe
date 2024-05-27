#include <stdio.h>
#include<string.h>
#include "data.h"
#include "game_input.h"
#include "game_output.h"
#include "game_judgement.h"

int main(void) {

	COORDINATES board_index = { INPUT_ERR,0 };
	int input_number = INPUT_ERR;
	//BOOL game_flag = FALSE;
	BOOL input_flag = FALSE;
	JUDGE game_result = DRAW;

	GAME_INFO game_info = {
	.game_board = {{'0','1','2'},
								 {'3','4','5'},
								 {'6','7','8'}},
	.player_names = {"プレイヤー1","プレイヤー2"},
	.marks = {'o','x'},
	.turn_counter = 0,
	.player_index = PLAYER_INDEX(game_info.turn_counter) };


	while (BoardJudgement(game_info.game_board) != TRUE) {
		DisplayBoard(game_info.game_board);
		DisplayStatus(game_info.player_names[game_info.player_index]);

		while (input_flag != TRUE) {
			input_number = InputProcess();

			if (input_number != INPUT_ERR) {

				board_index.y = input_number % BOARD_WIDTH;
				board_index.x = input_number / BOARD_WIDTH;

				if (isDuplicate != TRUE) {
					input_flag = TRUE;
				}

			}
		}
		game_info.game_board[board_index.y][board_index.x] = game_info.marks[game_info.player_index];
	}

	DisplayBoard(game_info.game_board);
	DisplayResult(game_info.player_names[game_info.player_index], game_result);



	return 0;


}