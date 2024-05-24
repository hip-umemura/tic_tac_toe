#include<stdio.h>


	int main(void) {
		char a[4];
		for (int i = 0; i < 3; i++) {
			printf("a");
			scanf_s("%[^\n]s", a,4);
			printf("%s\n", a);
		}

	}
