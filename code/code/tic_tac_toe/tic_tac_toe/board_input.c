#include<stdio.h>
#include"enum.h"
#include"board_input.h"
#include"board_output.h"
#include"error.h"

//3×３の9マス作成
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

//プレイヤーの盤面入力
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
			printf("1～9の数字を入力してください\n");
			printf("プレイヤー１(o)　入力：");
		}
		else if (player == PLAYER2)
		{
			printf("1～9の数字を入力してください\n");
			printf("プレイヤー２(x)　入力：");
		}
		scanf_s("%2d", &input);
		scanf_s("%*[^\n]");
	} while (InputErrorBoard(input, board) == ERROR);

	x = (input - 1) / INDEX;//仕様書チェック
	y = (input - 1) % INDEX;//仕様書チェック

	board[x][y] = player == PLAYER1 ? 'o' : 'x';
}
