// consoleView.cpp
#include "consoleView.h"

void ConsoleView::StartView() {
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);
}

void ConsoleView::board() {
    COORD snake_pos = m_controller->get_model()->snake.get_pos();
    COORD food_pos = m_controller->get_model()->food.get_pos();

    vector<COORD> snake_body = m_controller->get_model()->snake.get_body();

    mvprintw(HEIGHT+1, 0, "SCORE : %d", m_controller->get_score());
    refresh();

    for(int i = 0; i < HEIGHT; i++) {
        mvprintw(i, 0, "#");
        for(int j = 0; j < WIDTH - 2; j++) {
            if(i == 0 || i == HEIGHT - 1) mvprintw(i, j, "#");
            else if(i == snake_pos.Y && j == snake_pos.X) mvprintw(i, j, "0");
            else if(i == food_pos.Y && j == food_pos.X) mvprintw(i, j, "@");
            else {
                bool isBodyPart = false;
                for(int k = 0; k < snake_body.size() - 1; k++) {
                    if(i == snake_body[k].Y && j == snake_body[k].X) {
                        mvprintw(i, j, "o");
                        isBodyPart = true;
                        break;
                    }
                }

                if(!isBodyPart) mvprintw(i, j, " ");
            }
        }
        mvprintw(i, WIDTH - 1, "#");
    }
}

void ConsoleView:: NcursesInput() {
     refresh();
     keypad(stdscr, TRUE);
     mvprintw(HEIGHT+1, 0, "SCORE : %d", m_controller->get_score());
     refresh();
}

void ConsoleView::Input() {
    int ch = getch();

    switch(ch) {
        case KEY_UP:
            m_controller->get_model()->snake.change_dir('u');
            break;

        case KEY_DOWN:
            m_controller->get_model()->snake.change_dir('d');
            break;

        case KEY_LEFT:
            m_controller->get_model()->snake.change_dir('l');
            break;

        case KEY_RIGHT:
            m_controller->get_model()->snake.change_dir('r');
            break;
    }
}



void ConsoleView:: NcursesEnd() {
    endwin();
}
