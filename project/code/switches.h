#ifndef switches_included
#define switches_included

#define SW1 1	
/* switch 1 is p2.0 */
#define SW2 2        /* switch 2 is p2.1 */
#define SW3 4        //switch 3 is p2.2
#define SW4 8        //switch 4 is p3.4
#define P2_SWITCHES 15 /* Using 4 switches on upper board */

void switch_p2_init(void);         /* Initializes the port 2 switches */
void check_p2_switches(void);      /* Checks the port 2 switches */

extern const char down;
extern const char up;

extern char switch1_state, switch2_state, switch3_state, switch4_state;

#endif // included

