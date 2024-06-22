#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstdlib>
#include <vector>
// #include <QGraphicsScene>

#define WIDTH 20
#define HEIGHT 10

using namespace std;

struct COORD {int X, Y;};

class Model {

class Snake
{
    public:
    COORD pos;
    unsigned long len;
    int vel;
    char direction;
    vector <COORD> body;

    enum SnakeDirection
        {
            up,
            left,
            down,
            right
        };

    public:

    Snake(COORD pos, int vel);
    void change_dir(char dir);
    void move_snake();
    COORD get_pos();

    bool eaten(COORD food_pos);

    void grow();
    bool collided();

    vector <COORD> get_body();

};


class Food
{
    private:
        COORD pos;

    public:
        Food();
        void gen_food();

        COORD get_pos();
};

public:
Snake snake;
Food food;

Model() : snake({WIDTH/2, HEIGHT/2}, 1),food() {}
};

#endif //MODEL_H
