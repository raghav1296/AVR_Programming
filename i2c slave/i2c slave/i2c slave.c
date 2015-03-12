/*
 * i2c_slave.c
 *
 * Created: 02-03-2015 01:10:48
 *  Author: USER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <compat/twi.h>
#define BAUD 9600
void init_twi(void)
{
	TWCR|=1<<TWEN;             //no need of setting TWSR
	TWBR=12;                   //prescale=1 and SCL=400khz
}

void slave_recieve(void)
{
	TWAR=0b01010101;
	TWCR|=0<<TWSTA|1<<TWEN|1<<TWEA|0<<TWSTO;
}
char TWIReadACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
int main(void)
{
	DDRC=255;
	PORTC=0b01010101;
    while(1)
    {
	   PORTB=TWIReadACK();
       while(PORTB)
	   {
		   _delay_ms(500);
        }
	   _delay_ms(2000);
    }
}