#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "led.h"
#include "draw_sprites.h"
#include "state_machine.h"
#include "buzzer.h"

int state = 0;
static u_int idle_limit = 25;
static u_int idle_seconds = 0;

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 2;
  static u_int second_count = 0;

  second_count++;
  stateCheck(state);
  drawMenu();
  drawText(state);
  
  
  if (second_count >= second_limit) //This one is in charge of the bg
  {
    second_count = 0;
     updateBgValues();
  }
  
  if(state != 0)
  {
      idle_seconds++;
      
      if(idle_seconds >= idle_limit)
      {
          state = 0;
          fillRectangle(0,122,screenWidth,20,COLOR_BLACK);
          buzzer_set_period(0);
      }   
  }
  
  port2_c_handler();
}

void
port2_c_handler(void){
    
  if (P2IFG & P2_SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~P2_SWITCHES;	      /* clear pending sw interrupts */
    check_p2_switches();	      /* single handler for all port 2 switches */
    //clearScreen(COLOR_BLACK);
    buzzer_set_period(0);
    fillRectangle(0,122,screenWidth,20,COLOR_BLACK);
    idle_seconds = 0;
     if(switch1_state == 1)
    {
        state = 1;
    }
    
    else if(switch2_state == 1)
    {
        state = 2;
    }
    
    else if(switch3_state == 1)
    {
        state = 3;
    }
    
    else if(switch4_state == 1)
    {
        state = 4;
    }
  }
  
}



