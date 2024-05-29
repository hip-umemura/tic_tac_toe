#pragma once
#include "general.h"
#include <string.h>
#include <stdio.h>
#include "game.h"

// �^�C�g����ʂ̕\�����s���֐�
// ���� void
// �Ԃ�l �񋓌^ �Q�[���I������/�Q�[���J�n����
GAME_CONTINUE_INSTRUCTION Show_GameTitle(void);

// �Q�[�����I�����邩�v���C���[�Ɋm�F�������ʂ�\������֐�
// ���� void
// �Ԃ�l int�^Get_Input�֐��̕Ԃ�l
int Show_ExitGame(void);

// ���݂̔ՖʂƎO�ڕ��ׂ̃��[����\������֐�
/* ���� int�^�̃v���C���\��\���ϐ�
   �C�ӂ̌^�̔Ֆʂ�\���ϐ��ւ̃|�C���^�@*/
// �Ԃ�l void�^
void Show_GameInfo(int player_info, int* board);

// �Q�[���̏��s����Ɋ�Â��A���ʂ�\������֐�
/* ���U���g�\������
   �C�ӂ̕��̔Ֆʂ�\���ϐ��ւ̃|�C���^ */
// �Ԃ�l void
void Show_GameResult(SHOW_RESULT_INSTRUCTION result_instruction, int* board);

