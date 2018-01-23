/* loggerField.h
 *
 * Logs / text output field
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _LOGGERFIELD_H_
#define _LOGGERFIELD_H_


/* DEPENDENCIES */

#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>



/* GLOBAL VARIABLES */

Fl_Text_Buffer* logs = new Fl_Text_Buffer();



/* CLASSES */

class LoggerField : public Fl_Text_Display {
public:
    LoggerField(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

    void write(const char str[]);
    void writeln(const char str[]);

    void clearBuffer(void);
    void readBuffer(uint16_t line);

private:
    Fl_Text_Buffer* logBuffer = logs;
};



/* C++ PROGRAM */

#include "loggerField.cpp"


#endif  /* !_LOGGERFIELD_H_ */
