CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x8c.0x20000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = two_led.o delay.o usart.o 

TWO_LED:	$(FILES)
	$(CC) -o TWO_LED $(LFLAGS) @TWO_LED.lk   -lcatm128
two_led.o: .\..\..\..\LESSON~1\two_led\ICCAVR\delay.h D:\工作\avr\include\iom128v.h D:\工作\avr\include\macros.h D:\工作\avr\include\AVRdef.h .\..\..\..\LESSON~1\two_led\ICCAVR\usart.h
two_led.o:	..\..\..\LESSON~1\two_led\ICCAVR\two_led.c
	$(CC) -c $(CFLAGS) ..\..\..\LESSON~1\two_led\ICCAVR\two_led.c
delay.o: .\..\..\..\LESSON~1\two_led\ICCAVR\delay.h D:\工作\avr\include\iom128v.h D:\工作\avr\include\macros.h D:\工作\avr\include\AVRdef.h
delay.o:	..\..\..\LESSON~1\two_led\ICCAVR\delay.c
	$(CC) -c $(CFLAGS) ..\..\..\LESSON~1\two_led\ICCAVR\delay.c
usart.o: .\..\..\..\LESSON~1\two_led\ICCAVR\usart.h D:\工作\avr\include\iom128v.h D:\工作\avr\include\macros.h D:\工作\avr\include\AVRdef.h
usart.o:	..\..\..\LESSON~1\two_led\ICCAVR\usart.c
	$(CC) -c $(CFLAGS) ..\..\..\LESSON~1\two_led\ICCAVR\usart.c
