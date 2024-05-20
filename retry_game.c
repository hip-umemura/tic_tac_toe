#include<stdio.h>
#define TRUE 1
#define FALSE 0

int retry_game(void){
    char userInput;
    printf("再プレイしま'すか(YES...1 / No...1以外):");
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
//main関数内で呼び出される。ユーザ入力を受け再プレイするか決める。
// ユーザ入力が1の場合、TRUEを戻り値として返し、1以外の場合FALSEを返す。