NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0054   03F4 =   1012. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       002A  __start
       002A  __text_start
       004C  _exit
       004D  _delay_ms
       0061  _Light
       01CB  _main
       0205  push_xgsetF000
       020A  pop_xgsetF000
       020F  push_xgsetF00C
       0216  pop_xgsetF00C
       021D  lsl16
       0224  __text_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
light_more.o	[ light_more.c ]
<library>	[ gpushy.s, gpushz.s, lsl16.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

