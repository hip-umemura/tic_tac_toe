#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board_func.h"

int ScanInput(void) {
	char input_num[BYTE_LIMIT] = { 0 };
	char* endptr;
	int strtol_input_num = 0;
	int cell_num_min = 1;
	int cell_num_max = BOARD_CELL * BOARD_CELL;
	int no_error_flag = FALSE;

	do {
		if (scanf_s("%[^\n]", &input_num, BYTE_LIMIT) != TRUE) {

		}
		else {
			if (strchr(input_num, ' ') != NULL) {

			}
			else {
				strtol_input_num = strtol(input_num, &endptr, 10);
			}
		}
		while (getchar() != '\n');

		if ((cell_num_min <= strtol_input_num) && (strtol_input_num <= cell_num_max)) {
			no_error_flag = TRUE;
		}
		else {
			printf("%d`%d‚Ìƒ}ƒX”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F", cell_num_min, cell_num_max);
			no_error_flag = FALSE;
		}
	} while (no_error_flag == FALSE);
	return strtol_input_num;
}

void PrintBoard(MARK board[BOARD_CELL][BOARD_CELL]) {
    char board_num[][BOARD_CELL * BOARD_CELL] = { {"‚P"},{"‚Q"},{"‚R"},{"‚S"},{"‚T"},{"‚U"},{"‚V"},{"‚W"},{"‚X"} };
    int board_place_num = 0;
    for (int i = 0; i < BOARD_CELL; i++) {
        for (int j = 0; j < BOARD_CELL; j++) {
            switch (board[i][j]) {
                case BLANK: 
                    printf("%s", board_num[board_place_num]);
                    break;
                case PLAYER1_MARK:
                    printf("›");
                    break;
                case PLAYER2_MARK:
                    printf("~");
                    break;
            }
            if (j < (BOARD_CELL - 1)) {
                printf("b");
            }
            board_place_num++;
        }
        printf("\n");
        if (i < (BOARD_CELL - 1)) {
            for (int i = 0; i < (BOARD_CELL - 1); i++) {
                printf("\{");
            }
            printf("\\n");
        }

    }
}

RESULT CheckBoard(MARK board[BOARD_CELL][BOARD_CELL]) {
	int vertical;
	int horizon;
	int diagonal;
	int player1_mark_count = 0;
	int player2_mark_count = 0;
	int bingo = BOARD_CELL;
	int judge_draw = TRUE;

	for (vertical = 0; vertical < BOARD_CELL; vertical++) { // ‰¡1—ñ‚»‚ë‚Á‚½‚©‚Ì”»’è
		player1_mark_count = 0;
		player2_mark_count = 0;
		for (horizon = 0; horizon < BOARD_CELL; horizon++) {
			if (board[vertical][horizon] == PLAYER1_MARK) {
				player1_mark_count++;
				if (player1_mark_count == bingo) {
					return PLAYER1_WIN;
				}
			}
			else if (board[vertical][horizon] == PLAYER2_MARK) {
				player2_mark_count++;
				if (player2_mark_count == bingo) {
					return PLAYER2_WIN;
				}
			}
		}
	}

	for (horizon = 0; horizon < BOARD_CELL; horizon++) { // c1—ñ‚»‚ë‚Á‚½‚©‚Ì”»’è
		player1_mark_count = 0;
		player2_mark_count = 0;
		for (vertical = 0; vertical < BOARD_CELL; vertical++) {
			if (board[vertical][horizon] == PLAYER1_MARK) {
				player1_mark_count++;
				if (player1_mark_count == bingo) {
					return PLAYER1_WIN;
				}
			}
			else if (board[vertical][horizon] == PLAYER2_MARK) {
				player2_mark_count++;
				if (player2_mark_count == bingo) {
					return PLAYER2_WIN;
				}
			}
		}
	}

	player1_mark_count = 0;
	player2_mark_count = 0;

	for (diagonal = 0; diagonal < BOARD_CELL; diagonal++) { // ¶ŽÎ‚ß‚ª‚»‚ë‚Á‚½‚©‚Ì”»’è
		if (board[diagonal][diagonal] == PLAYER1_MARK) {
			player1_mark_count++;
			if (player1_mark_count == bingo) {
				return PLAYER1_WIN;
			}
		}
		else if (board[diagonal][diagonal] == PLAYER2_MARK) {
			player2_mark_count++;
			if (player2_mark_count == bingo) {
				return PLAYER2_WIN;
			}
		}
	}

	player1_mark_count = 0;
	player2_mark_count = 0;

	for (diagonal = 0; diagonal < BOARD_CELL; diagonal++) { // ‰EŽÎ‚ß‚ª‚»‚ë‚Á‚½‚©‚Ì”»’è
		if (board[diagonal][BOARD_CELL - 1 - diagonal] == PLAYER1_MARK) {
			player1_mark_count++;
			if (player1_mark_count == bingo) {
				return PLAYER1_WIN;
			}
		}
		else if (board[diagonal][BOARD_CELL - 1 - diagonal] == PLAYER2_MARK) {
			player2_mark_count++;
			if (player2_mark_count == bingo) {
				return PLAYER2_WIN;
			}
		}
	}

	for (vertical = 0; vertical < BOARD_CELL; vertical++) { // ˆø‚«•ª‚¯‚Ì”»’è
		for (horizon = 0; horizon < BOARD_CELL; horizon++) {
			if (board[vertical][horizon] == BLANK) {
				judge_draw = FALSE;
			}
		}
	}
	if (judge_draw == TRUE) {
		return DRAW;
	}

	return NONE;
}