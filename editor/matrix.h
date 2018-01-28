/* matrix.h
 *
 * Leds and Led matrix objects/methods
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIX_H_
#define _MATRIX_H_


/* DEPENDENCIES */

// FLTK Libraries
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>



/* GLOBAL VARIABLES */

extern Fl_Text_Buffer* logs;



/* CLASSES */

class Matrix : public Fl_Group {
public:
    Matrix(uint16_t x, uint16_t y);

    static uint64_t getData(Fl_Group* mtrx);
};


class Led : public Fl_Button {
public:
    Led(uint8_t index, bool state);
    void invert(void);
    int handle(int event);

    static const uint16_t dotSize = 48;
    static const uint16_t lineSize = 384;

    uint8_t index;

private:
    Fl_Image* led_on = new Fl_PNG_Image("images/led_on_48x48.png");
    Fl_Image* led_off = new Fl_PNG_Image("images/led_off_48x48.png");
};



/* C++ PROGRAM */

#include "matrix.cpp"


#endif /* !_MATRIX_H_ */