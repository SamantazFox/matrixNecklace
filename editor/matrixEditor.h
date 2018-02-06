/* matrixEditor.h
 *
 * Main file's header containing definitions and library calls
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIXEDITOR_H_
#define _MATRIXEDITOR_H_


/* CONSTANTS */

#define BG_COLOR 0x44
#define TEXT_COLOR 0xE5
#define SELECT_COLOR 0x95



/* CLASSES */

class Application;
class Menu;
class Matrix;
class Led;
class LoggerField;



/* DEPENDENCIES */

// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdlib>

// FLTK libraries
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Text_Buffer.H>



/* CLASS "Application" */

class Application : public Fl_Double_Window {
public:
    Application(void);

    // Children
    Menu* topMenu;
    Matrix* ledMatrix;
    LoggerField* logField;

private:
    const char* label = "matrixEditor";
    Fl_Image* ico = new Fl_PNG_Image("images/icon_48x48.png");
};



/* OTHER FILES FOR THIS PROJECT */

#include "loggerField.h"
#include "matrix.h"
#include "menuEntries.h"



/* C++ PROGRAM */

#include "matrixEditor.cpp"


#endif  /* !_MATRIXEDITOR_H_ */
