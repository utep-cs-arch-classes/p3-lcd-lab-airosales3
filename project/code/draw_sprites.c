#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_sprites.h"

background bg;

void drawSprite(void)
{
  int height = 43;
  int width = 26;
  
  //drawRalsei(width, height, color_1);
  

}

void drawMenu(void)
{
    u_int color_1 = COLOR_BLACK;
    u_int color_2 = COLOR_ORANGE;
    
  //clearScreen(color_1);
  
  drawString5x7(5,145,"Fight",color_2, color_1);
  drawString5x7(40,145,"Sing",color_2, color_1);
  drawString5x7(68,145,"Defend",color_2, color_1);
  drawString5x7(108,145,"Pet",color_2, color_1);
    
}



void initBgValues(void)
{
    bg.x = 0;
    bg.y = 0;
    bg.grid_size_x = 0;
    bg.grid_size_y = 0;
    
    //drawBg();
    
    
}


void updateBgValues(void)
{
    u_int color = COLOR_DARK_VIOLE;
    
    
    if(bg.grid_size_x >= 20)
    {
        bg.y = 0;
        bg.grid_size_x = 0;
    }
    
    if(bg.grid_size_y >= 20)
    {
        bg.x = 0;
        bg.grid_size_y = 0;
    }
    
    bg.x++;
    bg.y++;
    
    
    drawHorLine(0, bg.y, color);
    drawVerLine(bg.x, 0, color); 
    
    bg.grid_size_x ++;
    bg.grid_size_y ++;
    
    
}

void drawBg(void)
{
    
    u_int bgColor = COLOR_BLACK;
    
    drawHorLine(0,(bg.y - 1), bgColor); //Clear old hor lines
    drawVerLine((bg.x - 1) , 0, bgColor); //Clear old ver lines
    
    //updateBgValues(); //Update and draw the new bg
    
}
