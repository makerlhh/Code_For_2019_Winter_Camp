#include "delay.h"
#pragma interrupt_handler INT:2       //�ⲿ�ж�0

int led_flag = -1 ;
void INT()
{      
      delay(500);
      led_flag++ ;
	  //send1(led_flag+48);
	  
      EIFR |= BIT(INTF0) ;//����жϱ�־λ
}
void INT0_init()
{ 
   EICRA |= BIT(ISC01); //�½����ж�,������ʲô��ʽ�жϣ���ʹ���ж�
   EIMSK |= BIT(INT0);  //����INT0ʹ���ⲿ�ж�   
   SREG  |= BIT(7) ;    //�������ж�
}
void led_button_init()
{
   /*��������ߵ�ƽ*/
   DDRD&=~BIT(0);
   PORTD|=BIT(0);
   
   /*led����͵�ƽ*/
   DDRE|=BIT(0);
   PORTE&=BIT(0);
   DDRE|=BIT(1);
   PORTE&=BIT(1);
}
void main()
{
   led_button_init() ;
   INT0_init() ;
   while(1)
   {
       if(led_flag == 1 )
      {
         PORTE|=BIT(0);
		 PORTE&=~BIT(1);
      }
      if(led_flag == 2)
      {
         PORTE|=BIT(0);
		 PORTE|=BIT(1);
      }
      if(led_flag == 3)
      {
	     PORTE&=~BIT(0);
		 PORTE|=BIT(1);
	  }
      if(led_flag == 4)
      {
	     PORTE&=~BIT(0);
		 PORTE&=~BIT(1);
		 led_flag = 0 ;
	  }
   }
}