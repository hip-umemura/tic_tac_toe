#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "select.h"

#define LENGTH 3

int g_count_judge = 0;
int g_count_a_win = 0;
int g_count_b_win = 0;

RESULT GameBoard() {
    RESULT      result = NONE_WINNER;
    PLAYER_TURN player = P_RESET;
    SELECT      select = START;

    char board[3][3] = { "123", "456", "789" };

    do {
        player = WhoTurn(player);
        printf(" ______________________________ \n");
        printf("                         \n");
        printf("         %s\n", player == TURN_A ? ("Aの番") : ("Bの番"));
        DisplayBoard(&board);
        player = InputBoard(player, &board);
        if (player == P_RESET) {
            result = R_RESET;
        }
        else {
            result = JudgeMatch(player, &board);
        }

        if (result != NONE_WINNER && result != R_RESET) {
            Result(result);
            select = Rematch();
            if (select == END) {
                result = R_RESET;
            }
            else {
                int code = 0x31;
                for (int i = 0; i < LENGTH; i++) {
                    for (int j = 0; j < LENGTH; j++) {
                        board[i][j] = code;
                        code++;
                    }
                }
            }
            g_count_judge = 0;
        }
    } while (result != R_RESET);

    return result;
}

PLAYER_TURN WhoTurn(PLAYER_TURN PT) {
    srand((unsigned int)time(NULL));

    if (PT == P_RESET) {
        int toss = rand() % 2;
        switch (toss) {
        case 0:
            return TURN_A;
        case 1:
            return TURN_B;
        }
    }
    else {
        if (PT == TURN_A) {
            return TURN_B;
        }
        else {
            return TURN_A;
        }
    }
}

PLAYER_TURN InputBoard(PLAYER_TURN PT, char* c) {
    int  input_cnt = 0;
    int  num_input;
    char char_input[2] = { "" };

    while (1) {
        printf("どこにいれますか？(Reset[r]):");
        while ((num_input = getchar()) != '\n' && num_input != EOF) {
            input_cnt++;
            char_input[0] = num_input;
        }
        num_input = atoi(char_input);
        printf(" ______________________________\n");

        if (input_cnt != 1) {
            InputError();
            input_cnt = 0;
            continue;
        }
        num_input = atoi(char_input);
        printf(" ________________________\n");

        if ((num_input >= 1 && num_input <= 9) || (char_input[0] == RESET_COMMAND)) {
            if (strchr(c, char_input[0]) != NULL) {
                if (PT == TURN_A) {
                    c[num_input - 1] = 'O';
                    return TURN_A;
                }
                else {
                    c[num_input - 1] = 'X';
                    return TURN_B;
                }
            }
            if (char_input[0] == RESET_COMMAND) {
                return P_RESET;
            }
            else {
                SameInputError();
                continue;
            }
        }
        else {
            InputError();
            continue;
        }
    }
}

void DisplayBoard(char* c) {
    printf("\n");
    for (int i = 0; i < LENGTH; i++) {
        printf("         |   |\n");
        printf("       %c | %c | %c\n", c[i * 3], c[i * 3 + 1], c[i * 3 + 2]);
        printf("         |   |\n");
        if (i != 2) {
            printf("      ___|___|___\n");
        }
        else {
            printf("         |   | \n");
        }
    }
    printf("\n");
}

RESULT JudgeMatch(PLAYER_TURN PT, char* c) {
    g_count_judge++;
    // 横
    for (int i = 0; i < LENGTH; i++) {
        if (c[i * 3] == c[i * 3 + 1]) {
            if (c[i * 3 + 1] == c[i * 3 + 2]) {
                if (PT == TURN_A) {
                    return WINNER_A;
                }
                else {
                    return WINNER_B;
                }
            }
        }
    }
    // 縦
    for (int i = 0; i < LENGTH; i++) {
        if (c[i] == c[i + 3]) {
            if (c[i + 3] == c[i + 6]) {
                if (PT == TURN_A) {
                    return WINNER_A;
                }
                else {
                    return WINNER_B;
                }
            }
        }
    }
    // 斜め
    if (c[0] == c[4]) {
        if (c[4] == c[8]) {
            if (PT == TURN_A) {
                return WINNER_A;
            }
            else {
                return WINNER_B;
            }
        }
    }

    if (c[2] == c[4]) {
        if (c[4] == c[6]) {
            if (PT == TURN_A) {
                return WINNER_A;
            }
            else {
                return WINNER_B;
            }
        }
    }

    // 引き分け
    char num_or_symbol_check = 0x31;
    for (int i = 0; i < 9; i++) {
        if (c[i] == num_or_symbol_check) {
            return NONE_WINNER;
        }
        num_or_symbol_check++;
    }

    return DRAW;
}

void Result(RESULT r) {
    if (r == DRAW) {
        // 引き分け
        printf("          引き分け\n");
    } else {
        printf("\n           %sの勝利\n", r == WINNER_A ? "A" : "B");
    }
    printf("        Aの勝利回数:%d\n", r == WINNER_A ? ++g_count_a_win : g_count_a_win);
    printf("        Bの勝利回数:%d\n", r == WINNER_B ? ++g_count_b_win : g_count_b_win);
}

// 入力値異常時に表示される関数
void InputError()
{
    for (int i = 0; i < 5; i++) {
        switch (i) {
        case 0:
            printf(" ________________________ ");
            break;
        case 1:
            printf("|                        |");
            break;
        case 2:
            printf("|     不正な入力です     |");
            break;
        case 3:
            printf("|もう一度入力してください|");
            break;
        case 4:
            printf("|________________________|");
            break;
        }
        printf("\n");
    }
}

// 空いていないマスの数字を入れた際に表示される関数
void SameInputError()
{
    for (int i = 0; i < 5; i++) {
        switch (i) {
        case 0:
            printf(" ________________________ ");
            break;
        case 1:
            printf("|                        |");
            break;
        case 2:
            printf("|  既に入力されています  |");
            break;
        case 3:
            printf("|もう一度入力してください|");
            break;
        case 4:
            printf("|________________________|");
            break;
        }
        printf("\n");
    }
}