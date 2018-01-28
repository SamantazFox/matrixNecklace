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


/* CLASS "Matrix" */

Matrix::Matrix(uint16_t x, uint16_t y) :
    Fl_Group(x, y, Led::lineSize, Led::lineSize)
{
    // 'Led' elements are all children of 'Matrix'
    // Their UID defines their position
    for (uint8_t i = 0; i < 64; i++) {
        this->add( new Led(i, false) );
    }
}


uint8_t* Matrix::getData(Matrix* mtrx)
{
    // Initialize an out buffer array of 8x8 bits
    uint8_t* out = (uint8_t*) malloc(8);

    // Define local variables
    Led* child;
    uint8_t idx, x, y;
    bool tmp;

    // Travel through every 'Led' in the array
    for (uint8_t i = 0; i < 64; i++) {
        // Get child and it's ID
        child = (Led*) ((Fl_Group*) mtrx)->child(i);
        idx = child->index;

        // Get child value
        tmp = child->value();

        // Calculate x and y pos from Led's index
        x = (uint8_t) idx % 8;
        y = (uint8_t) idx / 8;

        // Fill the output buffer with chikdren states
        // Each line of the matrix is stored in an uint8_t where :
        //  - Led at position x = 0 is the LSB
        //  - Led at position x = 7 is the MSB.
        if (tmp) out[y] |= (1<<x);
        else     out[y] &= ~(1<<x);
    }

    return out;
}



/* CLASS "Led" */

Led::Led(uint8_t index, bool state) :
    Fl_Button(0, 0, this->dotSize, this->dotSize)
{
    this->index = index;
    this->position(
        (int) (index % 8) * this->dotSize + this->parent()->x(),
        (int) (index / 8) * this->dotSize + this->parent()->y()
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
