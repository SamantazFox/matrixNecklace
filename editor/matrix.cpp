/* matrix.cpp
 *
 * Leds and Led matrix objects/methods
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MATRIX_CPP_
#define _MATRIX_CPP_

#include "matrix.h"


/* CLASS "Led" */

Led::Led(uint8_t index, bool state) :
    Fl_Button(0, 0, this->dotSize, this->dotSize)
{
    this->index = index;
    this->position(
        (int) (index / 8) * this->dotSize + this->parent()->x(),
        (int) (index % 8) * this->dotSize + this->parent()->y()
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


#endif  /* !_MATRIX_CPP_ */
