#pragma once

//�}�N����`
//�Ֆʂ̗v�f����\���}�N��
#define GRID_HEIGHT	3
#define GRID_WIDTH	3



//�񋓌^��`
//�Q�[���̏��s�������񋓌^
typedef enum {
	CONTINUE,
	O_WIN,
	X_WIN,
	DRAW,
} RESULT;

//�^�[���������񋓌^
typedef enum {
	O_TURN,
	X_TURN,
} TURN;

//�^�U�������񋓌^
typedef enum {
	FALSE,
	TRUE,
} BOOL;

//�\���̒�`
//�z��̗v�f��INDEX���i�[����\����
typedef struct {
  int x;
  int y;
} INDEX;