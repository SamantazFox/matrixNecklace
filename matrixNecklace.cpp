/* matrixNecklace.cpp
 *
 * Main program file
 *
 * Copyright 2015 - 2017 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/



// Used fuse bits : Self Programming enabled, 8Mhz clock divided by 8
// -U lfuse:w:0x64:m -U hfuse:w:0xdf:m -U efuse:w:0xfe:m


/* INCLUDES */

// My small utility file
#include <myUtils.h>

// Functions who stores functions and data in flash.
#include <avr/pgmspace.h>

// Self Programing functions
// #include <avr/boot.h>


// A small 1-wire Serial interface (Tx version) made by Nerd Ralph
//#include <BasicSerial.h>
#include <serialTest.h>

// My pattern file
#include "patterns.h"



/* CONSTANTS DEFINITIONS */

// Frames speed
#define speed1 700
#define speed2 1000

// Main definition of pins used
short rows[8][2] = {{PORTB,0}, {PORTB,5}, {PORTD,5}, {PORTD,0}, {PORTD,4}, {PORTD,1}, {PORTD,2}, {PORTB,4}};
short cols[8][2] = {{PORTA,1}, {PORTA,0}, {PORTB,1}, {PORTD,3}, {PORTB,2}, {PORTB,6}, {PORTB,7}, {PORTD,5}};

// Serial strings
PROGMEM const char initDone[] = "Initialisation done.\n\r";
PROGMEM const char scrFilld[] = "Screen filled !\n\r";
PROGMEM const char scrClear[] = "Screen cleared !\n\r";
PROGMEM const char writingP[] = "writing pattern : ";



/* MAIN FUNCTION DEFINITIONS */

// MySerial initialisation
// extern "C" void SendByte(char) {}
void serOut(const char* str) {while (*str) SendByte(*str++);}

void serOut_P(const char* str) {while (pgm_read_byte(*str)) SendByte(pgm_read_byte(*str++));}

// BasicSerial main function implementation
// void serOut(const char* str) { while (*str) TxByte(*str++); }
// void serOut_P(const char* str) { while (pgm_read_byte(*str)) TxByte(pgm_read_byte(*str++)); }

// Light all the matrix's LEDs
void fillScreen(void) {
	for(int i = 0; i < 8; i++) {
		sbi(rows[i][0], rows[i][1]);
		cbi(cols[i][0], cols[i][1]);
	}
	serOut_P(scrFilld);
}

// Shut off all the matrix's LEDs
/*
void clearScreen(void) {
	for(int i = 0; i < 8; i++) {
		cbi(rows[i][0], rows[i][1]);
		sbi(cols[i][0], cols[i][1]);
	}
	serOut_P(scrClear);
}
*/

// Write a specific number of times the desired pattern
// TODO : improve timings efficiency (and power ?)
void writePattern(const char pat[8], int frames) {
	for(int x = 0; x < frames; x++) {
		for(int i = 0; i < 8; i++) {
			sbi(rows[i][0], rows[i][1]);
			for(int j = 7; j >= 0; j--) {
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
		serOut("Battery\n\r");
		for(int x = 0; x < 15; x++) {
			writePattern(bat_00, speed1);
			writePattern(bat_20, speed1);
			writePattern(bat_40, speed1);
			writePattern(bat_60, speed1);
			writePattern(bat_80, speed1);
			writePattern(bat_100, speed1);
		}

		// Space Invaders 1 animation
		serOut_P(writingP);
		serOut("Space Invaders 1\n\r");
		for(int x = 0; x < 20; x++) {
			writePattern(SI1_On, speed2);
			writePattern(SI1_Off, speed2);
		}

		// Space Invaders 2 animation
		serOut_P(writingP);
		serOut("Space Invaders 2\n\r");
		for(int x = 0; x < 20; x++) {
			writePattern(SI2_On, speed2);
			writePattern(SI2_Off, speed2);
		}

		// Other stuff
		/*
		serOut_P(writingP);
		serOut("A small heart\n\r");
		for(int x = 0; x < 10; x++) {
			writePattern(heart, speed2);
		}

		serOut_P(writingP);
		serOut("A smiley");
		for(int x = 0; x < 10; x++) {
			writePattern(smile, speed2);
		}

		serOut_P(writingP);
		serOut("A clock");
		for(int x = 0; x < 10; x++) {
			writePattern(clock, speed2);
		}
		*/
	}
}
