#include <stdio.h>
#include "display.h"
#include "select.h"

void main() {
    RESULT result = NONE_WINNER;
    SELECT select = StartEnd();

    while (select == START) {
        result = GameBoard();
        if (result == R_RESET) {
            select = StartEnd();
        }
    }
}