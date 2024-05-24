#ifndef DATA_H
#define DATA_H

// マクロの定義 //

#define PLAYER_NUM  2																		// プレイヤーの人数
#define NAME_LEN_MAX  17																	// プレイヤー名の最大バイト数
#define BOARD_HEIGHT  3																		// ボードの高さ
#define BOARD_WIDTH	3																		// ボードの幅
#define INPUT_LEN_MAX	2																	// 入力長の最大
#define INPUT_VAL_MIN	0
#define INPUT_VAL_MAX ((BOARD_HEIGHT * BOARD_WIDTH) – 1)		// 入力数値の最大値
#define INPUT_ERR  INPUT_VAL_MIN - 1														// 入力エラーを表す値
#define CONNECTED_NUM_FOR_END  3															// 終了条件の同じ記号が並ぶ数
#define PLAYER_INDEX(turn) (turn % PLAYER_NUM)							// turnをplayer_indexに変換する
#define EMPTY  " "																			// 空文字列



// 構造体の定義 //

typedef struct
{
	int x;
	int y;

}COORDINATES;

typedef struct
{
	char game_board[BOARD_HEIGHT][BOARD_WIDTH];
	char players[PLAYER_NUM][NAME_LEN_MAX];
	char marks[PLAYER_NUM];
	int turn_conter;
	int player_index;

}GAME_INFO;

// 列挙型の定義 // 

typedef enum {
	TRUE,
	FALSE
}BOOL;

typedef enum {
	WIN,
	DRAW
}JUDGE;

#endif // DATA_H