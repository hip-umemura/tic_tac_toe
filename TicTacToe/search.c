#include "define.h"
//���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(char input_info, char board_info[3][3]) {
  int x = 0;
  int y = 0;
  // ���͈�����int�^�ɕϊ�
  int input_val = input_info - '0';
  int loop_count = 0;

  for (y = 0, loop_count = 0; y < GRID_HEIGHT; y++) {
    BOOL match = FALSE;
    for (x = 0; x < GRID_WIDTH; x++, loop_count++) {
      if (input_val == loop_count) {
        match = TRUE;
        break;
      }
    }
    if (match) {
      break;
    }
  }

  INDEX index = { x, y };
  return index;
}