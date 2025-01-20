/*
 * GccApplication1.c
 *
 * Created: 1/20/2025 3:17:22 PM
 * Author : niros
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
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

