#include<iom16v.h>
#include<macros.h>

unsigned int adcc()
{
    unsigned int data;
	
	DDRA&=~BIT(PA0);//
	PORTA&=~BIT(PA0);
	
	ADMUX=0;
	ADCSRA|=BIT(ADEN);
	ADCSRA|=BIT(ADSC);//����ADC
	
	while(!(ADCSRA&(BIT(ADIF))));//�ж�ת���Ƿ�������жϱ�־��λ��
	
	data = ADCL;
	data = data + ADCH*256;//����ת��������
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
	
	
	
	
	