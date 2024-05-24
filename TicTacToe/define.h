#pragma once

//マクロ定義
//盤面の要素数を表すマクロ
#define GRID_HEIGHT	3
#define GRID_WIDTH	3



//列挙型定義
//ゲームの勝敗を示す列挙型
typedef enum {
	CONTINUE,
	O_WIN,
	X_WIN,
	DRAW,
} RESULT;

//ターンを示す列挙型
typedef enum {
	O_TURN,
	X_TURN,
} TURN;

//真偽を示す列挙型
typedef enum {
	FALSE,
	TRUE,
} BOOL;

//構造体定義
//配列の要素のINDEXを格納する構造体
typedef struct {
  int x;
  int y;
} INDEX;