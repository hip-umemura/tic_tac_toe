#pragma once

#include <stdio.h>
#include <conio.h>

#define TITLE "�O�ڕ��׃Q�[��"
#define VERSION "ver1.0"
#define TEXT_WIDTH 76
#define STR_SIZE 35
#define PLAYER1 1
#define PLAYER2 -1
#define ENTER '\n'
#define Y 'y'
#define N 'n'
#define PLAYER1_MARK 'o'
#define PLAYER2_MARK 'x'
#define ZHU_SIZE 3

/// <summary>
/// �Q�[���I������
/// </summary>
typedef enum {
  GAME_END,
  GAME_START,
  RE_INPUT,
} GAME_CONTINUE_INSTRUCTION;

/// <summary>
/// ���U���g�\������
/// </summary>
typedef enum {
  GAME_CONTINUE,
  GAME_DRAW,
  GAME_WIN_1,
  GAME_WIN_2,
} SHOW_RESULT_INSTRUCTION;

/// <summary>
/// BOOL�^
/// </summary>
typedef enum {
  FALSE,
  TRUE,
} BOOL;

/// <summary>
/// �w�b�_���̏���\������֐�
/// </summary>
/// <param name="title">�^�C�g����</param>
/// <param name="version">�o�[�W������</param>
void Show_Headder(char title[], char version[]);

/// <summary>
/// ���͂�1�����L�[�{�[�h����󂯎��֐�
/// </summary>
/// <param name="">void�^</param>
/// <returns>int�^</returns>
int Get_Input(void);