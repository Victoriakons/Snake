
#pragma once
#include <ncurses.h>
#include "s21_drawable.hpp"

class Apple : public Drawable
{
    public:
    Apple(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->icon = 'A';
    }

};