#include <stdio.h>
#include "select.h"

//三目並べスタート選択関数
SELECT StartEnd() {
    int  num_input;
    int input_length;
    char char_input[2] = {""};
    printf(" ______________________________ \n\n\n\n");
    printf("           三目並べ         \n");
    while (1) {
        printf("         Start  [y/n] :");
        input_length = 0;
        while ((num_input = getchar()) != '\n' && num_input != EOF) {
            input_length++;
            char_input[0] = num_input;
        }

        if (input_length != 1) {
            InputError();
            continue;
        }

        if (char_input[0] == 0x79) {
            printf("\n\n ______________________________ \n");
            return START;
        }
        else if (char_input[0] == 0x6e) {
            printf("\n\n ______________________________ \n");
            return END;
        }
        else {
            InputError();
            continue;
        }
    }
}

//再戦選択関数
SELECT Rematch() {
    int  num_input;
    int  input_length;
    char char_input[2] = {""};
    while(1) {
        printf("       Continue?  [y/n] :");
        input_length = 0;
        while ((num_input = getchar()) != '\n' && num_input != EOF) {
            char_input[0] = num_input;
            input_length++;
        }

        if (char_input[0] == 0x79) {
            return START;
        } else if (char_input[0] == 0x6e) {
            return END;
        } else {
            InputError();
            continue;
        }
    }
    printf("\n\n ______________________________ \n");
}
