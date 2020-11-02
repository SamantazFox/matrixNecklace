/* matrix.h
 *
 * Leds and Led matrix objects/methods
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIX_H_
#define _MATRIX_H_


/* ENUMS */

enum LedStates {
    ON  = true,
    OFF = false
};

enum DbgModes {
    RD = 0,
    WR = 1
};



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

    static uint64_t getData(Matrix* mtrx);
    static void setData(Matrix* mtrx, uint64_t data);

    static const uint8_t ledCount = 64;

private:
    static void debugIO(DbgModes mode, uint64_t data);
};


class Led : public Fl_Button {
public:
    Led(uint8_t index, bool state);
    inline void write(bool state);
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
