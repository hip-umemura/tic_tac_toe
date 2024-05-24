#pragma once

//マクロ定義

//勝敗、引き分けを表すマクロ
#define O_WIN	0
#define X_WIN	1
#define DRAW	2
//盤面の要素数を表すマクロ
#define GRID_HEIGHT	3
#define GRID_WIDTH	3


//構造体定義

//配列の要素のINDEXを格納する構造体
typedef struct {
  int x;
  int y;
} INDEX;