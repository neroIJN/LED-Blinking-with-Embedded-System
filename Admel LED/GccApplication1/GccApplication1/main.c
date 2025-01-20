/*
 * GccApplication1.c
 *
 * Created: 1/20/2025 2:48:59 PM
 * Author : niros
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> // need to import for the delay function


int main(void)
{
    
	DDRB |= 0B00100000; // PORTB pin 5 as an output port
    while (1) 
    {
		PORTB |= 0B00100000; //PINB made to high
		_delay_ms(1000);
		
		PORTB &= 0B11011111;
		_delay_ms(1000);
    }
}

