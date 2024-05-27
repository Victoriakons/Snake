#pragma once
// #include <ncurses.h>


class Scoreboard
{
    WINDOW *score_win;

    public:
    Scoreboard() {

    }

    Scoreboard(int width, int y, int x) {
        score_win = newwin(1, width, y, x);

    }

    void initialize(int initial_score) {
        clear();
        mvwprintw(score_win, 0, 0, "Score:");
        updateScore(initial_score);
        refresh();

    }

    void updateScore(int score) {
        werase(score_win);
        mvwprintw(score_win, 0, 0, "Score: %22llu", score);
        wrefresh(score_win);

    }

    void clear() {
        wclear(score_win);

    }
    void refresh(){
        wrefresh(score_win);

    }
};