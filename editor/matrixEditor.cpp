/* matrixEditor.cpp
 *
 * Main file for the matrixNecklace editor
 *
 * Copyright 2017 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIXEDITOR_CPP_
#define _MATRIXEDITOR_CPP_

#include "matrixEditor.h"


/* GLOBAL VARIABLES */

// Initialize dot matrix button inputs
static Led* matrix[8][8] = { (Led*) 0 };



/* CLASS "Led" */

Led::Led(int x, int y, bool state) : Fl_Toggle_Button(x, y, MTX_DOT_SIZE, MTX_DOT_SIZE)
{
    this->box(FL_FRAME_BOX);
    this->down_box(FL_NO_BOX);

    if (state) { this->value(1); this->image(led_on); }
    else { this->value(0); this->image(led_off); }
}

void Led::invert(void)
{
    if (this->value()) { this->value(0); this->image(led_off); }
    else { this->value(1); this->image(led_on); }

    this->redraw();
}

int Led::handle(int event)
{
    switch (event) {
        case FL_PUSH:
            if (Fl::event_button() == FL_LEFT_MOUSE) { this->invert(); return 1; }
            else { return 0; }
        default:
            return Fl_Widget::handle(event);
    }
}



/* CLASS "Application" */

int Application::run(void)
{
    while (Fl::wait());
    return 1;
}

Fl_Double_Window* Application::makeWindow(void)
{
    // Create main window
    Fl_Double_Window* w = new Fl_Double_Window(this->sizeX, this->sizeY, this->label);

    // Create buttons matrix
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matrix[i][j] = new Led(j*MTX_DOT_SIZE, i*MTX_DOT_SIZE, 0);
            matrix[i][j]->value( (i*8 + j) % 2 );
        }
    }

    // Select double buffering and full color
    Fl::visual(FL_DOUBLE|FL_RGB);

    // Finish creating window and return object to caller
    w->end();
    return w;
}



/* MAIN PROGRAM */

int main(int argc, char* argv[]) {
    // Create application object
    Application app;

    // Create the main window
    Fl_Double_Window* window = app.makeWindow();
    window->show(argc, argv);

    // Run !
    return app.run();
}


#endif  /* !_MATRIXEDITOR_H_ */
