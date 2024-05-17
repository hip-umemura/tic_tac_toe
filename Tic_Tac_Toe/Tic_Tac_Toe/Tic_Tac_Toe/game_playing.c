#include<stdio.h>
#include<conio.h>
#include"game_finish.c"

#define M 3
#define N 3

#define FOWARD 'w'
#define BACK 's'
#define RIGHT 'a'
#define LEFT 'd'
#define DECISION ' '

#define PLAYER_1 1
#define PLAYER_2 -1

typedef enum {
	FALSE,
	TRUE,
}BOOL;

typedef enum {
	REINPUT,
	FIRST_INPUT,
}FLAG;

// game_playing.c�����include
BOOL Operate_Exception(int move_operator, int *now_operator_x, int *now_operator_y);
BOOL isGameFinished(int now_game_field[3][3]);

int Input_OX(char player_name_now[], int player_symbol) {
	int now_operator_x = 1;
	int now_operator_y = 1;
	int display_field[M][N];
	int operate_field[M][N];
	BOOL isgame_continue = TRUE;
	FLAG display_tutorial = FIRST_INPUT;

	// display_field��input_field�̏�����
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			display_field[i][j] = 0;
			operate_field[i][j] = 0;
		}
	}

	// �ŏ��ɑ���q�𒆉��ɂ����Ă���
	operate_field[now_operator_y][now_operator_x] = 1;
	while (isgame_continue) {

		// ���̓G���[�̏ꍇ�\�������Ȃ�
		if (display_tutorial) {
			// ��ʕ\��
			printf("%s�̔Ԃł��B3�}�X�~3�}�X�̒�����D���ȏꏊ��I�����Ă��������B\n", player_name_now);
			printf("���̏ꏊ��%s����͂���ꏊ�ɂȂ�܂��B\n", (player_symbol > 0) ? "�Z" : "�~");
			printf("���̈ړ����@�́A�uA�F���AW�F��AS�F���A D�F�E�v�ł��B\n");
			printf("�ړ�������X�y�[�X�L�[�������Ă��������B\n");
		}
		printf("�Z�~�\���p�Ֆʁ@�@�@ �@�@�Z�~���͗p�Ֆ�\n");
		for (int i = 0; i < N; i++) {
			printf("�@�@");
			for (int j = 0; j < N; j++) {
				printf("%s", (display_field[i][j] == 1) ? "�Z" : ((display_field[i][j] == 0) ? "�[" : "�~"));
				if (j != 2) {
					printf(" ");
				}
			}
			printf("�@�@�@�@|�@�@�@�@");
			for (int j = 0; j < N; j++) {
				printf("%s", (operate_field[i][j] == 1) ? "��" : "�[");
				if (j != 2) {
					printf(" ");
				}
			}
			printf("\n");
		}

		// ������͂����҂��Ď���̓��͂�������͂Ƃ���
		display_tutorial = FIRST_INPUT;

		// ���͂��󂯎��
		int key_operataor = _getch();
		if (((key_operataor == FOWARD) || (key_operataor == RIGHT)) || ((key_operataor == BACK) || (key_operataor == LEFT))) {
				int before_x = now_operator_x;
				int before_y = now_operator_y;
			if (Operate_Exception(key_operataor, operate_field, &now_operator_x, &now_operator_y)) {
				operate_field[before_y][before_x] = 0;
				operate_field[now_operator_y][now_operator_x] = 1;
			}
		}
		else if (key_operataor == DECISION) {
			// ���͉\���̔���
			if (display_field[now_operator_y][now_operator_x] == 0) {
				// �ǂ���̃v���C���[�̓��͂��̔���
				if (player_symbol == PLAYER_1) {
					display_field[now_operator_y][now_operator_x] = 1;
				}
				else {
					display_field[now_operator_y][now_operator_x] = -1;
				}
				//�Q�[���I������
				if (isGameFinished(display_field)) {
					isgame_continue = FALSE;
				}
			}
			// �G���[����
			else {
				printf("���̃}�X�͊��ɓ��͂���Ă��܂��B�ē��͂����肢���܂��B\n");
				display_tutorial = REINPUT;
			}
		}
	}
	return 0;
}

int main() {
	Input_OX("Yuki Nakajima", -1);
}