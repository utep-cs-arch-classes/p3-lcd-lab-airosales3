# makfile configuration
COMMON_OBJECTS	= switches.o main.o draw_sprites.o interruptHandler.o buzzer.o led.o state_machine.o
CPU             = msp430g2553	
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: demo.elf

#additional rules for files
demo.elf: ${COMMON_OBJECTS} main.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: demo.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
