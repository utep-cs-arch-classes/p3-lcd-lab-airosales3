#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
                          
int song_notes_pt1[46] ={C5_s,B4,A4,A4,A4,A4, //6
                        E5,A4_s,D5,D5,D5,D5,  //6
                        D5,A4_s,D5,E5,E5,E5,E5,//7
                        E5,A4_s,G4,A4_s,B4, //5
                        A4_s,A4,G4,G4,G4,F4, //6
                        E5,A4_s,D5,D5,D5,D5, //6
                        D5,A4_s,D5,E5,A5,A4_s,A4,B4,D5,E5 //10
};

                                             //Hold E0
                        //0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 2 1 2 3 4
int delay_notes_pt1[46]= {1,0,0,0,0,3,
                          0,0,0,0,0,3,
                          0,0,0,0,0,0,3,
                          0,0,0,0,3,
                          0,0,0,0,0,3,
                          0,0,0,0,0,3,
                          0,0,0,2,0,0,0,0,0,3
};

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

