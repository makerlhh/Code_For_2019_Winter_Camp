CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = source1.o 

PROJICT2:	$(FILES)
	$(CC) -o PROJICT2 $(LFLAGS) @PROJICT2.lk   -lcatmega
source1.o: E:\include\iom16v.h
source1.o:	source1.c
	$(CC) -c $(CFLAGS) source1.c
