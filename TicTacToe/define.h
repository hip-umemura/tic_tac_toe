#pragma once

//}Nθ`
//ΥΚΜvfπ\·}N
#define GRID_HEIGHT	3
#define GRID_WIDTH	3

//ρ^θ`
//Q[Μsπ¦·ρ^
typedef enum {
	CONTINUE,
	O_WIN,
	X_WIN,
	DRAW,
} RESULT;

//^[π¦·ρ^
typedef enum {
	O_TURN,
	X_TURN,
} TURN;

//^Uπ¦·ρ^
typedef enum {
	FALSE,
	TRUE,
} BOOL;

//\’Μθ`
//zρΜvfΜINDEXπi[·ι\’Μ
typedef struct {
  int x;
  int y;
} INDEX;