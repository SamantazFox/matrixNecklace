/* menuEntries.h
 *
 * Menu bar items definition and callback functions header
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MENUENTRIES_H_
#define _MENUENTRIES_H_


/* DEPENDENCIES */

// FLTK Libraries
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_File_Chooser.H>



/* GLOBAL VARIABLES */

extern Fl_Text_Buffer* logs;



/* FUNCTIONS */

void foo(Fl_Widget*, void*);

void cb_open(Fl_Widget*, void*);



/* OBJECTS */

const Fl_Menu_Item __menu[] = {
    {"&File", 0, 0, 0, FL_SUBMENU},
        {"&New",        FL_CTRL+'n',          foo,     0},
        {"&Open",       FL_CTRL+'o',          cb_open, 0, FL_MENU_DIVIDER},
        {"&Save",       FL_CTRL+'s',          cb_open, 0},
        {"Save &As   ", FL_CTRL+FL_SHIFT+'s', cb_open, 0, FL_MENU_DIVIDER},
        {"&Quit",       FL_CTRL+'q',          foo,     0},
        {0},
    {"&Help", 0, 0, 0, FL_SUBMENU},
        {"Sho&w Help",            FL_F+1, foo, 0},
        {"&FAQ",                  0,        foo, 0, FL_MENU_DIVIDER},
        {"View &License",         0,        foo, 0, FL_MENU_DIVIDER},
        {"&About matrixNecklace", 0,        foo, 0},
        {0}
};



/* C++ PROGRAM */

#include "menuEntries.cpp"


#endif /* !_MENUENTRIES_H_ */
