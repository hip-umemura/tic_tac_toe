

void print_result(RESULT result, Player player)
{
	if (result == DRAW){
		printf("���������I");
	}
	else if (result == WIN){
		print("%p����̏����I\n, player");
	}
}

int main(void) {
	void print_result(RESULT result, Player player);
}


//game_progress�֐����ŌĂяo�����B
// ������result�ɉ����ăQ�[�����ʂ�\������B
//�܂��A���������̍�(result��WIN)�̓v���C���[����\������B