#include "define.h"
//���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(char input_info, char board_info[3][3]) {
  int x = 0;
  int y = 0;

  for (y = 0; y < GRID_HEIGHT; y++) {
    int match = FALSE;
    for (x = 0; x < GRID_WIDTH; x++) {
      if (board_info[y][x] == input_info) {
        match = TRUE;
        break;
      }
    }
    if (match) {
      break;
    }
  }

  // �v�f��2�����z��ɓK����悤�ɍ\���̂Ɋi�[����
  INDEX index = {x, y};
  return index;
}