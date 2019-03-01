/*
 * SPITEST_Master.c
 *
 * Created: 2019/2/18 10:07:19
 * Author : Jianhao
 
 SPI����ͨ�ţ���������
 
 */ 

#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>
//����ĺ궨�岻Ҫ�ճ�
#define uchar unsigned char
#define uint unsigned int
#define BIT(x) (1<<x)
#define SET(reg,x) reg|=BIT(x)
#define CLR(reg,x) reg&=~BIT(x)

#define DDR_SPI DDRB
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
#define SS_H SET(PORTB,SS)
#define SS_L CLR(PORTB,SS)

void SPI_MasterInit();
void SPI_write(uchar data);


int main(void)
{
	SPI_MasterInit();
	uchar data = 0b1;
    while (1) 
    {
	    SS_L;
	    SPI_write(data);
	    SS_H;
		data <<= 1;
		_delay_ms(1000);
    }
}

void SPI_MasterInit()
{
	DDR_SPI = BIT(MOSI)|BIT(SCK)|BIT(SS);	//��MOSI��SCK��SS����Ϊ���
	SPCR = BIT(SPE)|BIT(MSTR)|BIT(SPR0)|BIT(SPR0);	//ʹ��SPI������Ϊ������ʱ������ΪF/128
	SS_H;
	
}

void SPI_write(uchar data)
{
	SPDR = data;	//�������ݴ���
	while(!(SPSR&BIT(SPIF)));	//�ȴ�������ɣ�
}