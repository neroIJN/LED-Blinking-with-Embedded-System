#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{

	DDRB |= 0B00100000;
	DDRD &= 0B11110111; //PORF:PIN 3 is made out as input
    while (1) 
    {
		if (PIND & 0B00001000)
		{
			PORTB |= 0B00100000; 
		}
		else{
			PORTB &= 0B11011111;
		}
		
    }
}

