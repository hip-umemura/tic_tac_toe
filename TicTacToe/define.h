#pragma once

// マクロ定義
// 盤面の要素数を表すマクロ
#define GRID_HEIGHT	3
#define GRID_WIDTH	3
#define PLAYER_NUM	2
#define TURN_PLAYER(turn) turn % PLAYER_NUM
#define ERROR      -1
#define LINE_NUM		2
#define INPUT_LEN		2

// 列挙型定義
// ゲームの勝敗を示す
typedef enum {
	CONTINUE,
	WIN,
	DRAW,
} RESULT;

// 真偽を示す
typedef enum {
	FALSE,
	TRUE,
} BOOL;

// 構造体定義
// 配列の要素のINDEXを格納する
typedef struct {
  int x;
  int y;
} INDEX;