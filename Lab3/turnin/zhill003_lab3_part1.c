/*	Author: zhill003
 *  Partner(s) Name: none 
 *	Lab Section: 23
 *	Assignment: Lab 3  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0xFF;
	tmpB = PINB & 0xFF;
	int i;
	int cnt = 0;

	for(i=0; i<8; ++i) {
		tmpA = PINA >> i;
		if((tmpA & 0x01) == 0x01) {
			cnt++;
		}

		tmpB = PINB >> i;
		if((tmpB & 0x01) == 0x01) {
			cnt++;
		}
	}
	tmpC = cnt;
	PORTC = tmpC;
    }		
    return 1;
}
