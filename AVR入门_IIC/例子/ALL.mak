CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = main.o delay.o eeprom.o iic_hard.o usart.o 

ALL:	$(FILES)
	$(CC) -o ALL $(LFLAGS) @ALL.lk   -lcatmega
main.o: D:\iccavr\include\iom16v.h D:\iccavr\include\macros.h D:\iccavr\include\AVRdef.h .\delay.h .\eeprom.h .\usart.h .\iic_hard.h .\DELAY.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
delay.o: .\delay.h
delay.o:	delay.c
	$(CC) -c $(CFLAGS) delay.c
eeprom.o: .\eeprom.h D:\iccavr\include\iom16v.h D:\iccavr\include\macros.h D:\iccavr\include\AVRdef.h
eeprom.o:	eeprom.c
	$(CC) -c $(CFLAGS) eeprom.c
iic_hard.o: .\iic_hard.h .\DELAY.h D:\iccavr\include\iom16v.h D:\iccavr\include\macros.h D:\iccavr\include\AVRdef.h .\delay.h
iic_hard.o:	iic_hard.c
	$(CC) -c $(CFLAGS) iic_hard.c
usart.o: .\usart.h D:\iccavr\include\iom16v.h D:\iccavr\include\macros.h D:\iccavr\include\AVRdef.h .\delay.h
usart.o:	usart.c
	$(CC) -c $(CFLAGS) usart.c
