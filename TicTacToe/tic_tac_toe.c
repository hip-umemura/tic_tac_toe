//main�֐����L�q����\�[�X�t�@�C��

#include <stdio.h>
#include "tic_tac_toe.h"
#include "define.h"

//main�֐��̍쐬
int main(void)
{
    //�{�[�h���̉��쐬
    char a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = '1' + i * 3 + j;
        }
    }

    //Output_Info�֐��̌Ăяo��
    Output_Info(0);
    Output_Grid(a);
    Output_Result(O_WIN);
    Output_Result(X_WIN);
    Output_Result(DRAW);



    return 0;
}