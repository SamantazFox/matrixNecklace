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
//#include <FL/Fl_Widget.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_PNG_Image.H>



/* CONSTANTS */

#define MTX_DOT_SIZE 64



/* CLASSES */

class Led : public Fl_Toggle_Button {
public:
    Led(int x, int y, bool state);
    void invert(void);
    int handle(int event);

private:
    Fl_Image* led_on = new Fl_PNG_Image("images/led_on.png");
    Fl_Image* led_off = new Fl_PNG_Image("images/led_off.png");
};


class Application {
public:
    int run(void);
    Fl_Double_Window* makeWindow(void);

private:
    static const int sizeX = 512;
    static const int sizeY = 512;
    const char* label = "matrixEditor";
};



/* C++ PROGRAM */

#include "matrixEditor.cpp"


#endif  /* !_MATRIXEDITOR_H_ */
