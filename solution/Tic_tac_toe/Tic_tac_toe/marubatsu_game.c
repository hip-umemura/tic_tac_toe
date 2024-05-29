#include <stdio.h>
#include<string.h>
#include "data.h"
#include "game_input.h"
#include "game_output.h"
#include "game_judgement.h"

int main(void) {

	COORDINATES board_index = { 0,0 };
	int input_number = INPUT_ERR;
	BOOL line_up = FALSE;
	BOOL input_flag = FALSE;

	GAME_INFO game_info = {
	.game_board = {{'0','1','2'},
								 {'3','4','5'},
								 {'6','7','8'}},
	.player_names = {"プレイヤー1","プレイヤー2"},
	.marks				= {'o','x'},
	.turn_counter = 0,
	.player_index = PLAYER_INDEX(game_info.turn_counter) };



	for (game_info.turn_counter = 0; game_info.turn_counter <= INPUT_VAL_MAX; game_info.turn_counter++) {
		game_info.player_index = PLAYER_INDEX(game_info.turn_counter);

		DisplayBoard(game_info.game_board);
		DisplayStatus(game_info.player_names[game_info.player_index]);

		while (input_flag == FALSE) {

			input_number = InputProcess();

			if (input_number != INPUT_ERR) {
				board_index = ToIndexOfBoard(input_number);

				if (isDuplicate(game_info.game_board[board_index.y][board_index.x]) == FALSE) {
					input_flag = TRUE;
				}
			}
		}
		input_flag = FALSE;

		UpdateBoard(&game_info.game_board[board_index.y][board_index.x], game_info.marks[game_info.player_index]);

		line_up = BoardJudgement(game_info.game_board);

		if (line_up == TRUE) {
			break;
		}
	}

	DisplayBoard(game_info.game_board);
	DisplayResult(game_info.player_names[game_info.player_index], line_up);



	return 0;


}