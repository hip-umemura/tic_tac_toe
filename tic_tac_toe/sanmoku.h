#define ELEMENT 9
#define BOARD_LEN 3
#define MATCH_COUNTER 2

typedef enum{
	TRUE,
	FALSE,
}BOOL;

typedef enum {
	CIRCLE,
	CROSS,
}JUDGE;



typedef enum {
	UNKNOWN,
	CIRCLE_WIN,
	CROSS_WIN,
	DROW,
}JUDGE;

typedef enum {
	TRY,
	QUIT,
}RETRY;



