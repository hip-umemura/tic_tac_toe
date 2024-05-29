#pragma once

#include "tic_tac_toe.h"

void InputName(PLAYER* p_now_player) {
	int player_count = 0;
	while (player_count < PLAYER_MEM) {
		int name_len = 0;
		int name_char = "";
		printf("プレイヤー名を入力してください（全角文字のみ、10文字以内）：");
		while (name_char - ENTER) {
			name_char = getchar();
			if ((name_len + 1) % 2) {
				//　半角判断
				if (name_char != ENTER &&
					(name_char >= NULL && name_char <= DEL) ||
					(name_char >= LWC && name_char <= UPC)) {
				// bufferを捨て、正しくない名前なので名前を0にセット
					while (name_char - ENTER) {
						name_char = getchar();
					}
					name_len = 0;
				}
			}

			// 配列に格納 0から21文字まで ENTERをのぞく
			if (name_char != ENTER && ((0 <= name_len) && (name_len <= 20))) {
				*((&(*(p_now_player + player_count) -> player_name)) + name_len) = name_char;
				name_len++;
			}
			// ENTERが入力されたそれをヌル文字に置き換え配列に格納
			else if (name_char == ENTER && ((1 <= name_len) && (name_len <= 21))) {
				*((&(*(p_now_player + player_count) -> player_name)) + name_len) = '\0';
			}
			// 20字より大きくなったらバッファから吐き出す
			else if (NAME_SIZE - 1 < name_len) {
				while (name_char - ENTER) {
					name_char = getchar();
				}
			}
		}
		// 名前の長さが正常な時だけ入力を認め、カウントを増加
		if (MIN_NAME_SIZE <= name_len && name_len <= NAME_SIZE - 1) {
			player_count++;
		}
		else {
			printf("指定の入力と異なります。再入力をお願いします。\n");
		}
	}
}

int ChoiceFirstAttack(PLAYER* p_now_player) {
	srand((unsigned int)time(NULL));
	if (rand() % 2) {
		p_now_player -> turn = FIRST;
		(p_now_player + 1) -> turn = LAST;
		return PLAYER_ONE;
	}
	else {
		p_now_player -> turn = LAST;
		(p_now_player + 1) -> turn = FIRST;
		return PLAYER_TWO;
	}
}

int ChangePlay(int player_turn) {
	if (player_turn == PLAYER_ONE) {
		player_turn = PLAYER_TWO;
	}
	else {
		player_turn = PLAYER_ONE;
	}
	return player_turn;
}
