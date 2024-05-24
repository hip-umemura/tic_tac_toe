//main関数を記述するソースファイル

#include <stdio.h>
#include "tic_tac_toe.h"
#include "define.h"

//main関数の作成
int main(void)
{
    //ボード情報の仮作成
    char a[3][3];
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = '7' - i * 3 + j;
        }
    }

    //Output_Info関数の呼び出し
    Output_Info(0);
    Output_Grid(a);
    Output_Result(O_WIN);
    Output_Result(X_WIN);
    Output_Result(DRAW);

    //仮
    Insert(&a[0][1], 0);
    Output_Grid(a);




    return 0;
}