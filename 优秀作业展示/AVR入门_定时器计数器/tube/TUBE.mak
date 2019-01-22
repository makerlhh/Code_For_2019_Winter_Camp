CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = tube.o 

TUBE:	$(FILES)
	$(CC) -o TUBE $(LFLAGS) @TUBE.lk   -lcatmega
tube.o: G:\learning\iccavrProteus\iccv7avr\include\iom16v.h
tube.o:	..\..\..\LZELOV~1\Desktop\tube\tube.c
	$(CC) -c $(CFLAGS) ..\..\..\LZELOV~1\Desktop\tube\tube.c
