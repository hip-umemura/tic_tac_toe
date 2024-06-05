#include <stdio.h>

void Print_Grid(const char* board)
{
  int i, j;
  
  printf("y.x| 0 | 1 | 2 \n");
  for (i = 0; i <= 2; i++) {
    printf("---|---|---|---\n");
    printf(" %d |", i);
    for (j = 0; j <= 1; j++) {
      printf(" %c |", *(board + (i * 3) + j));
    }
    printf(" %c \n", *(board + (i * 3) + j));
  }
  printf("---|---|---|---\n");
}
