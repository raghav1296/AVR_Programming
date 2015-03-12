 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>             
int main(void)
{
	DDRA = 0b00000001;                       
	while(1)
	{
		PORTA= 0b00000000;            
		_delay_ms(500);
		PORTA= 0b00000001;
		_delay_ms(500);
		PORTA= 0b00000010;
		_delay_ms(500);
		PORTA= 0b00000100;
		_delay_ms(500);
		PORTA= 0b00001000;
		_delay_ms(500);
		PORTA= 0b00010000;
		_delay_ms(500);
		PORTA= 0b00100000;
		_delay_ms(500);
		PORTA= 0b01000000;
		_delay_ms(500);
		PORTA= 0b10000000;
		_delay_ms(500);
		    }
}