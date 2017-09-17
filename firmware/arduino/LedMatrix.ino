/* LedMatrix.ino
 *
 * Working, arduino code used to drive the display
 * Uses ATmega328P
 *
 * Copyright 2015 - 2017 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/


/*	Rows :  7  2  8  4 15  9 14 11
	Cols :  3 13 12  6 10  5  1  0
	Inverted
  		 _______________
	13 -| 16          1 |- 9
	12 -| 15          2 |- 8
	A0 -| 14   8x8    3	|- 7
	A1 -| 13          4 |- 6
	A2 -| 12   LED    5 |- 5
	A3 -| 11  Matrix  6 |- 4
	A4 -| 10          7 |- 3
	A5 -|_9___________8_|- 2
*/

#include "../patterns.h"

short rows[8] = {2, 7, A5, 5, 13, A4, 12, A2};
short cols[8] = {6, A0, A1, 3, A3, 4, 8, 9};

void fillScreen() {
	for(uint8_t i = 0; i < 8; i++) {
		digitalWrite(rows[i], HIGH);

		for(uint8_t j = 0; j < 8; j++) {
			digitalWrite(cols[j], LOW);
			digitalWrite(cols[j], HIGH);
		}

		digitalWrite(rows[i], LOW);
	}
}

void clearScreen() {
	for(uint8_t i = 0; i < 8; i++) {
		pinMode(rows[i], OUTPUT);
		digitalWrite(rows[i], LOW);
		pinMode(cols[i], OUTPUT);
		digitalWrite(cols[i], HIGH);
	}
}

void writePattern(uint8_t pat[8], uint8_t frames) {
 for(uint8_t x = 0; x < frames; x++) {
		for(uint8_t i = 0; i < 8; i++) {
			digitalWrite(rows[i], HIGH);
			for(uint8_t j = 7; j >= 0; j--) {
				if(bitRead(pat[i], j) == 1) {
					digitalWrite(cols[j], LOW);
				}
				digitalWrite(cols[j], HIGH);
			}
			digitalWrite(rows[i], LOW);
		}
	}
}

int speed1 = 700;
int speed2 = 1000;


void setup() {
	clearScreen();
}

void loop() {

	// Space invaders 2
	for(uint8_t x = 0; x < 20; x++) {
		writePattern(SI2_On, speed2);
		writePattern(SI2_Off, speed2);
	}

	// Space invaders 1
	for(uint8_t x = 0; x < 20; x++) {
		writePattern(SI1_On, speed2);
		writePattern(SI1_Off, speed2);
	}
}
