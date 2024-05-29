#include "general.h"

void Show_Headder(char title[], char version[]) {
  
  printf(" ---------------------------------------------------------------------------- \n");
  printf("| %s%*s%s |\n", title, TEXT_WIDTH - ((int)sizeof(TITLE)) - ((int)sizeof(VERSION)), " ", version);
  
  printf(" ---------------------------------------------------------------------------- \n");
}

int Get_Input(void) {
  char mono_input;
  mono_input = _getch();
  return mono_input;
}