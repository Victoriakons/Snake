#pragma once
#include <ncurses.h>
#include "s21_drawable.hpp"

class Empty : public Drawable
{
    public:
    Empty(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->icon = ' ';
    }

};