#include "define.h"
//“ü—Íˆø”‚Ì’l‚É‘Î‰‚µ‚½ƒOƒŠƒbƒh‚ª‚Ç‚Ì—v‘f‚È‚Ì‚©‚ğ’Tõ‚µA‚»‚Ì—v‘f‚ğ•Ô‚·ŠÖ”
INDEX Search(char input_info, char board_info[3][3]) {
  int x = 0;
  int y = 0;
  // input_integer
  int input_integer = input_info - '0';
  int const y_max = 3;
  int const x_max = 3;

  for (y = 0; y < y_max; y++) {
    //s•ûŒü‚Ì‘–¸‚ğ—v‘f”-1‰ñs‚¤
    for (x = 0; x < x_max - 1; x++) {
      if (board_info[y][x] == input_info) {
        break;
      }
    }
    //ˆê’v‚µ‚½—v‘f‚ª‚ ‚é‚©AÅŒã‚Ì—v‘f‚ªˆê’v‚µ‚½ê‡break
    if (board_info[y][x] == input_info) {
      break;
    }
  }

  // —v‘f‚ğ2ŸŒ³”z—ñ‚É“K‚·‚é‚æ‚¤‚É\‘¢‘Ì‚ÉŠi”[‚·‚é
  INDEX index = {x, y};
  return index;
}