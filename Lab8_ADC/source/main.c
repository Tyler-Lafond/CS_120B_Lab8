/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 8  Exercise # 1
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
unsigned char tempD;

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
	tempB = (char)volt;
	tempD = (((char)(volt >> 8)) & 0x03);
	PORTB = tempB;
	PORTD = tempD;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();

	while (1) {
		TickADC();
	}
	return 1;
}
