void view_tutorial(void)
{
	printf("チュートリアル開始！\n\n");
	printf("\x1b[36mまずは、先手になる人が入力しましょう！\n");
	printf("入力は半角英数字10文字で！\x1b[39m\n");
	printf("先手のプレイヤー名を入力してください：a\n");
	printf("\x1b[36m次に後手になる人が入力しましょう！\x1b[39m\n");
	printf("後手のプレイヤー名を入力してください：あ\n");
	printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
	printf("後手のプレイヤー名を入力してください：b\n");
	printf("現在の盤面を表示します\n");
	printf("　 1   2   3\n");
	printf(" -------------\n");
	printf("1|   |   |   |\n");
	printf(" -------------\n");
	printf("2|   |   |   |\n");
	printf(" -------------\n");
	printf("3|   |   |   |\n");
	printf(" -------------\n\n");
	printf("\x1b[36m入力は〇行〇列で入力しましょう！数字と数字の間は半角スペース！\x1b[39m\n");
	printf("aさん、駒を置く座標を入力してください：1 2\n");
	printf("　 1   2   3\n");
	printf(" -------------\n");
	printf("1|   | O |   |\n");
	printf(" -------------\n");
	printf("2|   |   |   |\n");
	printf(" -------------\n");
	printf("3|   |   |   |\n");
	printf(" -------------\n\n");
	printf("駒を配置しました！\n");
	printf("先手と後手を交代します\n\n");
	printf("\x1b[36m先手の行動が終わったら後手の行動です！\x1b[39m\n");
	printf("ｂさん、駒を置く座標を入力してください：1 2\n");
	printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
	printf("ｂさん、駒を置く座標を入力してください：4 1\n");
	printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
	printf("ｂさん、駒を置く座標を入力してください：2 2\n");
	printf("　 1   2   3\n");
	printf(" -------------\n");
	printf("1|   | O |   |\n");
	printf(" -------------\n");
	printf("2|   | X |   |\n");
	printf(" -------------\n");
	printf("3|   |   |   |\n");
	printf(" -------------\n");
	printf("駒を配置しました！\n");
	printf("先手と後手を交代します\n");
	printf("\x1b[36m以下、先手と後手を交代して行います！\n\n");
	printf("パターン１：列がそろった場合\x1b[39m\n");
	printf("aさん、駒を置く座標を入力してください：2 3\n");
	printf("　 1   2   3\n");
	printf(" -------------\n");
	printf("1| X | O | O |\n");
	printf(" -------------\n");
	printf("2|   | X | O |\n");
	printf(" -------------\n");
	printf("3| X |   | O |\n");
	printf(" -------------\n");
	printf("駒を配置しました！\n");
	printf("aさんの勝利！\n\n\n");
	printf("\x1b[36mパターン2：マスが埋まった場合\x1b[39m\n");
	printf("aさん、駒を置く座標を入力してください：3 3\n");
	printf("　 1   2   3\n");
	printf(" -------------\n");
	printf("1| X | X | O |\n");
	printf(" -------------\n");
	printf("2| O | O | X |\n");
	printf(" -------------\n");
	printf("3| X | O | O |\n");
	printf(" -------------\n");
	printf("引き分け！\n\n\n");
	printf("\x1b[36mパターン3: 入力座標が不正な場合\x1b[39m\n");
	printf("aさん、駒を置く座標を入力してください：4 1\n");
	printf("\x1b[31m不正な入力です。再度入力してください！\x1b[39m\n");
}