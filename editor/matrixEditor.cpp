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


/* CLASS "Led" */

Led::Led(int x, int y, bool state) : Fl_Button(x, y, this->dotSize, this->dotSize)
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

Fl_Double_Window* Application::makeWindow(void)
{
    // Create main window
    Fl_Double_Window* win = new Fl_Double_Window(this->sizeX, this->sizeY, this->label);

    // Create different childs
    Fl_Group* ledMatrix = new Fl_Group(0, 0, this->sizeX, this->sizeY);

    // Create the buttons matrix. Each line is a Fl_Group containing eight Led
    // The whole matrix is then nested in the Fl_Group "ledMatrix"
    for (int i = 0; i < 8; i++) {
        ledMatrix->add( new Fl_Group(0, (i * Led::dotSize), (Led::dotSize * 8), Led::dotSize) );

        for (int j = 0; j < 8; j++) {
            ((Fl_Group*) ledMatrix->child(i))->add( new Led((j * Led::dotSize), (i * Led::dotSize), 0) );
            ((Fl_Group*) ledMatrix->child(i))->end();
        }
    }

    ledMatrix->end();
    win->add(ledMatrix);

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


#endif  /* !_MATRIXEDITOR_H_ */
