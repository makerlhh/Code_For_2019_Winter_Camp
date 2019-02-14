#include<iom16v.h>
#include<macros.h>

unsigned int adcc()
{
    unsigned int data;
	
	DDRA&=~BIT(PA0);//
	PORTA&=~BIT(PA0);
	
	ADMUX=0;
	ADCSRA|=BIT(ADEN);
	ADCSRA|=BIT(ADSC);//配置ADC
	
	while(!(ADCSRA&(BIT(ADIF))));//判断转换是否结束（中断标志置位）
	
	data = ADCL;
	data = data + ADCH*256;//读出转换的数据
    return data;
}

int main()
{
    unsigned int redata;
	DDRC|=BIT(PC0);
	
	while(1)
	{
	    redata = adcc();
		if(redata>512)
		{
		    PORTC&=~BIT(PC0);
		}
		else
		{
		    PORTC|=BIT(PC0);
		}
	}
	return 0;
}
	
	
	
	
	