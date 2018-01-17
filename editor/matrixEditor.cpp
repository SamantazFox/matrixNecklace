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

Led::Led(uint8_t index, bool state) : Fl_Button(0, 0, this->dotSize, this->dotSize)
{
    this->index = index;
    this->position(
        (int) (index / 8) * this->dotSize,
        (int) (index % 8) * this->dotSize + 30
    );

    this->box(FL_FRAME_BOX);
    this->down_box(FL_NO_BOX);

    if (state) { this->set(); this->image(led_on); }
    else { this->clear(); this->image(led_off); }
}

void Led::invert(void)
{
    if (this->value()) { this->clear(); this->image(led_off); }
    else { this->set(); this->image(led_on); }

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
    logs = new LoggerField(0, (Led::lineSize + 30), Led::lineSize, 100);
    win->add(logs);

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
