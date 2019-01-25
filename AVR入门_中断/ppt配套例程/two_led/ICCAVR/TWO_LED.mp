NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0004 =      4. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0090  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0090   01FE =    510. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0048  __start
       0048  __text_start
       006A  _exit
       006B  _INT
       00A8  _INT0_init
       00B2  _led_button_init
       00BD  _main
       00F0  _delay
       0105  _usart1_init
       0119  _send1
       0129  _read1
       013D  push_xgsetF000
       0142  pop_xgsetF000
       0147  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0100  _led_flag
       0102  _flag
       0103  _qdata
       0104  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\นคื๗\avr\lib\crtatmega.o	[ crtatmega.s ]
two_led.o	[ two_led.c ]
delay.o	[ delay.c ]
usart.o	[ usart.c ]
<library>	[ gpushy.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

