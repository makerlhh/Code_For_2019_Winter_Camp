#ifndef usart_h_
#define usart_h_

#include<iom128v.h>
#include<macros.h>
#define  uchar unsigned char
#define  uint  unsigned int

void  usart1_init();
void  send1(uchar data);
uchar read1();

#endif