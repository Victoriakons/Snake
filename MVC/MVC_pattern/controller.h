// controller.h
#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once
#include "model.h"
#include "ncurses.h"


class SnakeController {
public:
    SnakeController(Model* model, int score) : m_model(model), m_score(score) {};
    // void Input();
    void Update();
    void EatingAndCollision();
    bool isGameOver() { return m_gameOver; }
    Model* get_model();
    int get_score();

private:
    Model* m_model;
    int m_score;
    bool m_gameOver = false;
};

#endif //CONTROLLER_H