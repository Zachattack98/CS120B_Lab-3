/*	Author: Zachary Hill
 *	Lab Section: 23
 *	Assignment: Lab 3 Exercise 4
 *	Exercise Description: mapping to lower and upper nibbles of port.
 *
 *	I acknowledge all content contained herein, excluding template or
 *	example code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x0F; PORTB = 0xF0;	//output to 4 rightmost bits
	DDRC = 0xF0; PORTC = 0x0F;	//output to 4 leftmost bits
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;

	while(1) {
		tmpA = PINA & 0xFF;

		tmpB = tmpA >> 4;
		tmpC = tmpA << 4;

		PORTB = tmpB;
		PORTC = tmpC;
	}
	return 0;
}
