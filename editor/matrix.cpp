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
    // Set the matrix as non-resizable, because Leds can't handle it
    this->resizable(0);

    // 'Led' elements are all children of 'Matrix'
    // Their UID defines their position
    for (uint8_t i = 0; i < this->ledCount; i++) {
        this->add( new Led(i, false) );
    }

    this->end();
}


uint64_t Matrix::getData(Matrix* mtrx)
{
    // Define local variables and initialize a 64-bits output buffer
    Led* children[mtrx->ledCount] = {0};
    Led* child;
    uint64_t out;

    // Make an index-ordered array of matrix' children
    for (uint8_t c = 0; c < mtrx->ledCount; c++) {
        child = (Led*) ((Fl_Group*) mtrx)->child(c);
        children[child->index] = child;
    }

    // Travel through every 'Led' in the array
    // and fill the output buffer with chikdren states
    for (int i = mtrx->ledCount - 1; i >= 0; i--) {
        if (children[i]->value())
            out |= (1L<<i);
        else
            out &= ~(1L<<i);
    }

    // Verbose to logs and return
    Matrix::debugIO(RD, out);
    return out;
}

void Matrix::setData(Matrix* mtrx, uint64_t data)
{
    // Define local variables
    Led* children[mtrx->ledCount] = {0};
    Led* child;

    // Verbose to logs
    Matrix::debugIO(WR, data);

    // Make an index-ordered array of matrix' children
    for (uint8_t c = 0; c < mtrx->ledCount; c++) {
        child = (Led*) ((Fl_Group*) mtrx)->child(c);
        children[child->index] = child;
    }

    // Set the child state from data
    for (uint8_t i = 0; i < mtrx->ledCount; i++) {
        children[i]->write( (bool) (data & 0x1) );
        data >>= 1;
    }
}


void Matrix::debugIO(DbgModes mode, uint64_t data)
{
    // Initialize local variables
    uint8_t nib;
    unsigned char c[17] = {0};

    // change text depending on mode
    if (mode == WR)
        logs->append("Write: 0x");
    else
        logs->append("Save:  0x");

    // Loop for data, 4-bits at a time
    for(uint8_t i = 0; i < 16; i++) {
        nib = (uint8_t) (data & 0x0F);
        c[i] = (nib<10) ? (nib+48) : ( (nib<16) ? (nib+55) : '0');

        // Shift data for next nibble
        data >>= 4;
    }

    // Write data and end by newline
    logs->append( (const char*) c );
    logs->append("\n");
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


void Led::write(bool state)
{
    if (state) { this->set();   this->image(led_on);  }
    else       { this->clear(); this->image(led_off); }

    this->redraw();
}

int Led::handle(int event)
{
    switch (event) {
        case FL_PUSH:
            if (Fl::event_button() == FL_LEFT_MOUSE) {
                this->write( !this->value() );
                return 1;
            }
            else { return 0; }
        default:
            return Fl_Widget::handle(event);
    }
    return 0;
}


#endif  /* !_MATRIX_CPP_ */
