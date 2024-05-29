#include <stdio.h>
#include <stdbool.h>
#include "display.h"
#include "general.h"
#include "game.h"

int main(void) {
  BOOL program_end = TRUE;
  enum GAME_CONTINUE_INSTRUCTION instruction = GAME_END;
  do {
    instruction = Show_GameTitle();
    if (instruction != GAME_END) {
      Play_Tic_Tac_Toe();
      instruction = GAME_START;
    } else {
      do {
        int game_end = Show_ExitGame();
        if (game_end == Y) {
          program_end = TRUE;
          instruction = GAME_END;
        } else if (game_end == N) {
          program_end = TRUE;
          instruction = GAME_START;
        } else {
          program_end = FALSE;
        }
      } while (program_end == FALSE);
    }
  } while (instruction == GAME_START);
  return 0;
}
  



