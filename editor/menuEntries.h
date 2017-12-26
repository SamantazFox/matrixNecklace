/* menuEntries.h
 *
 * Menu bar related definitions
 *
 * Copyright 2017 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MENUENTRIES_H_
#define _MENUENTRIES_H_


/* DEPENDENCIES */

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>



/* FUNCTIONS */

void foo(Fl_Widget*, void*) {}



/* OBJECTS */

const Fl_Menu_Item __menu[] = {
    {"&File", 0, 0, 0, FL_SUBMENU},
        {"&New",        FL_CTRL+'n',          foo, 0},
        {"&Open",       FL_CTRL+'o',          foo, 0, FL_MENU_DIVIDER},
        {"&Save",       FL_CTRL+'s',          foo, 0},
        {"Save &As   ", FL_CTRL+FL_SHIFT+'s', foo, 0, FL_MENU_DIVIDER},
        {"&Quit",       FL_CTRL+'q',          foo, 0},
    {0},
    {"&Help", 0, 0, 0, FL_SUBMENU},
        {"Sho&w Help",            FL_F+1, foo, 0},
        {"&FAQ",                  0,        foo, 0, FL_MENU_DIVIDER},
        {"View &License",         0,        foo, 0, FL_MENU_DIVIDER},
        {"&About matrixNecklace", 0,        foo, 0},
    {0}
};


/* INITIALIZATION */

Fl_Menu_Bar* makeMenu(void) {
    Fl_Menu_Bar* topMenu = new Fl_Menu_Bar(0, 0, 512, 30);

    topMenu->menu(__menu);
    return topMenu;
}


#endif /* !_MENUENTRIES_H_ */
