/*	Author: zlian030
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
//#ifdef _SIMULATE_
//#include "simAVRHeader.h"
//#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	
	while(1) {
		unsigned short my_short = ADC; //Value of ADC register is now stored in variable x
		unsigned char my_char = (char)my_short;
		PORTB = my_char;
		unsigned char my_char2 = (char)(my_short >> 8);
		PORTD = my_char2;
	
	}
	
}	
	
	
