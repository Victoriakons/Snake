#include "../../gui/s21_board.hpp"
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









// // Абстрактный класс игры
// class Game {
// public:
//     virtual void run() = 0;
//     virtual void handleInput() = 0;
//     virtual void update() = 0;
//     virtual void draw() = 0;
//     // ...
// };

// // Конкретная реализация игры для ncurses
// class NcursesGame : public Game {
// public:
//     void run() override {
//         // Инициализация ncurses
//         initscr();
//         curs_set(0);
        
//         while (true) {
//             handleInput();
//             update();
//             draw();
//             refresh();
//         }
        
//         endwin();
//     }
    
//     void handleInput() override {
//         // Обработка ввода с клавиатуры в ncurses
//         int ch = getch();
//         // ...
//     }
    
//     void update() override {
//         // Обновление состояния игры
//         // ...
//     }
    
//     void draw() override {
//         // Отрисовка игры в ncurses
//         // ...
//     }
// };

// // Конкретная реализация игры для Qt
// class QtGame : public Game, public QWidget {
// public:
//     void run() override {
//         // Инициализация Qt
//         show();
        
//         while (true) {
//             handleInput();
//             update();
//             draw();
//             QApplication::processEvents();
//         }
//     }
    
//     void handleInput() override {
//         // Обработка ввода с клавиатуры в Qt
//         // ...
//     }
    
//     void update() override {
//         // Обновление состояния игры
//         // ...
//     }
    
//     void draw() override {
//         // Отрисовка игры в Qt
//         // ...
//     }
// };

// int main(int argc, char *argv[]) {
//     // Выбор реализации игры
//     Game* game;
//     if (useNcurses) {
//         game = new NcursesGame();
//     } else {
//         QApplication app(argc, argv);
//         game = new QtGame();
//     }
    
//     game->run();
//     delete game;
//     return 0;
// }