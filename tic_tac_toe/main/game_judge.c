#include <stdio.h>

typedef struct BOARD_XY {
  int x;
  int y;
} BOARD_XY;

typedef enum {
  NONE,
  WIN,
  DRAW
} RESULT;

RESULT Game_Judge(const int turn_count, const BOARD_XY input_xy, const char* board_status)
{
  if (turn_count >= 5) {
    if ((*(board_status + (0 * 3) + input_xy.x) == *(board_status + (1 * 3) + input_xy.x)) && (*(board_status + (1 * 3) + input_xy.x) == *(board_status + (2 * 3) + input_xy.x))) {
      return WIN;
    }
    else if ((*(board_status + (input_xy.y * 3) + 0) == *(board_status + (input_xy.y * 3) + 1)) && (*(board_status + (input_xy.y * 3) + 1) == *(board_status + (input_xy.y * 3) + 2))) {
      return WIN;
    }
    else if (((*(board_status + (0 * 3) + 0) == *(board_status + (1 * 3) + 1)) && (*(board_status + (1 * 3) + 1) == *(board_status + (2 * 3) + 2))) ||
             ((*(board_status + (0 * 3) + 2) == *(board_status + (1 * 3) + 1)) && (*(board_status + (1 * 3) + 1) == *(board_status + (2 * 3) + 0)))) {
      return WIN;
    }
    else if (turn_count == 9) {
      return DRAW;
    }
  }
  return NONE;
}