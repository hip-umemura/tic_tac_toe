#include <stdio.h>
#include <assert.h>
#include "enum.h"
#include "retry.h"
#include "error.h"

RETRY_JUDGE Retry(char input)
{
	if (input == '1') {
		return RETRY;
	}
	else if (input == '2') {
		return FINISH;
	}
	else {
		assert(0);
	}
}

