#pragma once

// �}�N����`
// �Ֆʂ̗v�f����\���}�N��
#define GRID_HEIGHT	3
#define GRID_WIDTH	3
#define PLAYER_NUM	2
#define TURN_PLAYER(turn) turn % PLAYER_NUM
#define ERROR      -1
#define LINE_NUM		2
#define INPUT_LEN		2

// �񋓌^��`
// �Q�[���̏��s������
typedef enum {
	CONTINUE,
	WIN,
	DRAW,
} RESULT;

// �^�U������
typedef enum {
	FALSE,
	TRUE,
} BOOL;

// �\���̒�`
// �z��̗v�f��INDEX���i�[����
typedef struct {
  int x;
  int y;
} INDEX;