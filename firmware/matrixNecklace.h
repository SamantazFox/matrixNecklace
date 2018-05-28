/* matrixNecklace.h
 *
 * Header file
 *
 * Copyright 2015 - 2018 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/


#ifndef _MATRIXNECKLACE_H_
#define _MATRIXNECKLACE_H_


/* DEPENDENCIES */

// My small utility file
#include <myUtils.h>

// Functions who stores functions and data in flash.
#include <avr/pgmspace.h>

// Self Programing functions
// #include <avr/boot.h>

// My pattern file
#include "patterns.h"



/* CONSTANTS DEFINITIONS */

// Frames speed
#define speed1 ((uint16_t) 700)
#define speed2 ((uint16_t) 1000)

// Main definition of pins used
uint8_t rows[8][2] = {{PORTB,0}, {PORTB,5}, {PORTD,5}, {PORTD,0}, {PORTD,4}, {PORTD,1}, {PORTD,2}, {PORTB,4}};
uint8_t cols[8][2] = {{PORTA,1}, {PORTA,0}, {PORTB,1}, {PORTD,3}, {PORTB,2}, {PORTB,6}, {PORTB,7}, {PORTD,5}};

// Serial strings
PROGMEM const uint8_t initDone[] = "Initialisation done.\n\r";
PROGMEM const uint8_t scrFilld[] = "Screen filled !\n\r";
PROGMEM const uint8_t scrClear[] = "Screen cleared !\n\r";
PROGMEM const uint8_t writingP[] = "writing pattern : ";



/* FUNCTIONS */

void fillScreen(void);
//void clearScreen(void);
void writePattern(const uint8_t pat[8], uint8_t frames);



/* C PROGRAM */

#include "matrixNecklace.c"


#endif  /* !_MATRIXNECKLACE_H_ */
