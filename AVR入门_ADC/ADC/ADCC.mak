CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = ADC.o 

ADCC:	$(FILES)
	$(CC) -o ADCC $(LFLAGS) @ADCC.lk   -lcatmega
ADC.o: "D:\icc avr\include\iom16v.h" "D:\icc avr\include\macros.h" "D:\icc avr\include\AVRdef.h"
ADC.o:	ADC.c
	$(CC) -c $(CFLAGS) ADC.c
