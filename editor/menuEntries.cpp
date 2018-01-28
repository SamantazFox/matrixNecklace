/* menuEntries.cpp
 *
 * Callback function for every item defined under menuEntries.h
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MENUENTRIES_CPP_
#define _MENUENTRIES_CPP_

#include "menuEntries.h"


/* CLASS "Menu" */

Menu::Menu(uint16_t x, uint16_t y, uint16_t w, uint16_t h) :
    Fl_Menu_Bar(x, y, w, h)
{
    this->menu(__menu);
}


void Menu::foo(Fl_Widget*, void*) {}

void Menu::cb_open(Fl_Widget* wdg, void*)
{
    char* path = fl_file_chooser("Select File", "MatrixNecklace sequence file (*.mnl)", ".");
    logs->append("Open file: ");
    logs->append(path);
}

void Menu::cb_save(Fl_Widget* wdg, void*)
{
    //Application* app = (Application*) wdg->top_window();
    Fl_Double_Window* app = (Fl_Double_Window*) wdg->top_window();
    uint64_t out = Matrix::getData((Matrix*) app->child(0));
    printf("%lx\n, ", out);
}



#endif  /* !_MENUENTRIES_CPP_ */
