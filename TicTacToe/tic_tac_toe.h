#pragma once
//�O�ڕ��ׂɎg�p����֐��̃v���g�^�C�v�錾���s���w�b�_�t�@�C��
#include "define.h"

//�Ֆʂ�\������֐�
void Output_Grid(char board_info[3][3]);

//���݂̃^�[����\������֐�
void Output_Info(int tern_info);

//�Q�[���̏��s��\������֐�
void Output_Result(int result_info);

//���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(char input_info, char board_info[3][3]);

//�f�[�^�̑}�������̒�`���L�q����֐�
void Insert(char* board_element_info, int turn_info);

//���͂��󂯕t����֐�
char Input(TURN turn_info);