#include <stdio.h>
#include "enum.h"
#include "player_change.h"

PLAYER PlayerChange(PLAYER player)
{
	if (player == PLAYER1) {
		return PLAYER2;
	}
	else {
		return PLAYER1;
	}
}
