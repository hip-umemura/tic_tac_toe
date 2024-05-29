#include "game.h"

SHOW_RESULT_INSTRUCTION Play_Tic_Tac_Toe(void) {

  // プレイヤーの情報を表す変数
  int player = PLAYER1;  

  // 現在の盤面の状態を表す任意の型の変数
  int current_board[ZHU_SIZE * ZHU_SIZE];

  // リザルト表示命令/ゲーム続行命令を表す変数
  SHOW_RESULT_INSTRUCTION display_result = GAME_CONTINUE;

  // Get_Input関数の返り値を受け取るint型変数
  int input_num = 0;

  // 盤面の初期化
  for (int i = 0; i < (ZHU_SIZE*ZHU_SIZE); i++) {
    current_board[i] = 0;
  }

  while (display_result == GAME_CONTINUE) {

    Show_Headder(TITLE, VERSION);

    Show_GameInfo(player,current_board);

    input_num = Get_Input();

    system("cls");

    if (isCorrectInput(input_num,current_board) == TRUE) {

      // マス目を入力情報とプレイヤー情報に基づいて更新
      if (player == PLAYER1) {
        current_board[input_num - '1'] = 'o';
      } else {
        current_board[input_num - '1'] = 'x';
      }

    } else {
      Suggest_Reinput();
      continue;
    }

    display_result = isGameEnded(player, current_board);

    if (display_result == GAME_CONTINUE) {
      // プレイヤーを交代する
      player *= -1;
    } else {
      Show_GameResult(display_result,current_board);
    }

  }
}

BOOL isCorrectInput(int mono_input,int* board) {
  BOOL correct_input = FALSE; 

  if (('1' <= mono_input) && (mono_input <= '9')) {
    correct_input = TRUE;
  }

  // 選択されたマス目に初期値以外の記号が入っているか
  if (board[mono_input - '1'] != 0) {
    correct_input = FALSE;
  }

  return correct_input;
}

void Suggest_Reinput(void) {

  // Get_Input関数の返り値を保存するint型変数
  int input_letter = 0;

  while (input_letter != '\r') {
    Show_Headder(TITLE, VERSION);

    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf("|                      正しいマス目を入力してください                       |\n");
    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf("|                         Press Enter to Next Input                         |\n");
    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf("|%*s|\n", TEXT_WIDTH - 1, " ");
    printf(" --------------------------------------------------------------------------- \n");

    input_letter = Get_Input();

    system("cls");
  }

}

GAME_CONTINUE_INSTRUCTION isGameStart(int mono_input) {

  // ゲーム開始命令/ゲーム終了命令/再入力命令を保存する列挙型変数
  GAME_CONTINUE_INSTRUCTION start_action = RE_INPUT;

  if (mono_input == Y) {
    start_action = GAME_START;
  }

  if (mono_input == N) {
    start_action = GAME_END;
  }

  return start_action;
}

SHOW_RESULT_INSTRUCTION isGameEnded(int player, int *board) {

  // リザルト表示命令/ゲーム続行命令を保存する列挙型の変数
  SHOW_RESULT_INSTRUCTION result_action = GAME_CONTINUE;

  // 空白が存在することを表す変数
  BOOL is_space = TRUE;

  for (int i = 0; i <= ZHU_SIZE - 1; i++) {

    // 行と列で勝利条件を満たしたか
    if (((board[i * ZHU_SIZE] == board[(i * ZHU_SIZE) + 1]) 
         && (board[(i * ZHU_SIZE) + 1] == board[(i * ZHU_SIZE) + 2]))
        && board[i * ZHU_SIZE] != 0) {

      result_action = ((player - PLAYER1) ? GAME_WIN_2 : GAME_WIN_1);

    } else if (((board[i] == board[ZHU_SIZE + i]) 
                && (board[ZHU_SIZE + i] == board[(ZHU_SIZE*2) + i]))
               && board[i] != 0) {

      result_action = ((player - PLAYER1) ? GAME_WIN_2 : GAME_WIN_1);

    } else {

      // ななめで勝利条件を満たしたか
      if (((board[i] == board[(ZHU_SIZE - 1)+(ZHU_SIZE - 1)]) 
            && (board[i] == board[(ZHU_SIZE * ZHU_SIZE - 1) - i]))
          && board[i] != 0) {

        result_action = ((player - PLAYER1) ? GAME_WIN_2 : GAME_WIN_1);

      }

    }

  }

  if(result_action == GAME_CONTINUE){
    //空白は存在するか
    for (int j = 0; j < ZHU_SIZE * ZHU_SIZE; j++) {

      if (board[j] == 0) {
        is_space = TRUE;
        break;
      } else {
        is_space = FALSE;
      }
    }
  }

  if (result_action == GAME_CONTINUE && is_space == FALSE) {
    result_action = GAME_DRAW;
  }

  //命令を格納した変数を返す
  return result_action;
}