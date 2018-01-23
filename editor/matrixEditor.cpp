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
    Fl_Menu_Bar* topMenu = makeMenu();
    win->add(topMenu);

    // Leds are all children of 'ledMatrix'. Their UID defines their position.
    Fl_Group* ledMatrix = new Fl_Group(0, 30, Led::lineSize, Led::lineSize);
    for (uint8_t i = 0; i < 64; i++) ledMatrix->add( new Led(i, false) );
    ledMatrix->end();
    win->add(ledMatrix);

    // Logs / text output field
    LoggerField* logF = new LoggerField(0, (Led::lineSize + 30), Led::lineSize, 100);
    win->add(logF);

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
