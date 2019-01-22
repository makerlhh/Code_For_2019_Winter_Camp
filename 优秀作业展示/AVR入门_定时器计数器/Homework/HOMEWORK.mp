NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   003A =     58. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       008E  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   008E   02BC =    700. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0047  __text_start
       0047  __start
       0069  _exit
       006A  _init
       0073  _timeinit
       0078  _forward
       008B  _delay
       0096  _delay_ms
       00B2  _display
       0127  _main
       01A5  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   003A =     58. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _a
       0060  __data_start
       0074  _b
       0084  _time
       0094  _p
       0096  _control
       009A  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   009A   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       009A  __bss_start
       009A  _j
       009C  _i
       009E  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

E:\WorkTool\iccv7avr\NEWFOL~1\lib\crtatmega.o	[ crtatmega.s ]
homework.o	[ homework.c ]
<library>	

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

