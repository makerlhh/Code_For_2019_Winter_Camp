/*
 * SPITEST.c
 *
 * Created: 2019/2/18 9:31:21
 * Author : Jianhao
 
 AVRÓ²¼şSPIÇı¶¯ÒÆÎ»¼Ä´æÆ÷74HC595
 
 */ 

#include <avr/io.h>
#define F_CPU 8000000L
#include <util/delay.h>
//ä¸Šé¢çš„å®å®šä¹‰ä¸è¦ç…§æŠ„
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

void SPI_init();
void SPI_write(uchar data);


int main(void)
{
	SPI_init();
	_delay_ms(500);
	SS_L;
	SPI_write(0b10101100);
	SPI_write(0b11110000);
	SS_H;
    while (1) 
    {
    }
}

void SPI_init()
{
	DDR_SPI = BIT(MOSI)|BIT(SCK)|BIT(SS);
	SPCR = BIT(SPE)|BIT(MSTR)|BIT(SPR1)|BIT(SPR1);
	SS_H;
}

void SPI_write(uchar data)
{
	SPDR = data;
	while(!(SPSR&BIT(SPIF)));
}