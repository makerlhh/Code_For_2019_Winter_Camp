/*
 * SPITEST_Slave.c
 *
 * Created: 2019/2/18 10:08:39
 * Author : Jianhao
 SPI����ͨ�ţ��ӻ�����
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

void SPI_SlaveInit();
uchar SPI_read();



int main(void)
{
	SPI_SlaveInit();
	DDRC = 0b11111111;
    while (1) 
    {
		uchar data;
		data = SPI_read();
		PORTC = data;
    }
}


void SPI_SlaveInit()
{
	DDR_SPI = BIT(MISO);	//��MISO����Ϊ���
	SPCR = BIT(SPE);	//ʹ��SPI
}

uchar SPI_read()
{
	while(!(SPSR&BIT(SPIF)));	//�ȴ�������ɣ�
	return SPDR;
}