/* loggerField.cpp
 *
 * Logs / text output field's functions
 *
 * Copyright 2017 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _LOGGERFIELD_CPP_
#define _LOGGERFIELD_CPP_

#include "loggerField.h"


/* FUNCTIONS */




/* CLASSES METHODS */

LoggerField::LoggerField(uint16_t x, uint16_t y, uint16_t w, uint16_t h) :
    Fl_Text_Display(x, y, w, h)
{
    this->logBuffer = new Fl_Text_Buffer();
    this->buffer(this->logBuffer);
    this->writeln("Init Done.");
}


void LoggerField::write(const char str[])
{
    this->logBuffer->append(str);
}

void LoggerField::writeln(const char str[])
{
    this->logBuffer->append(str);
    this->logBuffer->append("\n");
}


void LoggerField::clearBuffer(void)
{
    return;
}

void LoggerField::readBuffer(uint16_t line)
{
    return;
}



#endif  /* !_LOGGERFIELD_CPP_ */
