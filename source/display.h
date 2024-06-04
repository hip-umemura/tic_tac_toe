#ifndef DISPLAY_H_
#define DISPLAY_H_
typedef enum {
    WINNER_A,
    WINNER_B,
    DRAW,
    NONE_WINNER,
    R_RESET
}RESULT;

typedef enum {
    TURN_A,
    TURN_B,
    P_RESET
}PLAYER_TURN;

#define RESET_COMMAND 'r'

RESULT GameBoard();

PLAYER_TURN WhoTurn(PLAYER_TURN PT);

PLAYER_TURN InputBoard(PLAYER_TURN PT, char *c);

void DisplayBoard(char *c);

RESULT JudgeMatch(PLAYER_TURN PT, char *c);

void Result(RESULT r);

void InputError();

void SameInputError();

#endif //DISPLAY_H_