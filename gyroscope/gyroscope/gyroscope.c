
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <compat/twi.h>
#define BAUD 9600
#define baudrate F_CPU/16/BAUD-1
unsigned char address=0x20,read=1,recv_data;
void TWI_init_master(void) // Function to initialize master
{
	TWBR=0x01; // Bit rate
	TWSR=(0<<TWPS1)|(0<<TWPS0); // Setting prescalar bits
	// SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
}
void TWI_read_address(unsigned char data)
{
	TWDR=data; // Address and read instruction
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
	while((TWSR & 0xF8)!= 0x40);  // Check for the acknoledgement
}

void TWI_start(void)                      //i2c bus begins
{
	TWBR=0x01;             // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR|=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= 0x08); // Check for the acknowledgement
}
void TWI_stop(void)                   //data transfer completed
{
	// Clear TWI interrupt flag, Put stop condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
}
char TWI_read_data(void)                //master receiver mode
{
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x58); // Check for the acknoledgement
	recv_data=TWDR;
	return recv_data;
}
void transmit(unsigned char data)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
}

int main(void)
{
	DDRB=255;
	char a;	
	TWI_init_master();
	DDRD|=255;
	PORTD=0b11111111;
	UCSRB|=1<<RXEN|1<<TXEN;
	UCSRC|=1<<URSEL|1<<USBS|1<<UCSZ1|1<<UCSZ0;
	UBRRL=(unsigned char)(baudrate);
	UBRRH=(unsigned char)((baudrate)>>8);
	    while(1)
    {
		TWI_start();
		TWI_read_address(address+read);
		a=TWI_read_data();
		transmit(a);
		_delay_ms(300);
    }
}