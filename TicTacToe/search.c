#include "define.h"
//���͈����̒l�ɑΉ������O���b�h���ǂ̗v�f�Ȃ̂���T�����A���̗v�f��Ԃ��֐�
INDEX Search(char input_info, char board_info[3][3]) {
  int x = 0;
  int y = 0;
  // input_integer
  int input_integer = input_info - '0';
  int const y_max = 3;
  int const x_max = 3;

  for (y = 0; y < y_max; y++) {
    //�s�����̑�����v�f��-1��s��
    for (x = 0; x < x_max - 1; x++) {
      if (board_info[y][x] == input_info) {
        break;
      }
    }
    //��v�����v�f�����邩�A�Ō�̗v�f����v�����ꍇbreak
    if (board_info[y][x] == input_info) {
      break;
    }
  }

  // �v�f��2�����z��ɓK����悤�ɍ\���̂Ɋi�[����
  INDEX index = {x, y};
  return index;
}