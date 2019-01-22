CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = light3.o 

LIGHT3:	$(FILES)
	$(CC) -o LIGHT3 $(LFLAGS) @LIGHT3.lk   -lcatmega
light3.o: D:\iccv7avr\include\iom16V.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h
light3.o:	light3.c
	$(CC) -c $(CFLAGS) light3.c
