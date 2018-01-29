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

    // File operation (open, save and export) callbacks
    static void cb_open(Fl_Widget* wdg, void*);
    static void cb_save(Fl_Widget* wdg, void* as);
    static void cb_export(Fl_Widget* wdg, void* as);

    // Edit menu callbacks
    static void cb_undo(Fl_Widget* wdg, void*);
    static void cb_redo(Fl_Widget* wdg, void*);
    static void cb_rand(Fl_Widget* wdg, void*);

    // Help menu callbacks
    static void cb_help(Fl_Widget* wdg, void*);
    static void cb_faq(Fl_Widget* wdg, void*);
    static void cb_license(Fl_Widget* wdg, void*);
    static void cb_about(Fl_Widget* wdg, void*);

    // Miscellanous callbacks
    static void cb_quit(Fl_Widget* wdg, void*);

private:
    static inline Application* mainWindow(Fl_Widget* wdg);
};



/* MENU ITEMS TREE */

const Fl_Menu_Item __menu[] = {
    {"&File", FL_ALT+'f', 0, 0, FL_SUBMENU},
        {"&New",          FL_CTRL+'n',          Menu::foo,       0},
        {"&Open",         FL_CTRL+'o',          Menu::cb_open,   0,            FL_MENU_DIVIDER},
        {"&Save",         FL_CTRL+'s',          Menu::cb_save,   (void*) false},
        {"Save &As",      FL_CTRL+FL_SHIFT+'s', Menu::cb_save,   (void*) true, FL_MENU_DIVIDER},
        {"&Export",       FL_CTRL+'e',          Menu::cb_export, (void*) false},
        {"E&xport As  ",  FL_CTRL+FL_SHIFT+'e', Menu::cb_export, (void*) true, FL_MENU_DIVIDER},
        {"&Quit",         FL_CTRL+'q',          Menu::cb_quit,   0},
        {0},
    {"&Edit", FL_ALT+'e', 0, 0, FL_SUBMENU},
        {"&Undo",      FL_CTRL+'z', Menu::cb_undo, 0},
        {"Re&do",      FL_CTRL+'y', Menu::cb_redo, 0, FL_MENU_DIVIDER},
        {"Randomi&ze", FL_CTRL+'r', Menu::cb_rand, 0},
        {0},
    {"&Help", FL_ALT+'h', 0, 0, FL_SUBMENU},
        {"Sho&w Help",            FL_F+1, Menu::cb_help,    0},
        {"&FAQ",                  0,      Menu::cb_faq,     0, FL_MENU_DIVIDER},
        {"View &License",         0,      Menu::cb_license, 0, FL_MENU_DIVIDER},
        {"&About matrixNecklace", 0,      Menu::cb_about,   0},
        {0}
};



/* C++ PROGRAM */

#include "menuEntries.cpp"


#endif /* !_MENUENTRIES_H_ */
