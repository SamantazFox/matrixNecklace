/* matrixNecklace.c
 *
 * Main program file
 *
 * Copyright 2015 - 2018 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/


// Used fuse bits : Self Programming enabled, 8Mhz clock divided by 8
// -U lfuse:w:0x64:m -U hfuse:w:0xdf:m -U efuse:w:0xfe:m


#ifndef _MATRIXNECKLACE_C_
#define _MATRIXNECKLACE_C_

#include "template.h"


/* MAIN FUNCTION DEFINITIONS */

// BasicSerial main function implementation
// void serOut(const uint8_t* str) { while (*str) TxByte(*str++); }
// void serOut_P(const uint8_t* str) { while (pgm_read_byte(*str)) TxByte(pgm_read_byte(*str++)); }

// Light all the matrix's LEDs
void fillScreen(void) {
	for(uint8_t i = 0; i < 8; i++) {
		sbi(rows[i][0], rows[i][1]);
		cbi(cols[i][0], cols[i][1]);
	}
	serOut_P(scrFilld);
}

// Shut off all the matrix's LEDs
/*
void clearScreen(void) {
	for(uint8_t i = 0; i < 8; i++) {
		cbi(rows[i][0], rows[i][1]);
		sbi(cols[i][0], cols[i][1]);
	}
	serOut_P(scrClear);
}
*/

// Write a specific number of times the desired pattern
// TODO : improve timings efficiency (and power ?)
void writePattern(const uint8_t pat[8], uint8_t frames) {
	for(uint8_t x = 0; x < frames; x++) {
		for(uint8_t i = 0; i < 8; i++) {
			sbi(rows[i][0], rows[i][1]);
			for(uint8_t j = 7; j >= 0; j--) {
				if(readBit(pgm_read_byte(pat[i]), j)) { cbi(cols[j][0], cols[j][1]); }
				sbi(cols[j][0], cols[j][1]);
			}
			cbi(rows[i][0], rows[i][1]);
		}
	}
}



/* MAIN PROGRAM */

int main(void) {
	// Define direction register
	DDRA = 0x03;
	DDRB = 0xFF;
	DDRD = 0x7F;

	// Start w/ a fresh new screen, and start debugging via serial
	//clearScreen();
	serOut_P(initDone);

	// uuuh ... that's not pretty clean :$
	while(1)
	{
		fillScreen();
		_delay_ms(5000);

		// Battery animation
		serOut_P(writingP);
		for(uint8_t x = 0; x < 15; x++) {
			writePattern(bat_0, speed1);
			writePattern(bat_20, speed1);
			writePattern(bat_40, speed1);
			writePattern(bat_60, speed1);
			writePattern(bat_80, speed1);
			writePattern(bat_100, speed1);
		}

		// Space Invaders 1 animation
		serOut_P(writingP);
		for(uint8_t x = 0; x < 20; x++) {
			writePattern(SI1_On, speed2);
			writePattern(SI1_Off, speed2);
		}

		// Space Invaders 2 animation
		serOut_P(writingP);
		for(uint8_t x = 0; x < 20; x++) {
			writePattern(SI2_On, speed2);
			writePattern(SI2_Off, speed2);
		}

		// Other stuff
		/*
		serOut_P(writingP);
		for(uint8_t x = 0; x < 10; x++) {
			writePattern(heart, speed2);
		}

		serOut_P(writingP);
		for(uint8_t x = 0; x < 10; x++) {
			writePattern(smile, speed2);
		}

		serOut_P(writingP);
		for(uint8_t x = 0; x < 10; x++) {
			writePattern(clock, speed2);
		}
		*/
	}
}


#endif  /* !_MATRIXNECKLACE_C_ */
