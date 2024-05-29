#pragma once

#include "tic_tac_toe.h"

void InputName(PLAYER* p_now_player) {
	int player_count = 0;
	while (player_count < PLAYER_MEM) {
		int name_len = 0;
		int name_char = "";
		printf("�v���C���[������͂��Ă��������i�S�p�����̂݁A10�����ȓ��j�F");
		while (name_char - ENTER) {
			name_char = getchar();
			if ((name_len + 1) % 2) {
				//�@���p���f
				if (name_char != ENTER &&
					(name_char >= NULL && name_char <= DEL) ||
					(name_char >= LWC && name_char <= UPC)) {
				// buffer���̂āA�������Ȃ����O�Ȃ̂Ŗ��O��0�ɃZ�b�g
					while (name_char - ENTER) {
						name_char = getchar();
					}
					name_len = 0;
				}
			}

			// �z��Ɋi�[ 0����21�����܂� ENTER���̂���
			if (name_char != ENTER && ((0 <= name_len) && (name_len <= 20))) {
				*((&(*(p_now_player + player_count) -> player_name)) + name_len) = name_char;
				name_len++;
			}
			// ENTER�����͂��ꂽ������k�������ɒu�������z��Ɋi�[
			else if (name_char == ENTER && ((1 <= name_len) && (name_len <= 21))) {
				*((&(*(p_now_player + player_count) -> player_name)) + name_len) = '\0';
			}
			// 20�����傫���Ȃ�����o�b�t�@����f���o��
			else if (NAME_SIZE - 1 < name_len) {
				while (name_char - ENTER) {
					name_char = getchar();
				}
			}
		}
		// ���O�̒���������Ȏ��������͂�F�߁A�J�E���g�𑝉�
		if (MIN_NAME_SIZE <= name_len && name_len <= NAME_SIZE - 1) {
			player_count++;
		}
		else {
			printf("�w��̓��͂ƈقȂ�܂��B�ē��͂����肢���܂��B\n");
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
