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
    this->box(FL_FLAT_BOX);
    this->color(fl_rgb_color(0x55));

    this->textcolor(fl_rgb_color(0xE5));
    this->textfont(FL_COURIER);
    this->textsize(11);

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
    // Get a pointer to ledMatrix, and pass it to getData()
    Matrix* matrix = ((Application*) wdg->window())->ledMatrix;
    uint8_t* out = Matrix::getData(matrix);

    // Print an hexadecimal value of the returned data
    printf("Out: 0x");
    for(int i=0; i < 8; i++) printf("%.2hhx", out[i]);
    printf("\n");

    // Free the memory block that getData allocated
    free(out);
}



#endif  /* !_MENUENTRIES_CPP_ */
