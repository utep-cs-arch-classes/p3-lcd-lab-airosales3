# makfile configuration
COMMON_OBJECTS	= switches.o moving_demo.o draw_shapes.o wdtInterruptHandler.o buzzer.o led.o
CPU             = msp430g2553	
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: demo.elf

#additional rules for files
demo.elf: ${COMMON_OBJECTS} moving_demo.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: demo.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
