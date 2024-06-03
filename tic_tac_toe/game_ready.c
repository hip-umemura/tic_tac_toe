#include <stdio.h>
#include "define.h"
#include "game_ready.h"


//�z��̗v�f��������
void InitSquare(char (*game_board)[TWODIMENTION]) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            game_board[i][j] = ' ';
        }
    }

}


//�}�X�Ɛ�U��U�̕\��
void PreScreen(char game_board[TWODIMENTION][TWODIMENTION]) {

    printf("  �Z�@��U\n");
    printf("  �~�@��U\n");

    printf("  ");
    for (int x = 1; x <= 3; x++) {
        printf("| %1d", x);
    }
    printf("|");
    printf("\n");
    for (int y = 0; y < 3; y++) {
        printf("% d|", y + 1);
        for (int x = 0; x < 3; x++) {
            printf("% 2c|", game_board[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}


