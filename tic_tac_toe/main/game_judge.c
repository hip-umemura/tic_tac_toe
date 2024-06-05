#include <stdio.h>
#include <stdlib.h>

typedef struct BOARD_XY {
  int x;
  int y;
} BOARD_XY;

typedef enum {
  NONE,
  WIN,
  DRAW
} RESULT;

RESULT Game_Judge(const int turn_count, const BOARD_XY input_xy, const char* board)
{
  if (((input_xy.x < 0) || (input_xy.x >= 3)) || ((input_xy.y < 0) || (input_xy.y >= 3)) || ((turn_count < 0) || (turn_count >= 10))) {
    exit(64);
  }

  if (turn_count >= 5) {
    if ((*(board + (0 * 3) + input_xy.x) == *(board + (1 * 3) + input_xy.x)) && (*(board + (1 * 3) + input_xy.x) == *(board + (2 * 3) + input_xy.x))) {
      return WIN;
    }
    else if ((*(board + (input_xy.y * 3) + 0) == *(board + (input_xy.y * 3) + 1)) && (*(board + (input_xy.y * 3) + 1) == *(board + (input_xy.y * 3) + 2))) {
      return WIN;
    }
    else if (((*(board + (0 * 3) + 0) == *(board + (1 * 3) + 1)) && (*(board + (1 * 3) + 1) == *(board + (2 * 3) + 2))) ||
             ((*(board + (0 * 3) + 2) == *(board + (1 * 3) + 1)) && (*(board + (1 * 3) + 1) == *(board + (2 * 3) + 0)))) {
      return WIN;
    }
    else if (turn_count == 9) {
      return DRAW;
    }
  }
  return NONE;
}