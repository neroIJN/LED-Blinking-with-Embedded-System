#include <avr/io.h>
#define F_CPU 16000000UL //Unsigned long
#include <avr/interrupt.h>

volatile int toggle = 0; //if we don't used volatile it give the toggle value in the cache
//but the toggle value should be a latest value so it should be get from the main memory directly;
int main(void)
{
	//Initializing the timer 1
	TIMSK1 |= (1<< OCIE1A);
	//configure the CTC mode
	TCCR1B |= (1<<WGM12);
	TCCR1B &= ~(1<WGM13);
	
	TCCR1A &= ~((1<<WGM11) | (1<<WGM10)); //make the pins as 0
	//To achieved the 1 second in the interrupt we have the configure cs12, cs11, cs10 pins
	//Here we used the pre scaler as 256
	TCCR1B |= (1<<CS12);
	TCCR1B &= ~((1<CS11) | (1<<CS10));
	
	//Timer register Configure/
	TCNT1H = 0x00;
	TCNT1L = 0x00; //total 16 bit set as 0 then we can count from 0
	
	//Configuring Timer Compare Reg/
	OCR1AH = 0xF4;
	OCR1AL = 0x24; // set the timer after 62500 pulses
	
	sei(); //Globle Interrupt
	
	DDRB |= (1<<PB5); //set the port5 as the output
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(TIMER1_COMPA_vect){
	if(toggle){
		PORTB |= (1<<PB5);
	}else{
		PORTB &= ~(1<<PB5);
	}
	toggle = 1- toggle;
}