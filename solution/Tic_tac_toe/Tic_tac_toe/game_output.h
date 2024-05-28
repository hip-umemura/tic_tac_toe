#ifndef GAME_OUTPUT_H
#define GAME_OUTPUT_H

// �v���g�^�C�v�錾
void DisplayBoard(char game_board[BOARD_HEIGHT][BOARD_WIDTH]);

void DisplayStatus(char[]);

void DisplayResult(char[], BOOL);

void UpdateBoard(char*, char);

COORDINATES ToIndexOfBoard(int);

#endif // GAME_OUTPUT_H