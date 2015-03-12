/*
 * GccApplication11.c
 *
 * Created: 27-02-2015 19:45:14
 *  Author: USER
 */ 


#include <avr/io.h>
#include <util//delay.h>
#include <math.h>
#define F_CPU 16000000UL

int main(void)
{
	DDRB=0b11111111;
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);   //64 prescalar 
	ICR1=5000;   //maaximum value of pwm
	while(1)
	{
		OCR1A=600;
		_delay_ms(100);
		OCR1A=125;
		_delay_ms(100);
	}
}