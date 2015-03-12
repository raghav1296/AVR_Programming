/*
 * GccApplication13.c
 *
 * Created: 28-02-2015 17:30:23
 *  Author: USER
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR F_CPU/16/BAUD-1
int main(void)
{
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);   //64 prescalar
	ICR1=5000;   //maximum value of pwm
	DDRD|=255;
	PORTD=0b11111111;
	UCSRA|=1<<TXC;
	UCSRB|=1<<RXEN|1<<TXEN;
	UCSRC|=1<<UMSEL|1<<USBS|1<<UCSZ1|1<<UCSZ0;
	UBRRH=(unsigned char)UBRR;
	UBRRL=(unsigned char)(UBRR>>8);
	void transmit(unsigned char data){
		while(!(UCSRA&(1<<UDRE)));
		UDR=data;
	}
	unsigned char recieve(void)
	{
		while(!(UCSRA & (1<<RXC)));
		return UDR;
	}
    while(1)
    {
     unsigned char a;
	 a=recieve();
		 transmit(a);
		 OCR1A=(a/255)*ICR1; 
		 _delay_ms(1000);
	}
}