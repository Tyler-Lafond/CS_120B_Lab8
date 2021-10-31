/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 8  Exercise # 4
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
unsigned char voltPerLED;
unsigned char tempB;
unsigned short MAX = 590;
unsigned short MIN = 31;

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
	voltPerLED = MAX/8;
	if (volt >= (voltPerLED * 7))
	{
		tempB = 0xFF;
	}
	else if (volt >= (voltPerLED * 6))
	{
		tempB = 0x7F;
	}
	else if (volt >= (voltPerLED * 5))
	{
		tempB = 0x3F;
	}
	else if (volt >= (voltPerLED * 4))
	{
		tempB = 0x1F;
	}
	else if (volt >= (voltPerLED * 3))
	{
		tempB = 0x0F;
	}
	else if (volt >= (voltPerLED * 2))
	{
		tempB = 0x07;
	}
	else if (volt >= voltPerLED)
	{
		tempB = 0x03;
	}
	else
	{
		tempB = 0x01;
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
