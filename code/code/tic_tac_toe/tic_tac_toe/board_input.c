#include<stdio.h>
#include"enum.h"
#include"board_input.h"
#include"board_output.h"
#include"error.h"

//3�~�R��9�}�X�쐬
void BoardInitialize(char (*board)[INDEX])
{
	char init_value[INDEX][INDEX] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
	int x;
	int y;

	for (x = 0; x < INDEX; x++)
	{
		for (y = 0; y < INDEX; y++)
		{
			board[x][y] = init_value[x][y];
		}
	}
}

//�v���C���[�̔Ֆʓ���
void PlayerInput(char(*board)[INDEX], PLAYER player)
{
	int input;
	int x;
	int y;
	
	BoardOutput(board);

	do
	{
		if (player == PLAYER1)
		{
			printf("1�`9�̐�������͂��Ă�������\n");
			printf("�v���C���[�P(o)�@���́F");
		}
		else if (player == PLAYER2)
		{
			printf("1�`9�̐�������͂��Ă�������\n");
			printf("�v���C���[�Q(x)�@���́F");
		}
		scanf_s("%2d", &input);
		scanf_s("%*[^\n]");
	} while (InputErrorBoard(input, board) == ERROR);

	x = (input - 1) / INDEX;//�d�l���`�F�b�N
	y = (input - 1) % INDEX;//�d�l���`�F�b�N

	board[x][y] = player == PLAYER1 ? 'o' : 'x';
}
