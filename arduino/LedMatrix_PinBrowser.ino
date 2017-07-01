/*
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

int pin[16] = {9, 8, 7, 6, 5, 4, 3, 2, A5, A4, A3, A2, A1, A0, 12, 13};

void waitForInput(int del = 500) {
	while(digitalRead(10) == HIGH) {}
	delay(del);
}


void setup() {
	Serial.begin(9600);

    for(uint8_t i = 0; i < 16; i++) {
		pinMode(pin[i], OUTPUT);
	}

	pinMode(10, INPUT);
	digitalWrite(10, HIGH);
}

void loop() {
	Serial.println("----- ROWS -----");

	for(int i = 0; i < 16; i++) {
		digitalWrite(pin[i], LOW);
	}

	for(int i = 0; i < 16; i++) {
		Serial.print("Pin : ");
		Serial.println(i);

		digitalWrite(pin[i], HIGH);
		waitForInput();
		digitalWrite(pin[i], LOW);
	}


	Serial.println("----- COLS -----");

	for(int i = 0; i < 16; i++) {
		digitalWrite(pin[i], HIGH);
	}

	for(int i = 0; i < 16; i++) {
		Serial.print("Pin : ");
		Serial.println(i);

		digitalWrite(pin[i], LOW);
		waitForInput();
		digitalWrite(pin[i], HIGH);
	}
}

