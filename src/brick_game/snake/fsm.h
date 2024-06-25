#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <vector>

#include "model.h"
#include "controller.h"

using namespace std;

enum class State { EAT, MOVE, GAME_OVER };

class FSM {
public:
    FSM(SnakeController* controller);
    void update(); 

private:
    State m_state;
    SnakeController* m_controller;
    void updateEating();
    void updateMove();
    void updateGameOver();
    // void updateDirection();
};

#endif // FSM_H
