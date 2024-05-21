//main関数を記述するソースファイル

#include <stdio.h>
#include "tic_tac_toe.h"

//main関数の作成
int main(void)
{
    //すぐ消す
    char a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = '1' + i * 3 + j;
        }
    }

    //Output_Info関数の呼び出し
    Output_Info(0, a);

    
    return 0;
}