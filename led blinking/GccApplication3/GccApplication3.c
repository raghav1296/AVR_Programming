
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	
	DDRB=0b11111111;
    while(1)
    {
        
			   _delay_ms(500);
				PORTB=0b10000001;
				_delay_ms(500);
				PORTB=0b01000010;
				_delay_ms(500);
				PORTB=0b00100100;
				_delay_ms(500);
				PORTB=0b00011000;
				_delay_ms(500);
				PORTB=0b00011000;
				_delay_ms(500);
				PORTB=0b00100100;
				_delay_ms(500);
				PORTB=0b01000010;
				_delay_ms(500);
				PORTB=0b10000001;
		      _delay_ms(500);
			 PORTB=0b11111111;
			 _delay_ms(500);
			 PORTB=0b10000001;
			 _delay_ms(500);
			 PORTB=0b01000010;
			 _delay_ms(500);
			 PORTB=0b00100100;
			 _delay_ms(500);
			 PORTB=0b00011000;
			 _delay_ms(500);
			 PORTB=0b00011000;
			 _delay_ms(500);
			 PORTB=0b00100100;
			 _delay_ms(500);
			 PORTB=0b01000010;
			 _delay_ms(500);
			 PORTB=0b10000001;
	
	
    }
}