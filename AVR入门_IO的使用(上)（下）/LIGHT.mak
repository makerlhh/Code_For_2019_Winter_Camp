CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = light.o 

LIGHT:	$(FILES)
	$(CC) -o LIGHT $(LFLAGS) @LIGHT.lk   -lcatmega
light.o: .\..\..\..\..\iccv7avr\include\iom16v.h
light.o:	light.c
	$(CC) -c $(CFLAGS) light.c
