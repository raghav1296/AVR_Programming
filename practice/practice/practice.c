/*
 * practice.c
 *
 * Created: 28-02-2015 03:59:59
 *  Author: USER
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	DDRA&=~(1<<PINA1);
	DDRA|=1<<PINA0;
	PORTA|=255;
    while(1)
    {
        if ( bit_is_clear(PINA,1) )
		{
		PORTA&=~(1<<PINA0);
		_delay_ms(100);
		}
		else
		{ 
			PORTA|=(1<<PINA0);
		 _delay_ms(100);
        }
}
}