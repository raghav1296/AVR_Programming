

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}
unsigned char EEPROM_read(unsigned int uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}
int main(void)
{
    unsigned int a=0;
	char read_memory;
	DDRB=255;
	PORTB=255;
    while(1)
    {
		if(a>511)a=0;
        EEPROM_write(a,PORTB);
		_delay_ms(1000);
		read_memory=EEPROM_read(a);
		PORTB^=read_memory;
		_delay_ms(1000);
		a+=2;
    }
}