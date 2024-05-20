#include <stdio.h>
#include <ctype.h>

#include "tutorial.h"
#include "basic.h"

int retry_game(void) {
  return FALSE;
}

void game_progress(char* name1, char* name2) {
  
}

int main(void) {
  int start_tutorial;
  char name1[NAME_LEN];
  char name2[NAME_LEN];
  int name_array;

  printf("チュートリアルを見ますか(YES...1 / NO...1以外)：");
  scanf_s("%d", &start_tutorial);
  fflush(stdin);

  if (start_tutorial == TRUE) {
	view_tutorial();
  }

  printf("ゲーム開始！");

  do{
	name_array = 0;

	printf("先手のプレイヤー名を入力してください：");
	scanf_s("%s", name1, NAME_LEN);

	do {
	  if (!islower(name1[name_array])) {
		printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
		break;
	  }
	  name_array++;
	} while (name1[name_array] != '\0');

	while (getchar() != '\n')
	  ;

  } while (name1[name_array] != '\0' || name_array == 0);

  do {
	name_array = 0;

	printf("後手のプレイヤー名を入力してください：");
	scanf_s("%s", name2, NAME_LEN);

	do {
	  if (!islower(name2[name_array])) {
		printf("\x1b[31m半角英数字10字以内で入力してください！\x1b[39m\n");
		break;
	  }
	  name_array++;
	} while (name2[name_array] != '\0');

	while (getchar() != '\n')
	  ;

  } while (name2[name_array] != '\0' || name_array == 0);

  do
  {
	game_progress(name1, name2);
  } while (retry_game() == TRUE);

  return 0;
}