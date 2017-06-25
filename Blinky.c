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

	_delay_ms(2500);

	pwm_pin1A(1000);
	pwm_pin1B(750);


	while(true) {
	/*
		for(char i = 0x000; i < 0x3FF; i++) {
			pwm_pin1A(i);
			pwm_pin1B((0x3FF-i));

			_delay_ms(250);
		}

		for(char i = 0x3FF; i > 0x000; i--) {
			pwm_pin1A(i);
			pwm_pin1B((0x3FF-i));

			_delay_ms(250);
		}
	*/
	}


/*
	setPortOut(PORTB);
	setPortOut(PORTD);

	char a = 0x05;

	PORTB = swap(a);

	PORTD = swap(PORTB);

	while(true);
*/

/*
	i2c_init();
	char msg[3] = {slaveAddr(0x07, i2c_WRITE), 0x55, 0xFF};

	while(true) {
		_delay_us(100);
		i2c_send(msg);
	}
*/

/*
	//lcd_init();

	while(true) {
		for(char i = 0x00; i <= 0xFF ; i++) {
			lcd_write(CMD, lcd_clearDisplay_CMD);
			lcd_wait();

			//char g = (char)fact(i) + "!";

			lcd_print((char*)(i + '\0'), 1, 0);
			//lcd_print(g, 1, 0);

			_delay_ms(1000);
		}
	}
*/
}
