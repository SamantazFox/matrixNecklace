/* matrixEditor.h
 *
 * Main file's header containing definitions and library calls
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIXEDITOR_H_
#define _MATRIXEDITOR_H_


/* DEPENDENCIES */

// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>

// FLTK libraries
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_PNG_Image.H>

// Other files for this project
#include "loggerField.h"
#include "menuEntries.h"



/* GLOBAL VARIABLES */

extern Fl_Text_Buffer* logs;



/* CLASSES */

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


class Application {
public:
    Fl_Double_Window* makeWindow(void);

    static uint16_t sizeX;
    static uint16_t sizeY;

private:
    const char* label = "matrixEditor";
};



/* C++ PROGRAM */

#include "matrixEditor.cpp"


#endif  /* !_MATRIXEDITOR_H_ */
