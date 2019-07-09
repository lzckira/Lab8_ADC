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

unsigned short max = 0xAF;

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
		unsigned short my_short = ADC; 
		
		if (ADC >= (7.7 * max / 8)) {
			PORTB = 0xFF;
		}
		else if (ADC >= (6.7 * max / 8)) {
			PORTB = 0x7F;
		}
		else if (ADC >= (5.7 * max / 8)) {
			PORTB = 0x3F;
		}
		else if (ADC >= (4.7 * max / 8)) {
			PORTB = 0x1F;
		}
		else if (ADC >= (3.7 * max / 8)) {
			PORTB = 0x0F;
		}
		else if (ADC >= (2.7 * max / 8)) {
			PORTB = 0x07;
		}
		else if (ADC >= (1.7 * max / 8)) {
			PORTB = 0x03;
		}
		else {
			PORTB = 0x01;
		}
		
	
	}
	
}	
	
	
