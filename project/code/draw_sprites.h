#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <lcdutils.h>

typedef struct bg_st {
  u_char x;
  u_char y;
  int grid_size_x;
  int grid_size_y;
} background;

void initBgValues(void);
void updateBgValues(void);
void drawBg(void);
void drawMenu(void);
void drawSprite(void);

#endif // _DRAW_SHAPES_H_
