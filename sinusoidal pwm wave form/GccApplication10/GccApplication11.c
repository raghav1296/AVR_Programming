/*
 * GccApplication10.c
 *
 * Created: 26-02-2015 18:10:03
 *  Author: USER
 */ 


#include <avr/io.h>
#include <util//delay.h>
#include <math.h>
#define F_CPU 16000000UL

int main(void)
{
	DDRB=0b11111111;
TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11)|(1<<WGM10);
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);
    ICR1=1250;
	while(1)
    {  
		OCR1A=100;
		_delay_ms(100);
		OCR1A=50;
		_delay_ms(100);
    }
}