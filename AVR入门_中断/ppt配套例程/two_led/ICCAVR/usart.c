//PD0,1
#include"usart.h"
#pragma interrupt_handler read1:31       //usart1接收结束中断
uchar flag=0,qdata=0;  //已经在middle.h里面声明了的全局变量
void usart1_init()
{
   DDRD&=~BIT(2);//PD2(RXD)输入
   DDRD|=BIT(3);//PD3(TXD)输出
   UCSR1A=0;
   UCSR1B|=BIT(RXCIE1)|BIT(RXEN1)|BIT(TXEN1);    
   UCSR1C|=BIT(UCSZ11)|BIT(UCSZ10);//8位
   UBRR1L=51;      //9600
   SREG|=BIT(7);
}

void send1(uchar data)
{
    while(!(UCSR1A&BIT(UDRE1)));
	UDR1=data;
	while(!(UCSR1A&BIT(TXC1)));
	UCSR1A|=BIT(TXC1);
}

uchar read1()
{
   while(!(UCSR1A&BIT(RXC1)));
   qdata=UDR1;
   flag=1; 
}
