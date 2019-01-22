NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   001B =     27. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       006F  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0070   0498 =   1176. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0038  __text_start
       0038  __start
       005A  _exit
       005B  _main
       011F  _timer0_init
       0126  _counter
       0160  _delay
       0173  _disp
       0203  _key
       021E  mod16u
       0220  div16u
       0221  xdiv16u
       023A  mod8u
       023C  div8u
       023D  xdiv8u
       0252  pop_xgset30FC
       025B  push_xgsetF0FC
       025D  push_xgset30FC
       025F  push_xgset00FC
       0261  push_xgset003C
       0266  lsl8
       026C  asgnblk
       0284  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   001B =     27. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _table
       006A  _hour
       006C  _minute
       006E  _second
       0070  _ms
       0072  _Key_Value
       007B  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccavrpjbtmo\lib\crtatmega.o	[ crtatmega.s ]
lesson2_work.o	[ lesson2_work.c ]
<library>	[ div16u.s, div8u.s, gpop4.s, gpush.s, lsl8.s, struct.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

