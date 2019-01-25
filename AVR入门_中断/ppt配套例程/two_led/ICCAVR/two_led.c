#include "delay.h"
#pragma interrupt_handler INT:2       //外部中断0

int led_flag = -1 ;
void INT()
{      
      delay(500);
      led_flag++ ;
	  //send1(led_flag+48);
	  
      EIFR |= BIT(INTF0) ;//清除中断标志位
}
void INT0_init()
{ 
   EICRA |= BIT(ISC01); //下降沿中断,先配置什么方式中断，再使能中断
   EIMSK |= BIT(INT0);  //配置INT0使能外部中断   
   SREG  |= BIT(7) ;    //开启总中断
}
void led_button_init()
{
   /*按键输入高电平*/
   DDRD&=~BIT(0);
   PORTD|=BIT(0);
   
   /*led输出低电平*/
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