NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   007E =    126. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       00D2  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00D2   07FE =   2046. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0069  __text_start
       0069  __start
       008B  _exit
       008C  _time1_init
       0098  _main
       00E6  _time1
       0205  _delay_us
       0217  _delay_ms
       022C  _eeprom_write
       0236  _eeprom_read
       0240  _eeprom_write_str
       0254  _TWI_init
       025B  _TWI_Write
       02A0  _TWI_Write_str
       02A1  _TWI_Read
       02EF  _usart_init
       031A  _usart_send_char
       0338  _usart_send_str
       034D  _usart_send
       0381  mod16s
       0385  div16s
       039F  mod16u
       03A1  div16u
       03A2  xdiv16u
       03BB  div32u
       03BD  mod32u
       03C1  div32s
       03C3  mod32s
       03EF  long_div_prolog
       0402  long_div_epilog
       0412  tst_R16_R19
       0417  tst_R24_R27
       041C  neg_R24_R27
       0425  push_xgset300C
       042A  pop_xgset300C
       042F  push_xgsetF000
       0434  pop_xgsetF000
       0439  push_xgsetF00C
       0440  pop_xgsetF00C
       0447  neg32
       0450  asgnblk
       0468  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   007E =    126. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _sec
       0062  _min
       0064  _hour
       0066  _day
       00DE  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0024 =     36. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccavr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
delay.o	[ delay.c ]
eeprom.o	[ eeprom.c ]
iic_hard.o	[ iic_hard.c ]
usart.o	[ usart.c ]
<library>	[ div16s.s, div16u.s, div32.s, gpushx.s, gpushy.s, gpushz.s, lneg.s, struct.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

