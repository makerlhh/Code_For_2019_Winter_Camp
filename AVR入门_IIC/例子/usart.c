#include"usart.h"
#include"delay.h"
void usart_init(void)    //    9600,8,1停止位,无奇偶校验          初始化
{
	uint baud=9600;     //波特率
	DDRD|= BIT(1);    
	UCSRA =0;           
	UCSRB |=BIT(RXCIE)|BIT(RXEN)|BIT(TXEN);        //发送和接收使能
	UCSRC |=BIT(URSEL)|BIT(UCSZ1)|BIT(UCSZ0);       //URSEL不用理？？（去掉也能用）
	//UBRRH =0X00;
	//UBRRL =0X33;           //51
	UBRR =8000000/16/baud-1;       //波特率设置，8M晶振
	SREG |=BIT(7);    //+++++++++++++++++++开总中断
}
void usart_send_char(uchar i)          //发送字符
{
	while(!UCSRA&BIT(UDRE));
	UDR =i;
	while(!UCSRA&BIT(TXC)); 
	delay_ms(1);                //好像需要??????? 
	//UCSRA |=BIT(TXC);                //没有对应中断时要手动清零?当有新数据进入缓冲区该位会置零。
}
void usart_send_str(char *zifu)        //发送 字符串
{
	int i=0;
	while(zifu[i]!='\0' )
	{
		usart_send_char(zifu[i]);
		//delay_ms(1);                //好像需要???????
		i++;
	}
}
void usart_send(int num)    //发送4位数字
{
	usart_send_char(num/1000%10+48);
	usart_send_char(num/100%10+48);
	usart_send_char(num/10%10+48);
	usart_send_char(num%10+48);
	usart_send_char(13);
}