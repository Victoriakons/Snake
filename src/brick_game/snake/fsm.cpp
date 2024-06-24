#include "fsm.h"

FSM::FSM(SnakeController* controller) : m_state(State::MOVE) {
}

void FSM::update() {
    switch (m_state) {
    case State::EAT:
        updateEating();
        break;
    // case State::MOVE:
    //     updateMove();
    //     break;
    // case State::GAME_OVER:
    //     updateGameOver();
    //     break;
    }
}



void FSM::updateEating() {
 if(m_controller->get_model()->snake.eaten(m_controller->get_model()->food.get_pos())) {
        m_controller->get_model()->food.gen_food();
        m_controller->get_model()->snake.grow();
        m_controller->set_score(m_controller->get_score() + 1);
        m_state = State::MOVE;
        
        } else if (m_controller->get_model()->snake.collided()) {
            m_state = State::GAME_OVER;
            } else { m_state = State::MOVE;
    }
}

void FSM::updateMove(){
    m_controller->get_model()->snake.move_snake();
     if (m_controller->get_model()->snake.collided()) {
        m_state = State::GAME_OVER;
        } else {
            m_state = State::EAT;
    }
}
void FSM::updateGameOver(){
    m_controller->get_model()->snake.collided();
    m_state = State::GAME_OVER;
}


