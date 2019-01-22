NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0028 =     40. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       007C  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   007C   0748 =   1864. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       003E  __start
       003E  __text_start
       0060  _exit
       0061  _timer_init
       0067  _delay
       007B  _time
       008C  _key_press
       0098  _scan
       01B6  _zhanshi
       0312  _main
       035E  push_arg4
       0360  push_arg2
       0363  mod16s
       0367  div16s
       0381  mod16u
       0383  div16u
       0384  xdiv16u
       039D  mod8u
       039F  div8u
       03A0  xdiv8u
       03B5  pop_xgsetF0FC
       03C0  push_xgsetF0FC
       03C2  push_xgset30FC
       03C4  push_xgset00FC
       03C6  push_xgset003C
       03CB  push_xgsetF000
       03D0  pop_xgsetF000
       03D5  lsl16
       03DC  lsl8
       03E2  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0028 =     40. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _table
       0060  __data_start
       0074  _table1
       0088  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
miaobiao.o	[ miaobiao.c ]
<library>	[ asave.s, div16s.s, div16u.s, div8u.s, gpop5.s, gpush.s, gpushy.s, lsl16.s, lsl8.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

