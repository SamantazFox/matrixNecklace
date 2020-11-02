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
    Fl_Double_Window(0, 0, this->label)
{
    // Add an icon to the top level window
    this->top_window()->icon((Fl_RGB_Image*) this->ico);

    // Set elements' base sizes
    uint16_t topMenu_h = 30;
    uint16_t logs_h = 100;

    // In order to properly draw elements, we should get track of where we are
    Pos offset {0, 0};

    // set the final size of the window
    this->size(
        Led::lineSize,
        topMenu_h + Led::lineSize + logs_h
    );

    // Menu Bar at the top of the window
    this->topMenu = new Menu(offset.x, offset.y, this->w(), topMenu_h);
    this->add(topMenu);
    offset.y += topMenu_h;

    // Resizing frame. This Tile element will include all the window's children,
    // minus the titlebar, which souldn't be resizeable
    Fl_Tile* frame = new Fl_Tile(offset.x, offset.y, this->w(), this->h() - offset.y);


    // Led Matrix (8x8 Leds array)
    this->ledMatrix = new Matrix(offset.x, offset.y);
    frame->add(ledMatrix);

    offset.y += Led::lineSize;

    // In order to make the logs/text output field resizable, we have to encapsulate
    // it in the 'frame' ("Tile" element define above)
    this->logField = new LoggerField(offset.x, offset.y, this->w(), logs_h);
    frame->add(logField);

    // Close the frame object, and add it to the window.
    frame->end();
    this->add(frame);

    /* Define the Fl_Tile 'frame' as the rezising box
     * Then, define minimum and maximum size for the window
     * Minimum is the size we computed above
     * Maximum is set to height = 0 (infinite) and width restrained to actual size
    */
    this->resizable(frame);
    this->size_range(this->w(), this->h(), this->w(), 0);

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
