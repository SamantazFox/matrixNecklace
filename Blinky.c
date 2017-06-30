/* Blinky.c
 *
 * Test file ...
 * Fuses used : -U lfuse:w:0x26:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m
 *
 * Copyright 2015 - 2017 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/


#include <myUtils.h>


/* MAIN FUNCTION */

int main(void) {
	// Test of the HD4470 LCD
	lcd_init();

	// Main loop
	while(true) {
		for(uint8_t i = 0x00; i <= 0xFF ; i++) {
			lcd_write(CMD, lcd_clearDisplay_CMD);
			lcd_wait();

			//char g = (char)fact(i) + "!";

			lcd_print((uint8_t*)(i + '\0'), 1, 0);
			//lcd_print(g, 1, 0);

			_delay_ms(1000);
		}
	}
}
