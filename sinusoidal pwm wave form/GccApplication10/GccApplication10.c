/*
 * GccApplication10.c
 *
 * Created: 26-02-2015 18:10:03
 *  Author: USER
 */ 


#include <avr/io.h>
#include<util//delay.h>
#include<math.h>
#define F_CPU 16000000UL

int main(void)
{
	DDRB=0b11111111;
TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11)|(1<<WGM10);
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);
    while(1)
    {  
		ICR1=500;
		unsigned int i=0;
		while(i<500)
		{
		OCR1B=500*sin(i*1.57/499);
		i++;
		}
    }
}