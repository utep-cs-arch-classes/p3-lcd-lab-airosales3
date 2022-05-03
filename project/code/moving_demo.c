#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "led.h"
#include "draw_shapes.h"

u_int backgroundColor = COLOR_BLUE;
// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 


void main()
{
  configureClocks();
  lcd_init();
  switch_p2_init();
  clearScreen(COLOR_BLACK);
  initBgValues();
  enableWDTInterrupts();
  
  or_sr(0x18);	/**< CPU off , GIE on*/
  //drawRalsei(43,23, ralsei_idle);
  
  
  //Guess I will have to make an individual function for this
}



