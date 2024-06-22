#include "model.h"

Model::Snake::Snake(COORD pos, int vel) {
    this->pos = pos;
    this->vel = vel;
    len = 4;
    direction = 'r';

    body.push_back(pos);
}

void Model::Snake::change_dir(char dir) {
    direction = dir;

}

bool Model::Snake::eaten(COORD food_pos)
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y) return true;
    else return false;
}

void Model::Snake::move_snake() {
    switch(direction)
    {
        case 'u':
        pos.Y -= vel;
        break;

        case 'd':
        pos.Y += vel;
        break;

        case 'l':
        pos.X -= vel;
        break;

        case 'r':
        pos.X += vel;
        break;
    }
    body.push_back(pos);
    if(body.size() > len) body.erase(body.begin());
}


COORD Model::Snake::get_pos() {
    return pos;
}

void Model::Snake::grow() {
    len++;
}

bool Model::Snake::collided(){
    if (pos.X < 1 || pos.X > WIDTH || pos.Y < 1 || pos.Y > HEIGHT)
    return true;

    for(unsigned long i = 0; i < body.size() - 1; i++)
    {
        if(pos.X == body[i].X && pos.Y == body[i].Y)
        return true;
    }
    return false;
}

vector <COORD> Model::Snake::get_body() {
    return body;
}

Model::Food::Food() {
    gen_food();
}

void Model::Food::gen_food(){
    pos.X = (rand() % (WIDTH - 3)) + 1;
    pos.Y = (rand() % (HEIGHT - 3)) + 1;
}

COORD Model::Food::get_pos() {
    return pos;
}
