#pragma once
#include <stdio.h>
#include <time.h>
#include<stdlib.h>

#define DEBUG
#ifdef DEBUG
#define PLAYER_ONE 0
#define PLAYER_TWO 1
#endif

#define NUL '\0'
#define DEL 127
#define LWC 161
#define UPC 223
#define ENTER '\n'


void InputName(PLAYER* player_info) {
	int player_count = 0;
	while (player_count < 2) {
		int name_len = 0;
		int name_char = "";
		printf("プレイヤー%dの入力 :", player_count + 1);
		while (name_char - ENTER) {
			name_char = getchar();
			if ((name_len + 1) % 2) {
				//　半角判断
				if (name_char != ENTER &&
					(name_char >= NULL && name_char <= DEL) ||
					(name_char >= LWC && name_char <= UPC)) {

					// bufferを捨てるifに入るためにname_lenを21で代入
					printf("半角です。\n");
					name_len = 21;
				}
			}
			// 配列に入れます。
			if (name_char != ENTER && ((0 <= name_len) && (name_len <= 20))) {
				*((&(*(player_info + player_count)->player_name)) + name_len) = name_char;
				name_len++;
			}
			else if (name_char == ENTER && ((1 <= name_len) && (name_len <= 21))) {
				*((&(*(player_info + player_count)->player_name)) + name_len) = '\0';
			}
			else if (20 < name_len) {
				while (name_char - ENTER) {
					name_char = getchar();
				}
				name_char = ENTER;
			}

		}

		if (1 <= name_len && name_len <= 20) {
			player_count++;
		}

	}
}

void ChoiceFirstAttack(int* now_player_turn, PLAYER* player_info)
{
	srand((unsigned int)time(NULL));
	if (rand() % 2) {
		player_info ->turn = FIRST;
		(player_info + 1)->turn = LAST;
		*now_player_turn = PLAYER_ONE;
	}
	else {
		player_info->turn = LAST;
		(player_info + 1)->turn = FIRST;
		*now_player_turn = PLAYER_TWO;
	}
}

int ChangePlay(int now_player_turn){

	if (now_player_turn == PLAYER_ONE){
		now_player_turn = PLAYER_TWO;
	}
	else
	{ 
		now_player_turn = PLAYER_ONE;
	}
	return now_player_turn;

}

