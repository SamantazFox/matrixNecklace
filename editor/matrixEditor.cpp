/* matrixEditor.cpp
 *
 * Main file for the matrixNecklace editor
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIXEDITOR_CPP_
#define _MATRIXEDITOR_CPP_

#include "matrixEditor.h"


/* CLASS "Application" */

Fl_Double_Window* Application::makeWindow(void)
{
    // Create main window
    Fl_Double_Window* win = new Fl_Double_Window(Led::lineSize, (130 + Led::lineSize), this->label);

    // Menu Bar at the top of the window
    this->topMenu = new Menu(0, 0, 512, 30);
    this->add(topMenu);

    // Matrix is a 8x8 Leds array.
    this->ledMatrix = new Matrix(0, 30);
    this->add(ledMatrix);

    // Logs / text output field
    this->logField = new LoggerField(0, (Led::lineSize + 30), Led::lineSize, 100);
    this->add(logField);

    // Select double buffering and full color
    Fl::visual(FL_DOUBLE|FL_RGB);

    // Finish creating window and return object to caller
    win->end();
    return win;
}



/* MAIN PROGRAM */

int main(int argc, char* argv[]) {
    // Create application object
    Application app;

    // Create the main window
    Fl_Double_Window* window = app.makeWindow();
    window->show(argc, argv);

    // Run !
    return Fl::run();
}


#endif  /* !_MATRIXEDITOR_CPP_ */
