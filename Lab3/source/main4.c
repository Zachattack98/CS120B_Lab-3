/*	Author: Zachary Hill
 *	Lab Section: 23
 *	Assignment: Lab 3 Exercise 5
 *	Exercise Description: car seat weight sensor and airbag.
 *
 *	I acknowledge all content contained herein, excluding template or
 *	example code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;	//rightmost bit is set to zero for input
	unsigned char tmpD = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char wgtTl = 0;
	while(1) {
		tmpD = PIND & 0xFF;
		tmpB = PINB & 0x01;

		wgtTl = tmpD + tmpB;
		if(wgtTl >= 70) {
			tmpB = (tmpB & 0xF9) | 0x02;
		}
		else if(wgtTl < 70 && wgtTl > 5) {
			tmpB = (tmpB & 0xF9) | 0x04;
			printf("Airbag disabled");
		}
		else {
			tmpB = (tmpB & 0xF9);
		}
		PORTB = tmpB;
	}
	return 0;
}
