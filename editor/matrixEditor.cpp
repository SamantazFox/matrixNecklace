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

Application::Application(void) :
    Fl_Double_Window(Led::lineSize, (130 + Led::lineSize), this->label)
{
    // Add an icon to the top level window
    this->top_window()->icon((Fl_RGB_Image*) this->ico);

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

    // Finish creating window
    this->end();
}



/* MAIN PROGRAM */

int main(int argc, char* argv[]) {
    // Create application object
    Application* app = new Application();

    // Create the main window
    app->show(argc, argv);

    // Run !
    return Fl::run();
}


#endif  /* !_MATRIXEDITOR_CPP_ */
