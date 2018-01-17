/* menuEntries.cpp
 *
 * Callback function for every item defined under menuEntries.h
 *
 * Copyright 2017 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MENUENTRIES_CPP_
#define _MENUENTRIES_CPP_

#include "menuEntries.h"


/* FUNCTIONS */

void foo(Fl_Widget*, void*) {}

void cb_open(Fl_Widget*, void*) {
    char* path = fl_file_chooser("Select File", "MatrixNecklace sequence file (*.mnl)", ".");
    printf("%s\n", path);
}


Fl_Menu_Bar* makeMenu(void) {
    Fl_Menu_Bar* topMenu = new Fl_Menu_Bar(0, 0, 512, 30);

    topMenu->menu(__menu);
    return topMenu;
}



#endif  /* !_MENUENTRIES_CPP_ */
