#include "define.h"
//入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(char input_info, char board_info[3][3]) {
  int x = 0;
  int y = 0;

  for (y = GRID_HEIGHT - 1; y >= 0; y--) {
    BOOL match = FALSE;
    for (x = 0; x < GRID_WIDTH; x++) {
      // 引数が現在探索中のグリッド番号に対応するかを判定
      if (input_info == '1' + (GRID_HEIGHT - y - 1) * GRID_WIDTH + x) {
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