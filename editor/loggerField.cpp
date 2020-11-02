/* loggerField.cpp
 *
 * Logs / text output field's functions
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _LOGGERFIELD_CPP_
#define _LOGGERFIELD_CPP_

#include "loggerField.h"


/* CLASSES METHODS */

LoggerField::LoggerField(uint16_t x, uint16_t y, uint16_t w, uint16_t h) :
    Fl_Text_Display(x, y, w, h)
{
    this->box(FL_NO_BOX);
    this->color(fl_rgb_color(LogsColors.bg));
    this->selection_color(fl_rgb_color(LogsColors.select));

    this->textcolor(fl_rgb_color(LogsColors.text));
    this->textfont(FL_SCREEN);
    this->textsize(10);

    this->buffer(this->logBuffer);
    this->logBuffer->append("Init Done\n");
}


void LoggerField::clearBuffer(void) {}


#endif  /* !_LOGGERFIELD_CPP_ */
