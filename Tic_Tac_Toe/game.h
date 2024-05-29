#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "display.h"

/// <summary>
/// �O�ڕ��ׂ̃}�X�\���A���[���\���A�Q�[���i�s���s���֐�
/// </summary>
/// <param name="">void�^</param>
/// <returns>SHOW_RESULT_INSTRUCTION</returns>
SHOW_RESULT_INSTRUCTION Play_Tic_Tac_Toe(void);

/// <summary>
/// �}�X�ڂ̎w�肪���������ǂ����𔻒肷��֐�
/// </summary>
/// <param name="mono_input">int�^:�}�X��</param>
/// <param name="board">int*�^:�Ֆ�</param>
/// <returns>BOOL</returns>
BOOL isCorrectInput(int mono_input,int* board);

/// <summary>
/// �}�X�ڂ̓��͂��������Ȃ����Ƃ�񎦂��ăv���C���[�ɍē��͂����߂�֐�
/// </summary>
/// <param name="">void�^</param>
void Suggest_Reinput(void);

/// <summary>
/// �Q�[�����J�n���邩�I�����邩�𔻒肷��֐�
/// </summary>
/// <param name="mono_input">int�^:�����R�[�h</param>
/// <returns>GAME_CONTINUE_INSTRUCTION</returns>
GAME_CONTINUE_INSTRUCTION isGameStart(int mono_input);

/// <summary>
/// �Q�[���I�������𖞂����ďI�����邩�A�Q�[���𑱍s���邩���肷��֐�
/// </summary>
/// <param name="player">int�^:���</param>
/// <param name="board">int*�^:�Ֆ�</param>
/// <returns>SHOW_RESULT_INSTRUCTION</returns>
SHOW_RESULT_INSTRUCTION isGameEnded(int player,int *board);