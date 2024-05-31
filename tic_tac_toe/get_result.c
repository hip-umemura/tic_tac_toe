#include<stdio.h>

#include "define.h"
#include "get_result.h"

//結果を出力
void GameResult(int result)
{
	if (result == O_WIN) {
		printf("Oが勝ちました！");
	}
	else if (result == X_WIN) {
		printf("Xが勝ちました！");
	}
	else if (result == DROW) {
		printf("引き分けでした。");
	}

}

//もう一度遊ぶか選択
EXIT PlayAgain(void){

	int exit = 0;
	int try = 0;
	
	printf("もう一度遊ぶ…0/やめる…0以外：");
	scanf_s("%d", &exit);

	if (exit == 0) {
		try = CONTINUE;
	}
	else {
		try = END;
	}
	return try;
}