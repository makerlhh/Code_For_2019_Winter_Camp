CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = lesson2_work.o 

LESSON2_WORK:	$(FILES)
	$(CC) -o LESSON2_WORK $(LFLAGS) @LESSON2_WORK.lk   -lcatmega
lesson2_work.o: D:\iccavrpjbtmo\include\iom16v.h
lesson2_work.o:	lesson2_work.c
	$(CC) -c $(CFLAGS) lesson2_work.c
