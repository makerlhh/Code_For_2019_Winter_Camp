NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0054   01E2 =    482. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       002A  __start
       002A  __text_start
       004C  _exit
       004D  _crol
       0063  _delay
       0078  _main
       00F1  asr16
       00F8  pop_xgset00FC
       00FF  push_xgsetF0FC
       0101  push_xgset30FC
       0103  push_xgset00FC
       0105  push_xgset003C
       010A  push_xgsetF000
       010F  pop_xgsetF000
       0114  lsl16
       011B  __text_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

E:\lib\crtatmega.o	[ crtatmega.s ]
source1.o	[ source1.c ]
<library>	[ asr16.s, gpop3.s, gpush.s, gpushy.s, lsl16.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

