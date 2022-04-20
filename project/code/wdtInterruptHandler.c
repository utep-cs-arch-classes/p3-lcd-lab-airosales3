#include <msp430.h>
#include "libTimer.h"
#include "draw_sprites.h"
#include "lcdutils.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
    drawMenu();
  const  u_int second_limit = 250;
  static u_int second_count = 0;

  second_count++;

  if (second_count >= second_limit) {
    drawBg();
    second_count = 0;
  }
} 

