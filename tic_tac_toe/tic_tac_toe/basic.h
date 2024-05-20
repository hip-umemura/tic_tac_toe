#define NAME_LEN (10)	//プレイヤー名の長さ上限
#define FALSE (0)	//“FALSE”を0とする
#define TRUE (1)	 //“TRUE”を1とする

typedef enum
{
	FIRST_TURN,
	SECOND_TURN,
} TURN;

typedef struct 
{
	char* name; //player名
	char piece; //駒
} PLAYER;