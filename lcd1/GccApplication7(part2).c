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
*char sonar()
{
	char *name[15]="RAGHAV SONAVANE";
	_delay_ms(10);
	//while ((PINC&(1<<1))==0){}
	//TCNT2=0;
	//while((PINC&(1<<1))!=0 && TCNT2<230){}
	//distance=TCNT2;
	//distance=(distance*1.07);
	//return distance;
	return name;
}


int main(void)
{
	init_LCD();
	char *d;
	int i=0;
	DDRA =0x00;
	DDRC =0b01111111;
	DDRD |=(1<<4);
	DDRD |=(1<<5);
	d=sonar();
	for(i=0;i<15;i++)
	print_string(*(d+i));
	//d=sonar();
	//print_integer(d*100);
	_delay_ms(1000);
}
