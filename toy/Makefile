# makfile configuration
COMMON_OBJECTS		= wdt_handler.o p2_interrupt_handler.o draw_shapes.o switches.o wdt_c_handler.o music.o buzzer.o 

#COMMON_OBJECTS2		= wdt_handler.o p2_interrupt_handler.o draw_shapes.o switches.o wdt_c_handl#er.o musicS.o buzzer.o 
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:toydemo.elf

#additional rules for files
toydemo.elf: ${COMMON_OBJECTS} toydemo.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

toydemo2.elf: ${COMMON_OBJECTS} toydemo.o wdt_handler.o p2_interrupt_handler.o draw_shapes.o switches.o wdt_c_handler.o musicS.o buzzer.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: toydemo.elf
	msp430loader.sh $^

load2: toydemo2.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf 

music.o: music.h
buzzer.o: buzzer.h
