#include<iom16v.h>
#include<macros.h>
unsigned int shu;
/***************************************
           延时函数
****************************************/
void delay(unsigned  int k)
{
	unsigned int i,j;
	for(i=0;i<k;i++)
	for(j=0;j<1148;j++);
}
/****************************************
            主函数
****************************************/
void main(void)
{
	DDRB=0XFF; //将 PB 口设置为输出
	PORTB=0XFF; //PB 口输出 11111111,熄灭全部灯
	DDRD=0XF7; //PD3 设置为输入，其余设置输出
	PORTD=0XFF; //PD3 使能上拉电阻，其余都输出 1
	
	
	MCUCR=0X08; //INT1 设置为下降沿触发
	GICR=0X80; //使能 INT1 中断
	SREG=0X80; //使能总中断
while(1)
{
	PORTB=0X00; //PB 口输出全是 0，点亮 8 个灯
	delay(1000); //延时一段时间
	PORTB=0XFF; //PB 口输出全是 1，熄灭 8 个灯
	delay(1000); //延时一段时间
}
}
/***************************************
            中断服务程序
***************************************/
#pragma interrupt_handler int1_isr:3
void int1_isr(void)
{
for(shu=0;shu<5;shu++)
{
	PORTB|= BIT(7); //PB7 输出 1，熄灭 LED
	delay(100); //延时
	PORTB&=~BIT(7); //PB7 输出 0，点亮 LED
	delay(100); //延时
}
}
