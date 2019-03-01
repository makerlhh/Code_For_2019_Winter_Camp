#include"usart.h"
#include"delay.h"
void usart_init(void)    //    9600,8,1ֹͣλ,����żУ��          ��ʼ��
{
	uint baud=9600;     //������
	DDRD|= BIT(1);    
	UCSRA =0;           
	UCSRB |=BIT(RXCIE)|BIT(RXEN)|BIT(TXEN);        //���ͺͽ���ʹ��
	UCSRC |=BIT(URSEL)|BIT(UCSZ1)|BIT(UCSZ0);       //URSEL����������ȥ��Ҳ���ã�
	//UBRRH =0X00;
	//UBRRL =0X33;           //51
	UBRR =8000000/16/baud-1;       //���������ã�8M����
	SREG |=BIT(7);    //+++++++++++++++++++�����ж�
}
void usart_send_char(uchar i)          //�����ַ�
{
	while(!UCSRA&BIT(UDRE));
	UDR =i;
	while(!UCSRA&BIT(TXC)); 
	delay_ms(1);                //������Ҫ??????? 
	//UCSRA |=BIT(TXC);                //û�ж�Ӧ�ж�ʱҪ�ֶ�����?���������ݽ��뻺������λ�����㡣
}
void usart_send_str(char *zifu)        //���� �ַ���
{
	int i=0;
	while(zifu[i]!='\0' )
	{
		usart_send_char(zifu[i]);
		//delay_ms(1);                //������Ҫ???????
		i++;
	}
}
void usart_send(int num)    //����4λ����
{
	usart_send_char(num/1000%10+48);
	usart_send_char(num/100%10+48);
	usart_send_char(num/10%10+48);
	usart_send_char(num%10+48);
	usart_send_char(13);
}