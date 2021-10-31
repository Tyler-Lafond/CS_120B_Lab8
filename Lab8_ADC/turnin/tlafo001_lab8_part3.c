/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 8  Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short volt;
unsigned char tempB;
unsigned short MAX = 588;
unsigned short MIN = 30;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	// 	in free Running Mode, a new conversion will trigger whenever
	// 	the previous conversion completes
}

void TickADC() {
	volt = ADC;
	if (volt >= (MAX/2))
	{
		tempB = 0x01;
	}
	else if (volt < (MAX/2))
	{
		tempB = 0x00;
	}
	PORTB = tempB;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	ADC_init();

	while (1) {
		TickADC();
	}
	return 1;
}
