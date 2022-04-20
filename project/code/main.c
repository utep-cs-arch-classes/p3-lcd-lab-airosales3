#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_sprites.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
    
  configureClocks();
  lcd_init();
  enableWDTInterrupts();
  
  clearScreen(COLOR_BLACK);
  initBgValues();
  drawMenu();
  or_sr(0x10);	/**< CPU OFF */
}
