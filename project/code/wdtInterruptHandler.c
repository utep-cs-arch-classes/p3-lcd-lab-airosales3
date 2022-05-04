#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "led.h"
#include "draw_shapes.h"
#include "buzzer.h"

int state = 0;
static u_int idle_limit = 25;
static u_int idle_seconds = 0;
int note_freq = 1000; //A by default I guess
int note_delay = 4;
int note_trans = 0; //This thing will go through the note array
int note_duration = 0; //Note duration counter
// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 2;
  static u_int second_count = 0;

  second_count++;
  drawMenu();
  drawText(state);
  
  
  
  switch(state)
  {
      case 0:
          drawRalsei(43,23,ralsei_idle);
          break;
          
      case 1:
          drawRalsei(43,37,ralsei_fight);
          break;
          
      case 2:
          drawRalsei(43,32,ralsei_sing);
          
    if (note_trans >= 46)   
    {
        note_trans = 0;
    }
    if(note_trans <= 46)
  {
      note_delay = delay_notes_pt1[note_trans];
      note_freq = song_notes_pt1[note_trans];
      
      if(note_duration <= note_delay)
      {
        note_duration ++;
        buzzer_set_period(note_freq);
      }
      
      else if (note_duration > note_delay)
      {
      note_duration = 0;
      note_trans++;
      buzzer_set_period(0);
      }
      
}

          break;
          
      case 3:
          drawRalsei(43,23,ralsei_defend);
          break;
          
      case 4:
          drawRalsei(43,23, ralsei_pet);
          break;
          
      default:
          drawRalsei(43,23,ralsei_idle);
          break;
}
 
  
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



