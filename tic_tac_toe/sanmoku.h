#define ELEMENT 9
#define WIDE_GAP 3
#define VERETICAL_GAP 3

typedef enum{
	TRUE,
	FALSE,
}BOOL;

typedef enum {
	CIRCLE,
	CROSS,
}TURN;



typedef enum {
	UNKNOWN,
	CIRCLE_WIN,
	CROSS_WIN,
	DROW,
}JUDGE;

typedef enum {
	TRY,
	QUIT,
	ERROR,
}RETRY;



