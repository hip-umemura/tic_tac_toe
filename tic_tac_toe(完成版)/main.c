/*
  三目並べ(設計：Lチーム  コーディング：Cチーム)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// マクロ定義
#define TRUE       1
#define FALSE      0
#define WIN        2
#define DRAW       3
#define CONTINUES -1
#define BOARDSIZE  3
#define ARRAYSIZE  2 // 配列サイズ 

// ルール説明
void DisplayRule() {
  printf("ルール説明                           \n");
  printf("─────────────────────────────────────\n");
  printf(" 横軸[1, 2, 3]＋Enterと              \n");
  printf(" 縦軸[1, 2, 3]＋Enterと              \n");
  printf(" 〇×を置く位置を入力してください    \n");
  printf("─────────────────────────────────────\n");
  printf("\n\n");
}

// 3*3の盤面の状況表示
void DisplayScreen(char board[BOARDSIZE][BOARDSIZE]) {
  printf("  1   2   3\n");
  printf("-------------\n");
  for (int i = 0; i < BOARDSIZE; i++) {
    for (int j = 0; j < BOARDSIZE; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("| %d\n", i + 1);
    printf("-------------\n");
  }
}

// 縦軸の入力
char InputVerticalAxis(void) {
  char input[ARRAYSIZE];  // 文字列を格納する変数(要素数2)
  printf("選択するマスの縦軸を入力してください：");
  scanf_s("%s", input, (int)sizeof(input));  // 入力を配列に格納
  while (getchar() != '\n')
    ;
  return input[0];  // 文字列の0番目を文字として返す
}

// 横軸の入力
char InputHorizontalAxis(void) {
  char input[ARRAYSIZE];  // 文字列を格納する変数(要素数2)
  printf("選択するマスの横軸を入力してください：");
  scanf_s("%s", input, (int)sizeof(input));
  while (getchar() != '\n')
    ;
  return input[0];
}

// 入力を整数値に変換
int ConvertingInputToInt(char input) {       
  int input_to_int;
  if ((input == '1') || (input == '2') || (input == '3')) {  // inputが1or2or3
    input_to_int = input - '0'; // 整数値変換
    return input_to_int;
  }
  else {
    printf("\033[41m1,2,3で入力してください！\033[0m\n");   // 背景色を赤にして表示
    return FALSE;
  }
}

//盤面の配列にOXが入っていないかの判定
int isNotAlreadyPlaced(int vertical, int horizontal, char board[BOARDSIZE][BOARDSIZE]) {
  assert(vertical > 0 && vertical < 4 && horizontal > 0 && horizontal < 4); // 強制終了

  if (board[vertical - 1][horizontal - 1] == ' ') { // 指定した座標が空いている
    return TRUE;
  }
  else {
    printf("\033[41mすでに置かれています！\033[0m\n");      // 背景色を赤にして表示
    return FALSE;
  }
  
}

// OXを配置する
void StoringInput(int vertical, int horizontal, char turn, char *board) {
  assert(vertical > 0 && vertical < 4 && horizontal > 0 && horizontal < 4); // 強制終了

  board[(vertical - 1) * BOARDSIZE + (horizontal - 1)] = turn;
}

// 勝ち、引き分け、続行の判定
int isWinDrawContinues(int vertical, int horizontal, char board[BOARDSIZE][BOARDSIZE]) {
  assert(vertical > 0 && vertical < 4 && horizontal > 0 && horizontal < 4); // 強制終了

  int count_free = 0; // 空いているマスの数
  // 縦または横にOXが揃っているか
  if ((board[vertical - 1][1] != ' ') && (board[vertical - 1][0] == board[vertical - 1][1]) && (board[vertical - 1][1] == board[vertical - 1][2])) {  // 横に揃っているか
    return WIN;
  }
  if ((board[1][horizontal - 1] != ' ') && (board[0][horizontal - 1] == board[1][horizontal - 1]) && (board[0][horizontal - 1] == board[2][horizontal - 1])) {  // 縦に揃っているか
    return WIN;
  }
  if ((board[1][1] != ' ') && (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) ||
    board[0][2] == board[1][1] && board[1][1] == board[2][0])) {  // 斜めに揃っているか
    return WIN;
  }

  // 空いているマスの数を計算
  for (int i = 0; i < BOARDSIZE; i++) {
    for (int j = 0; j < BOARDSIZE; j++) {
      if (board[i][j] == ' ') {
        count_free++;
      }
    }
  }
  if (count_free == 0) {  // 全てのマスが埋まっている
    return DRAW;
  }
  else {
    return CONTINUES;
  }

}

// プレイヤーのターンを入れ替える
char PlayerChange(char turn) {
  char player_turn; // 現在のターン
  if (turn == 'O') {
    player_turn = 'X';
  }
  else {
    player_turn = 'O';
  }
  return player_turn;
}

// 引き分け表示
void DrowOutput(void) {
  printf("Draw\n");
}

// プレイヤーターン表示
void PlayerTurnOutput(char turn) {
  printf("Player:%c\n", turn);
}

// 勝利表示
void WinnerOutput(char turn) {
  PlayerTurnOutput(turn);
  printf("WIN!\n");
}

// 実行用関数
int main(void)
{
  int flag = FALSE;         // 終了フラグ
  char turn = 'O';         // プレイヤーターン
  char board[BOARDSIZE][BOARDSIZE] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} }; // 盤面
  char input_vertical;     // 縦軸の入力
  char input_horizontal;   // 横軸の入力
  int vertical;            // 縦軸の整数
  int horizontal;          // 横軸の整数

  printf("\x1b[30;47m");   // 文字色・背景色変更
  // ルール出力
  DisplayRule();
  printf("\x1b[0m");       // デフォルトに戻す

  while (flag == FALSE) {  // flagがTRUEになるまでループ処理
    DisplayScreen(board);  // 画面出力
    PlayerTurnOutput(turn);                   // ターン出力
    input_horizontal = InputHorizontalAxis(); // 横軸入力
    input_vertical = InputVerticalAxis();     // 縦軸入力

    printf("\033[8;0H \033[0J\n");            // カーソルの位置移動&画面クリア
    
    // 整数変換＆入力が正しいか判断
    horizontal = ConvertingInputToInt(input_horizontal);
    if (horizontal == FALSE) {
      continue;
    }
    vertical = ConvertingInputToInt(input_vertical);
    if (vertical == FALSE) {
      continue;
    }
    // 既に置かれているか
    if (isNotAlreadyPlaced(vertical, horizontal, board) == FALSE) {
      continue;
    }

    StoringInput(vertical, horizontal, turn, *board); // 駒を配置

    // 勝敗判定
    if (isWinDrawContinues(vertical, horizontal, board) == WIN) {           // 勝利判定
      DisplayScreen(board);
      WinnerOutput(turn);
      flag = TRUE;
    }
    else if (isWinDrawContinues(vertical, horizontal, board) == DRAW) {     // 引き分け判定
      DisplayScreen(board);
      DrowOutput();
      flag = TRUE;
    }
    else {                                                                  // 継続判定
      turn = PlayerChange(turn);  // ターンを入れ替える
    }
  }
  return 0;
}