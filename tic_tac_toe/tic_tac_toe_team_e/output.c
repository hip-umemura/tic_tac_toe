#include "enum.h"
#include <stdio.h>
#include "output.h"
#include "assert.h"
// �Ֆʕ\��
void PrintBoard(void) {
	int i;
	int j;
	for (i = 0; i < NUM; i++) {
		printf("----------\n");
		printf("|");
		for (j = 0; j < NUM; j++) {
			if (g_board[i][j] == ' ') {
				printf("%2d", (i * NUM) + (j + 1));// ���͈ʒu���������l���v�Z�E�\��
				printf("|");
			}
			else {
				printf("%2c", g_board[i][j]);
				printf("|");
			}
		}
		printf("\n");
	}
	printf("----------\n");
}
// ���s�̌��ʂ�\��
void PrintResult(RESULT result) {
	switch (result) {
	case PLAYER1_WIN:
		printf("��U�̏����ł��B");
		break;
	case PLAYER2_WIN:
		printf("��U�̏����ł��B");
		break;
	case DRAW:
		printf("���������ł��B");
		break;
	case RESULT_NONE:
	    assert(FALSE);
		break;
	}
}
