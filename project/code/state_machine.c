#include "state_machine.h"
#include "draw_sprites.h"
#include "buzzer.h"

int note_freq = 1000; //A by default I guess
int note_delay = 4;
int note_trans = 0; //This thing will go through the note array
int note_duration = 0; //Note duration counter  

void stateCheck(state)
{
  //////////////Make this into assembly
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
 ///////////////// 
}
