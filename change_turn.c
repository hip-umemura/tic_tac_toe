TURN change_turn(TURN now) 
{
	printf("���ƌ��̃^�[������サ�܂�")
	if (now == FIRST_TURN) {
		return SECOND_TURN;
	}
	else {
		return FIRST_TURN;
	}

}
//game_progress�֐����ŌĂяo�����B
//now��FIRST_TURN�Ȃ�SECOND_TURN���A
// now��SECOND_TURN�Ȃ�FIRST_TURN��߂�l�Ƃ��ĕԂ��B
// �܂��A��サ���|��\������B