#ifndef buzzer_included
#define buzzer_included

#define C3 130
#define C3_s 139
#define D3 147
#define D3_s 156
#define E3 165
#define F3 175
#define F3_s 185
#define G3 196
#define G3_s 208
#define A3 220
#define A3_s 233
#define B3 247
#define C4 262
#define C4_s 277
#define D4 297
#define D4_s 311
#define E4 330
#define F4 349
#define F4_s 370
#define G4 392
#define G4_s 415
#define A4 440
#define A4_s 466
#define B4 494
#define C5 523
#define C5_s 554
#define D5 587
#define D5_s 622
#define E5 659
#define F5 698
#define G5 784
#define G5_s 830
#define A5 880
#define A5_s 932
#define B5 987
#define C6 1046
#define C6_s 1108
#define D6 1175
#define D6_s 1244

void buzzer_init();
void buzzer_set_period(short cycles);
extern int song_notes_pt1[46];
extern int delay_notes_pt1[46];



#endif // included
