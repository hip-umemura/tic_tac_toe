#include<stdio.h>
#define TRUE 1
#define FALSE 0

int retry_game(void){
    char userInput;
    printf("�ăv���C����'����(YES...1 / No...1�ȊO):");
    scanf_s("%c", &userInput, 1);
    if(userInput == '1') {
        //printf("1");
        return TRUE;
    } else {
        //printf("0");
        return FALSE;
    }
}
int main() {
    retry_game();
    
}
//main�֐����ŌĂяo�����B���[�U���͂��󂯍ăv���C���邩���߂�B
// ���[�U���͂�1�̏ꍇ�ATRUE��߂�l�Ƃ��ĕԂ��A1�ȊO�̏ꍇFALSE��Ԃ��B