#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
//#include <s21_main.hpp>

const int x_max = 100;
const int y_max = 25;

enum Rotation {
    left,
    right,
    up,
    down
};

struct Position {
    int x;
    int y;
};

class Field {
    public:
    char field[y_max][x_max + 1];
    void CreateBoundaries(char ch);
    void Show();
    // void SpownPrice();

};

class Snake {
    private:
    int length;
    Position snakePos[1000];
    Rotation snakeRot;

    public:
    Snake(int _length, Rotation _snakeRot):
    length(_length), snakeRot(_snakeRot){};
    void ToStartValues();
    void Move(char field[y_max][x_max + 1]);
    // bool IsGameOver();
    // void AddTail();
};


void Snake::ToStartValues()
{
    for(int i = 0; i < length; i++)
    {
        snakePos[i].x = 0;
        snakePos[i].y = 0;
    }

    length = 1;
    snakePos[0] = {x_max/2, y_max /2};

    move(snakePos[0].y, snakePos[0].x);
    addch('o');
    refresh();



}

void Snake::Move(char field [y_max][x_max + 1])
{
    int ch = getch();

    switch(ch){
        case KEY_UP:
        case 'w':
        snakeRot = up;
        break;

        case KEY_DOWN:
        case 's':
        //do something
        snakeRot =down;
        break;

        case KEY_RIGHT:
        case 'd':
        //do something
        snakeRot =right;
        break;

        case KEY_LEFT:
        case 'a':
        //do something
        snakeRot =left;
        break;

        case 'p':
        //do something
        while (snakeRot != 'p')
        break;

        default:
        break;
        }
        field[snakePos[length - 1].y][snakePos[length - 1].x] = ' ';
        for (int i = length; i >= 0; i--)
        {
            snakePos[i] = snakePos[i - 1];
        }

        switch(snakeRot)
        {
            case up:
            snakePos[0].y = snakePos[0].y-1;
            break;

            case down:
            snakePos[0].y = snakePos[0].y+1;
            break;

            case left:
            snakePos[0].x = snakePos[0].x-2;
            break;

            case right:
            snakePos[0].x = snakePos[0].x+2;
            break;
        }
        field[snakePos[0].y][snakePos[0].x] = 'o';
        if(length > 1)
        {
            field[snakePos[1].y][snakePos[1].x] = '*';
        }
        refresh();
    }


void Field::CreateBoundaries(char ch){
    for(int y = 0; y < y_max; y++) 
    {
        for (int x = 0; x < x_max; x++)
        {
            if(y == 0 || y == y_max - 1 || x == 0 || x == x_max - 1) 
            {
                field[y][x] = ch;
            }
            else 
            {
                field[y][x] = ' ';
            }
        }
        field[y][x_max] = '\0';
    }
    };

void Field::Show()
{
    move(0, 0);
    for(int y = 0; y < y_max; y++)
    {
        // printf("%s\n", field[0]);
        printw("%s\n", field[y]);
    }
    refresh();

};


// void Field::SpownPrice()
// {
//     int x = rand() % (x_max - 2) + 1;
//     int y = rand() % (y_max - 2) + 1;
    
//     bool isSpawn = false;
//     while(true)
//     {
//         if(x%2 == 0) isSpawn = true;
//         if(field[y][x] == 'o' || field[y][x] == '*') isSpawn = false;
//         if(isSpawn) break;
//         x = rand() % (x_max - 2) + 1;
//     }
//     field[y][x] = '$';
// }

//     bool Snake::IsGameOver(){
//         bool IsGameOver = false;
//         if(snakePos[0].x <= 0 || snakePos[0].x >= x_max - 1 || snakePos[0].y <= 0 || snakePos[0].y >= y_max - 1)
//         {
//             IsGameOver = true;
//         }
//        for (int i = 2; i < length; i++)
//        {
//         if(snakePos[0].x == snakePos[i].x && 
//            snakePos[0].y == snakePos[i].y)
//            {
//             IsGameOver = true;
//            }
//        }
//        return IsGameOver;
    
//     }

// void Snake::AddTail(){
//     snakePos[length].x = snakePos[length - 1].x;
//     snakePos[length].y = snakePos[length - 1].y;

//     length ++;

// }


    int main() {
    srand(time(NULL));
    initscr();
    noecho();
    Field gameField;
    Snake snake(1, up);

    gameField.CreateBoundaries(219);
    gameField.Show();
    snake.ToStartValues();
    move(y_max+1, 0);

//     for (int i = 0; i < 20; i++)
//     gameField.SpownPrice();

//     snake.AddTail();
//     snake.AddTail();
//     snake.AddTail();

    while(true)
    {
        // if (snake.IsGameOver()) break;

        snake.Move(gameField.field);
        gameField.Show();

        sleep(85);
    }  
//     getchar();

refresh();

getch();
return 0;

    }
