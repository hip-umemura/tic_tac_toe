#include "define.h"
//入力引数の値に対応したグリッドがどの要素なのかを探索し、その要素を返す関数
INDEX Search(char input_info, char board_info[3][3]) {
  int x = 0;
  int y = 0;
  // input_integer
  int input_integer = input_info - '0';
  int const y_max = 3;
  int const x_max = 3;

  for (y = 0; y < y_max; y++) {
    //行方向の走査を要素数-1回行う
    for (x = 0; x < x_max - 1; x++) {
      if (board_info[y][x] == input_info) {
        break;
      }
    }
    //一致した要素があるか、最後の要素が一致した場合break
    if (board_info[y][x] == input_info) {
      break;
    }
  }

  // 要素を2次元配列に適するように構造体に格納する
  INDEX index = {x, y};
  return index;
}