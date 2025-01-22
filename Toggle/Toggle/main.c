// this is only working on the rising edge , when the push button is push , at that instance the changings are workings 
// if we want to  do this in another  way we have to change the EICRA to its relavent state
//     EICRA |= 0B00001100; // ISC 11 = 1 ISC110 =0 Rising edge interrupts
//     EICRA |= 0B00001000; // ISC 11 = 1 ISC110 =0 Faling edge interrupts 
#define F_CPU 1600000;
#include <avr/interrupt.h>
#include <avr/io.h>

volatile int toggle =0; 

int main(void)
{
	
	DDRB |= 0B00100000; // port b pin 5 set to output
    EICRA |= 0B00001100; // ISC 11 = 1 ISC110 =0 Rising edge interrupts
	EIMSK |= 0B00000010; // INT1 is selected
	sei(); // global interrupts			// we should enable this otherwise interrupts wont work
	
    while (1) 
    {
		
    }
}
// interrupts function , guides for these functions  are in the data sheet
ISR (INT1_vect){
	if(toggle){
		PORTB |= 0B00100000; // if toggle then the PORTB is now high
	}
	else{
		PORTB &= 0B11011111; // else otherwise
	}
	toggle = 1 - toggle;
}


/*
This is the other way  to write

int main(void)
{
	
	DDRB |= (1<<PB5); // port b pin 5 set to output
	EICRA |= (1<<ISC11)|(1<<ISC10); // ISC 11 = 1 ISC110 =0 Rising edge interrupts
	EIMSK |=  (1<<INT1); // INT1 is selected
	sei(); // global interrupts			// we should enable this otherwise interrupts wont work
	
	while (1)
	{
		
	}
}
// interrupts function , guides for these functions  are in the data sheet
ISR (INT1_vect){
	if(toggle){
		PORTB |= (1<<PB5); // if toggle then the PORTB is now high
	}
	else{
		PORTB |= ~(1<<PB5); // else otherwise
	}
	toggle = 1 - toggle;
}*/