// データの挿入部分の定義を記述するソースファイル

#include <stdio.h>
#include "define.h"

// 指定されたグリッドに図柄を代入する関数
void Insert(char* board_element_info, char symbol)
{
  *board_element_info = symbol;
}