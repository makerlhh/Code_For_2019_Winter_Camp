CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = lesson1_work2.o 

LESSON1_WORK2:	$(FILES)
	$(CC) -o LESSON1_WORK2 $(LFLAGS) @LESSON1_WORK2.lk   -lcatmega
lesson1_work2.o: D:\iccavrpjbtmo\include\iom16v.h
lesson1_work2.o:	lesson1_work2.c
	$(CC) -c $(CFLAGS) lesson1_work2.c
