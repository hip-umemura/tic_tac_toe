#pragma once

// �O�ڕ��ׂɎg�p����֐��̃v���g�^�C�v�錾���s���w�b�_�t�@�C��
#include "define.h"

// �Ֆʂ�\������֐�
void Output_Grid(char board_info_array[3][3]);

// ���݂̃^�[����\������֐�
void Output_Turn(char symbol);

// �Q�[���̏��s��\������֐�
void Output_Result(char symbol, RESULT result_info);

// ���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(char input_info, char board_info_array[3][3]);

// �f�[�^�̑}�������̒�`���L�q����֐�
void Insert(char* board_element_info, char symbol);

// ���͂��󂯕t����֐�
void Input(char symbol, char input_info_array[INPUT_LEN]);

// �O���b�h���J���Ă��邩�𔻒肷��֐�
BOOL Judge_Grid(char board_info_array, char symbol_array[PLAYER_NUM]);

// ���͂����������𔻒肷��֐�
BOOL Judge_Input(char input_possess);

// �O�ڕ��ׂ̏��s�̔��������֐�
RESULT Judge_Result(char joke[GRID_HEIGHT][GRID_WIDTH], char symbol, INDEX grid_element_designation, int turn_count);