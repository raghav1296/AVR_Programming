/*
 * GccApplication7.c
 *
 * Created: 13-12-2014 15:21:11
 *  Author: USER
 */ 

/*#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "LCD.h"
#include "LCD.c"
int sonar()
{
	int distance;
	_delay_ms(10);
	while ((PINC&(1<<1))==0){}
	TCNT2=0;
	while((PINC&(1<<1))!=0 && TCNT2<230){}
	distance=TCNT2;
	distance=(distance*1.07);
	return distance;
}


int main(void)
{
	init_LCD();
	int d;
	DDRA =0x00;
	DDRC =0b01111111;
	DDRD |=(1<<4);
	DDRD |=(1<<5);
	d=sonar();
	print_integer(d*100);
	_delay_ms(1000);
}*/
/*
 * lcd2.c
 *
 * Created: 06-03-2015 18:44:28
 *  Author: USER
 */ 


/*
 * GccApplication7.c
 *
 * Created: 13-12-2014 15:21:11
 *  Author: USER
 */ 

#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "LCD.h"
#include "LCD.c"
int main(void)
{
	init_LCD();
	char name[15]="raghavsonavane";
	DDRA =0x00;
	PORTB=255;
	DDRD |=(1<<1);
	DDRD |=(1<<0);
	print_string(name);
	//d=sonar();
	//print_integer(d*100);
	_delay_ms(1000);
}

