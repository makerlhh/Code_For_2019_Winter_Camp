CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = light_more.o 

LIGHTS_MORE:	$(FILES)
	$(CC) -o LIGHTS_MORE $(LFLAGS) @LIGHTS_MORE.lk   -lcatmega
light_more.o: C:\iccv7avr\include\iom16v.h
light_more.o:	light_more.c
	$(CC) -c $(CFLAGS) light_more.c
