

void print_result(RESULT result, Player player)
{
	if (result == DRAW){
		printf("引き分け！");
	}
	else if (result == WIN){
		print("%pさんの勝利！\n, player");
	}
}

int main(void) {
	void print_result(RESULT result, Player player);
}


//game_progress関数内で呼び出される。
// 引数のresultに応じてゲーム結果を表示する。
//また、勝利条件の際(resultがWIN)はプレイヤー名を表示する。