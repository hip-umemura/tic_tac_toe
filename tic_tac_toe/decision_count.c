#include <stdio.h>
#include "sanmoku.h"
#include "input_num.h"

BOOL RangeNum(int input) {
	BOOL in_range;
	if (input >= 1 && input <= 9) {
		in_range = TRUE;
	}
	else {
		in_range = FALSE;
	}
}

BOOL CheckNum(int input, int* p) {
	BOOL ischeck;
	if (*(p + input) == input) {
		ischeck = TRUE;
	}
	else {
		printf("”ÍˆÍ“à‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B");
		ischeck = FALSE;
	}
	return ischeck;
}

JUDGE CheckWin(int p[9]) {
	for (int i = 0; i < 3; (i + i * 2)) {

	}
}