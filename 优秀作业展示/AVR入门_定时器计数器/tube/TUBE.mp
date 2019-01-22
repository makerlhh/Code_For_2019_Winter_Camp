NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0012 =     18. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0066  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0066   040C =   1036. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0033  __text_start
       0033  __start
       0055  _exit
       0056  _enter_one
       00AB  _delay
       00BF  _show_time
       00F6  _key_press
       0106  _key_scan
       0137  _main
       01E4  mod16s
       01E8  div16s
       0202  mod16u
       0204  div16u
       0205  xdiv16u
       021E  push_xgset300C
       0223  pop_xgset300C
       0228  push_xgsetF000
       022D  pop_xgsetF000
       0232  lsl16
       0239  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0012 =     18. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _data
       006B  _ms
       006C  _s
       006E  _m
       0070  _h
       0072  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0024 =     36. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

G:\learning\iccavrProteus\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
tube.o	[ tube.c ]
<library>	[ div16s.s, div16u.s, gpushx.s, gpushy.s, lsl16.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

