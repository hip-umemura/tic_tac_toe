#define ELEMENT 9

typedef enum{
	TRUE,
	FALSE,
}BOOL;

typedef enum {
	CIRCLE,
	CROSS
}TURN;

typedef enum {
	UNKNOWN,
	CIRCLE_WIN,
	CROSS_WIN
}JUDGE;
// DROW書いてたけどいらない

typedef enum {
	TRY,
	QUIT,
	ERROR
}RETRY;

typedef enum {
	END,
	EXTEND
}CONTINUE;



