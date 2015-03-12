 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
void left()
{
PORTB=0b00001011;
OCR1A=0;
OCR1B=200;
_delay_ms(1000);
}
void right()
{
	PORTB=0b00001110;
	OCR1A=200;
	OCR1B=0;
	_delay_ms(1000);
}
void forward()
{
	PORTB=0b00001010;
	OCR1A=120;
	OCR1B=120;
	_delay_ms(1000);
}
void backward()
{
	PORTB=0b00000101;
	OCR1A=120;
	OCR1B=120;
	_delay_ms(1000);
}

int main(void)
{
	int i;
	ADMUX=0b01000000;
	ADCSRA=0b11000111;
	DDRA=0b00000000;
	DDRB=0b11111111;
	DDRD=0b11111111;
	TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<COM00)|(1<<CS01)|(1<<CS00);
	TCCR1A|=(1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0);
	TCCR1B|=(1<<CS11)|(1<<CS10);
    while(1)
    {
		ADCSRA|=(1<<6);
		while(ADCSRA&(1<<6));
	     i=ADC;	
		PORTB=ADC;
        _delay_ms(500);
		if(i<256)
		left();
		else if(i<512)
		right();
		else if(i<768)
		forward();
		else if(i<1024)
		backward();
	}
	return 0;
}