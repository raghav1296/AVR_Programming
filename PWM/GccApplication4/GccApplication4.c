

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRA=0b11111111;
	DDRD=0b11111111;
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);
	TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    while(1)
    {
		OCR1A=10;
		OCR1B=255;
		PORTD|=(0<<PD3)|(1<<PD2)|(0<<PD1)|(1<<PD0);
	
	}
}