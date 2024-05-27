#include "s21_board.hpp"
#include "s21_snake.hpp"
#include "s21_drawable.hpp"
#include <ncurses.h>
#include <iostream>

// #define BOARD_ROWS 20
// #define BOARD_COLS 10

using namespace std;
int main(int argc, char **argv) {
    initscr();
    refresh();

    noecho();
    curs_set(0); //turn off cursor

    SnakeGame game(BOARD_ROWS, BOARD_COLS, 300);

    while (!game.isOver()) {
        //1: get input from user
        game.processInput();
        //2: update game state
        game.updateState();
         //3: redraw display
        game.redraw();

      
    }
    //4: go to 1, unless game is over

    endwin();

    std::cout << "Your score: " << game.getScore() << " points" << std::endl;

    return 0;

}

// #include "s21_board.hpp"
// #include "s21_snake.hpp"
// #include "s21_drawable.hpp"
// #include <iostream>

// using namespace std;



// #ifdef USE_NCURSES
//     #include <ncurses.h>
// #else
//     // #include <QApplication>
//     // #include "s21_qt.hpp"
// #endif

// int main(int argc, char *argv[]) {
// SnakeGame* game = nullptr;
// #ifdef USE_NCURSES

// game = new SnakeGame(BOARD_ROWS, BOARD_COLS, 300);
// initscr();
// refresh();
   
// noecho();
// curs_set(0); //turn off cursor
   
//  while (!game->isOver()) {
//         //1: get input from user
//         game->processInput();
//         //2: update game state
//         game->updateState();
//         //3: redraw display
//         game->redraw();
    
//    }
//     endwin();
//     std::cout << "Your score: " << game->getScore() << " points" << std::endl;
//     delete game;

// #else
//     // QApplication app(argc, argv);
//     // game = new QtGame();
// #endif


//     return 0;
// }