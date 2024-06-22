// consoleView.h
#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#pragma once
#include <iostream>
#include <ncurses.h>
#include <ctime>

#include "controller.h"

class ConsoleView {
private:
SnakeController *m_controller;

public:
    ConsoleView(SnakeController *c) : m_controller(c) {};

    void StartView();
    void board();
    void NcursesInput();
    void Input();
    void NcursesEnd();


};

#endif //CONSOLEVIEW_H