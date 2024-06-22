// controller.cpp
#include "controller.h"

void SnakeController::EatingAndCollision() {
    if(m_model->snake.eaten(m_model->food.get_pos())) {
        m_model->food.gen_food();
        m_model->snake.grow();
        m_score++;
    }
    if(m_model->snake.collided()) m_gameOver = true;

}

void SnakeController::Update() {
    m_model->snake.move_snake();
    // refresh();
}

Model* SnakeController::get_model() {
    return m_model;
}

int SnakeController::get_score() {
    return m_score;
}