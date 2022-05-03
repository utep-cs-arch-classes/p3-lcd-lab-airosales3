#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

background bg;

u_int colorId(int id)
{
    switch(id)
    {
        case 1:
            return COLOR_BLACK;
            break;
        
        case 2:
            return COLOR_FOREST_GREEN;
            break;
        
        case 3:
            return COLOR_DARK_GREEN;
            break;
        
        case 4:
            return COLOR_MAGENTA;
            break;
            
        case 5:
            return COLOR_WHITE;
            break;
            
        case 6:
            return COLOR_CHOCOLATE;
            break;
            
        case 7:
            return COLOR_GRAY;
        break;
        
        default:
            return 0;
            break;
    }
}


void drawRalsei(int height, int width, int sprite[height][width])
{
    int y = 0;
    int x = 0;
    int c_x = (screenWidth/3) + 10;   //This is used for centering the image
    int c_y = (screenHeight/4) + 5;   //Same as before
    int colorP = 0;//It basically gets a color id from a certain sprite, idle sprite by default
    u_int currentColor = COLOR_BLUE; //Initialize the color to smething by default
    
    while(y < height)
    {
        
        while(x < width)
        {
            colorP = sprite[y][x];
            currentColor = colorId(colorP);
            drawPixel(x + c_x, y + c_y, currentColor);
            x++;
        }
        y++;
        x = 0;
    }
    
    //Now, the color will depend on what color we are sending, that should be on the draw_shape code
    //drawPixel(rcol + c, rrow + c, currentColor); //Offsets and current color
    
}

void drawMenu()
{
    u_int color_1 = COLOR_BLACK;
    u_int color_2 = COLOR_ORANGE;
    
  //clearScreen(color_1);
  
  drawString5x7(5,145,"Fight",color_2, color_1);
  drawString5x7(40,145,"Sing",color_2, color_1);
  drawString5x7(68,145,"Defend",color_2, color_1);
  drawString5x7(108,145,"Pet",color_2, color_1);
    
  
}

void drawText(int state)
{
    u_int color_1 = COLOR_BLACK;
    u_int color_2 = COLOR_WHITE;
    //fillRectangle(0,122,screenWidth,20,COLOR_BLACK);
    
    switch(state)
    {
        
        case 0:
         drawString5x7(0,122,"*Ralsei patiently",color_2, color_1);
         drawString5x7(0,132,"awaits your orders... ",color_2, color_1);
         break;
         
        case 1:
            drawString5x7(0,122,"*Ralsei brings out",color_2, color_1);
         drawString5x7(0,132,"the pain! ",color_2, color_1);
            break;
            
        case 2:
            drawString5x7(0,122,"*Ralsei used sing!",color_2, color_1);
         drawString5x7(0,132,"It's super effective?",color_2, color_1);
            break;
            
        case 3:
            drawString5x7(0,122,"*Ralsei defends! ...",color_2, color_1);
         drawString5x7(0,132,"but there is no enemy",color_2, color_1);
            break;
            
        case 4:
            drawString5x7(0,122,"*You pet the goat...",color_2, color_1);
         drawString5x7(0,132,"Floof",color_2, color_1);
            break;
    }
}

void initBgValues(void)
{
    bg.x = 0;
    bg.y = 0;
    bg.grid_size_x = 0;
    bg.grid_size_y = 0;
    //clearScreen(COLOR_BLACK);
    //drawBg();
    
}


void updateBgValues(void)
{
    u_int bgColor = COLOR_BLACK;
    //clearScreen(bgColor); //Clear current screen
    drawHorLine(0,(bg.y - 1), bgColor); //Clear old hor lines
    drawVerLine((bg.x - 1) , 0, bgColor); //Clear old ver lines

    
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
    
    drawBg(bg.x, bg.y);
    
    bg.grid_size_x ++;
    bg.grid_size_y ++;
    

    
}

void drawBg(u_char x, u_char y)
{
    
    u_int color = COLOR_DARK_VIOLE;
    //clearScreen(COLOR_BLACK);
    
    drawHorLine(0, y, color);

    drawVerLine(x, 0, color); 
    
}
