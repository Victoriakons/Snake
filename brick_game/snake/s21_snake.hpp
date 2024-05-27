#pragma once
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "../../gui/s21_board.hpp"
#include "s21_drawable.hpp"
#include "s21_apple.hpp"
#include "s21_empty.hpp"
#include "s21_snakebody.hpp"
#include "../../gui/s21_scoreboard.hpp"


class SnakeGame{
    Board board;
    bool game_over;
    Apple *apple;
    Snake snake;
    Scoreboard scoreboard;
    int score;

    void handleNextPiece(SnakePiece next) {
        if (apple != NULL) {
            switch (board.getCharAt(next.getY(), next.getX())) {
                case 'A':
                eatApple();
                break;

                case ' ':
                {
                int emptyRow = snake.tail().getY();
                int emptyCol = snake.tail().getX();
                board.add(Empty(emptyRow, emptyCol));
                snake.removePiece();
                break;
                }
                default:
                game_over = true;
                break;
            }

        }
      
        board.add(next);
        snake.addPiece(next);

    }


    void createApple() {

            int y, x;
            board.getEmptyCoordinates(y,x);
            apple = new Apple(y, x);
            board.add(*apple);

    }

    void eatApple(){
        delete apple;
        apple = NULL;
        score += 1;
        scoreboard.updateScore(score);
    }
    public:
    SnakeGame(int height, int width, int speed = 1000)
    {
        board = Board(height, width, speed);
        int sb_row = board.getStartRow() + height;
        int sb_col = board.getStartCol();
        scoreboard = Scoreboard(width, sb_row, sb_col);
        initialize();
    }

    ~SnakeGame()
    {
        delete apple;
    }

    void initialize()
    {
       apple = NULL;
       board.initialize();
       score = 0;
       scoreboard.initialize(score);
       game_over = false;
       srand(time(NULL));
       snake.setDirection(down);

       handleNextPiece(SnakePiece(1, 1));
       handleNextPiece(snake.nextHead());
       handleNextPiece(snake.nextHead());

       snake.setDirection(right);

       handleNextPiece(snake.nextHead());

       
       if (apple == NULL)
       {
       createApple();
       }
    }

    void processInput()
    {
        // chtype input = board.getInput();
        // int old_timeout = board.getTimeout();
        int input = board.getInput();
        switch (input) {
            case KEY_UP:
            case 'w':
            snake.setDirection(up);
            break;

            case KEY_DOWN:
            case 's':
            //do something
            snake.setDirection(down);
            break;

            case KEY_RIGHT:
            case 'd':
            //do something
            snake.setDirection(right);
            break;

            case KEY_LEFT:
            case 'a':
            //do something
            snake.setDirection(left);
            break;

            case 'p':
            board.setTimeout(-1);
            //do something
            while (board.getInput() != 'p')
            // board.setTimeout(old_timeout);
            board.setTimeout(1000);
            break;

            default:
            break;
        }
    }
    void updateState(){
          handleNextPiece(snake.nextHead());
        
        if (apple == NULL)
        {
            createApple();

            }
    }

    void redraw(){
        board.refresh();
        scoreboard.refresh();

    }

    bool isOver(){
        return game_over;

    }
    int getScore()
    {
        return score;
    }

};

