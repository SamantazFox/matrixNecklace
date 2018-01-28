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

// Other files for this project
#include "loggerField.h"
#include "matrix.h"
#include "menuEntries.h"



/* GLOBAL VARIABLES */

extern Fl_Text_Buffer* logs;



/* CLASSES */

class Application : public Fl_Double_Window {
public:
    Application(void);

    static uint16_t sizeX;
    static uint16_t sizeY;

    // Children
    Menu* topMenu;
    Matrix* ledMatrix;
    LoggerField* logField;

private:
    const char* label = "matrixEditor";
};



/* C++ PROGRAM */

#include "matrixEditor.cpp"


#endif  /* !_MATRIXEDITOR_H_ */
