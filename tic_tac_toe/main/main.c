#include <stdio.h>
#include "enum.h"
#include "input.h"
#include "output.h"
#include "judge.h"

int main(void) {
  int row;
  int column;
  TURN player_turn = TURN_PLAYER1;
  RESULT result = RESULT_NONE;
  // ”Õ–Ê‚Ì‰Šú‰»
  BoardInit();
  // ”Õ–Ê•\¦
  PrintBoard();
  do {
    // “ü—Í‚ğ‹‚ß‚é
    PlayerInput(&row, &column, player_turn);
    // ‹L†‚ğŠi”[
    BoardUpdate(row, column, player_turn);
    // ”Õ–Ê•\¦
    PrintBoard();
    // Ÿ”s”»’è
    result = ResultJudge(player_turn);
    // è”Ô‚ğis
    player_turn = NextTurn(player_turn);
  } while (result == RESULT_NONE);
  // Ÿ”s‚ÌŒ‹‰Ê‚ğ•\¦
  PrintResult(result);

  return 0;
}