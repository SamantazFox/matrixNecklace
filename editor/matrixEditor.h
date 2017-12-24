/* matrixEditor.h
 *
 * Main file's header containing definitions and library calls
 *
 * Copyright 2017 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIXEDITOR_H_
#define _MATRIXEDITOR_H_


/* DEPENDENCIES */

// Standard lobraries
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

// FLTK libraries
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_PNG_Image.H>



/* CLASSES */

class Led : public Fl_Button {
public:
    Led(int x, int y, bool state);
    void invert(void);
    int handle(int event);

    static const u_int8_t dotSize = 64;

private:
    Fl_Image* led_on = new Fl_PNG_Image("images/led_on.png");
    Fl_Image* led_off = new Fl_PNG_Image("images/led_off.png");
};


class Application {
public:
    Fl_Double_Window* makeWindow(void);

    static const int sizeX = 512;
    static const int sizeY = 512;

private:
    const char* label = "matrixEditor";
};



/* C++ PROGRAM */

#include "matrixEditor.cpp"


#endif  /* !_MATRIXEDITOR_H_ */
