 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>             
int main(void)
{
	DDRA = 0b11111111;                       
	while(1)
	{
		PORTA= 0b00001111;
		_delay_ms(2000);
		PORTA= 0b00000001;
		_delay_ms(2000);
		PORTA= 0b00000010;
		_delay_ms(2000);
		PORTA= 0b00000100;
		_delay_ms(2000);
		PORTA= 0b00001000;
		_delay_ms(2000);
		PORTA= 0b00001001;
		_delay_ms(2000);
		PORTA= 0b00000110;
		_delay_ms(2000);
		PORTA= 0b00000101;
		_delay_ms(2000);
		PORTA= 0b00001010;
		_delay_ms(2000);
	               
	}
}