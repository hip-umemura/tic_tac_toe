#include<stdio.h>

#include "define.h"
#include "get_result.h"

//���ʂ��o��
void GameResult(int result)
{
	if (result == O_WIN) {
		printf("O�������܂����I");
	}
	else if (result == X_WIN) {
		printf("X�������܂����I");
	}
	else if (result == DROW) {
		printf("���������ł����B");
	}

}

//������x�V�Ԃ��I��
EXIT PlayAgain(void){

	int exit = 0;
	int try = 0;
	
	printf("������x�V�ԁc0/��߂�c0�ȊO�F");
	scanf_s("%d", &exit);

	if (exit == 0) {
		try = CONTINUE;
	}
	else {
		try = END;
	}
	return try;
}