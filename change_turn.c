TURN change_turn(TURN now) 
{
	printf("先手と後手のターンを交代します")
	if (now == FIRST_TURN) {
		return SECOND_TURN;
	}
	else {
		return FIRST_TURN;
	}

}
//game_progress関数内で呼び出される。
//nowがFIRST_TURNならSECOND_TURNを、
// nowがSECOND_TURNならFIRST_TURNを戻り値として返す。
// また、交代した旨を表示する。