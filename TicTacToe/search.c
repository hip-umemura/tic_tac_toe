#include "define.h"
//入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
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

  // 要素を2次元配列に適するように構造体に格納する
  INDEX index = {x, y};
  return index;
}