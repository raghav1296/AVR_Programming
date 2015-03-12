




#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#define BAUD 9600
#define baudrate F_CPU/16/BAUD-1

void transmit(unsigned char data){
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
}
unsigned char b[3],t;
unsigned int i;

unsigned char recieve(void)
{
	t='0';
	for(i=0;i<3;i++)
	{
	while(!(UCSRA & (1<<RXC)))
	b[i]=UDR;
    t+=(b[i]-'0')*10*(2-i);
	}
	return t;
	
}

int main(void)
{
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10);   //64 prescalar
	ICR1=4999;   //maximum value of pwm
	DDRD|=255;
	PORTD=0b11111111;
	//UCSRA|=1<<TXC;
	UCSRB|=1<<RXEN|1<<TXEN;
	UCSRC|=1<<URSEL|1<<USBS|1<<UCSZ1|1<<UCSZ0;
	UBRRL=(unsigned char)(baudrate);
	UBRRH=(unsigned char)((baudrate)>>8);
	
	unsigned char a;
	while(1)
	{ 
		a=recieve();
		transmit(a);
		OCR1A=a*ICR1/255;
	}
}  