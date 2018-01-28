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



/* CLASS "Menu" */

class Menu : public Fl_Menu_Bar {
public:
    Menu(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

    // Placeholder callback
    static void foo(Fl_Widget*, void*);

    // Callbacks for the different menu items
    static void cb_open(Fl_Widget* wdg, void*);
    static void cb_save(Fl_Widget* wdg, void*);
};



/* MENU ITEMS TREE */

const Fl_Menu_Item __menu[] = {
    {"&File", 0, 0, 0, FL_SUBMENU},
        {"&New",        FL_CTRL+'n',          Menu::foo,     0},
        {"&Open",       FL_CTRL+'o',          Menu::cb_open, 0, FL_MENU_DIVIDER},
        {"&Save",       FL_CTRL+'s',          Menu::cb_save, 0},
        {"Save &As   ", FL_CTRL+FL_SHIFT+'s', Menu::cb_save, 0, FL_MENU_DIVIDER},
        {"&Quit",       FL_CTRL+'q',          Menu::foo,     0},
        {0},
    {"&Help", 0, 0, 0, FL_SUBMENU},
        {"Sho&w Help",            FL_F+1, Menu::foo, 0},
        {"&FAQ",                  0,      Menu::foo, 0, FL_MENU_DIVIDER},
        {"View &License",         0,      Menu::foo, 0, FL_MENU_DIVIDER},
        {"&About matrixNecklace", 0,      Menu::foo, 0},
        {0}
};



/* C++ PROGRAM */

#include "menuEntries.cpp"


#endif /* !_MENUENTRIES_H_ */
