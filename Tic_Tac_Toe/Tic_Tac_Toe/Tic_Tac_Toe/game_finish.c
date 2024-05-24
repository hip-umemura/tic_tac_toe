
#include<stdio.h>
#include<conio.h>

/*debug*/
#define PLAYER_MEM 2
#define NAME_SIZE 21
#define BOARD_SIZE_X 3
#define BOARD_SIZE_Y 3
#define PLYER_ONE 0
#define PLAYER_TWO 1

typedef enum {
	FALSE,
	TRUE
}BOOL;

typedef enum {
	FIRST,
	LAST,
}FIRSTMOVE;

typedef struct PLAYER {
	char player_name[NAME_SIZE];
	FIRSTMOVE turn;
}PLAYER;

char GameDecision(char display_ox_board[], PLAYER now_player);

/*debug*/

char GameDecision(char display_ox_board[BOARD_SIZE_X][BOARD_SIZE_Y], PLAYER now_player) {
	if (
		(((display_ox_board[0][0] == display_ox_board[1][1]) &&
			(display_ox_board[1][1] == display_ox_board[2][2]) ||
			(display_ox_board[2][0] == display_ox_board[1][1]) &&
			(display_ox_board[1][1] == display_ox_board[0][2])) ||
			((display_ox_board[0][0] == display_ox_board[0][1]) &&
				(display_ox_board[0][1] == display_ox_board[0][2]) ||
				(display_ox_board[1][0] == display_ox_board[1][1]) &&
				(display_ox_board[1][1] == display_ox_board[1][2]))) ||
		(((display_ox_board[2][0] == display_ox_board[2][1]) &&
			(display_ox_board[2][1] == display_ox_board[2][2]) ||
			(display_ox_board[0][0] == display_ox_board[1][0]) &&
			(display_ox_board[1][0] == display_ox_board[2][0])) ||
			((display_ox_board[0][1] == display_ox_board[1][1]) &&
				(display_ox_board[1][1] == display_ox_board[2][1]) ||
				(display_ox_board[0][2] == display_ox_board[1][2]) &&
				(display_ox_board[1][2] == display_ox_board[2][2])))
		) {
		if (now_player.turn == FIRST) {
			return 'O';
		}
		return 'X';
	}
	else if (
		(((display_ox_board[0][0] == '-' ||
			display_ox_board[0][1] == '-') ||
			(display_ox_board[0][2] == '-' ||
				display_ox_board[1][0] == '-')) ||
			((display_ox_board[1][1] == '-' ||
				display_ox_board[1][2] == '-') ||
				(display_ox_board[2][0] == '-' ||
					display_ox_board[2][1] == '-'))) ||
		display_ox_board[2][2] == '-') {
		return 'D';
	}
	return 'F';
}

/*
char ShowResult(char game_progress, PLAYER players_array[PLAYER_MEM]) {

}
*/

/*
BOOL Retry_Game() {
	return
}
*/

