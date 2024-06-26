#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../gui/cli/s21_frontend.h"
#include "s21_backend.h"
#include "s21_util.h"

// Save and exit the game.
void save(GameStruct *game, WINDOW *w) {
  FILE *f;

  wclear(w);
  box(w, 0, 0);  // return the border
  wmove(w, 1, 1);
  wprintw(w, "Save and exit? [Y/n] ");
  wrefresh(w);
  timeout(-1);
  if (getch() == 'n') {
    timeout(0);
    return;
  }
  f = fopen("tetris.save", "w");
  Save(game, f);
  fclose(f);
  Delete(game);
  endwin();
  printf("Game saved to \"tetris.save\".\n");
  printf("Resume by passing the filename as an argument to this program.\n");
  exit(EXIT_SUCCESS);
}

GameStruct *Load(FILE *f) {
  GameStruct *obj = malloc(sizeof(GameStruct));
  fread(obj, sizeof(GameStruct), 1, f);
  obj->board = malloc(obj->rows * obj->cols);
  fread(obj->board, sizeof(char), obj->rows * obj->cols, f);
  return obj;
}

/*
  Save a game to a file.
 */
void Save(GameStruct *obj, FILE *f) {
  fwrite(obj, sizeof(GameStruct), 1, f);
  fwrite(obj->board, sizeof(char), obj->rows * obj->cols, f);
}

/*
  Print a game board to a file.  Really just for early debugging.
 */
void Print(GameStruct *obj, FILE *f) {
  int i, j;
  for (i = 0; i < obj->rows; i++) {
    for (j = 0; j < obj->cols; j++) {
      if (TC_IS_EMPTY(GetBlock(obj, i, j))) {
        fputs(TC_EMPTY_STR, f);
      } else {
        fputs(TC_BLOCK_STR, f);
      }
    }
    fputc('\n', f);
  }
}

// Main

int main(int argc, char **argv) {
  GameStruct *tg;
  tetris_move move = TM_NONE;
  bool running = true;
  WINDOW *board, *next, *hold, *score;

  if (argc >= 2) {
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
      perror("tetris");
      exit(EXIT_FAILURE);
    }
    tg = Load(f);
    fclose(f);
  } else {
    tg = CreateGame(22, 10);
  }

  // NCURSES initialization:
  initscr();             // initialize curses
  cbreak();              // pass key presses to program, but not signals
  noecho();              // don't echo key presses to screen
  keypad(stdscr, TRUE);  // allow arrow keys
  timeout(0);            // no blocking on getch()
  curs_set(0);           // set the cursor to invisible
  init_colors();         // setup  colors

  // Create windows for each section of the interface.
  board = newwin(tg->rows + 2, 2 * tg->cols + 2, 0, 0);
  next = newwin(6, 10, 0, 2 * (tg->cols + 1) + 1);
  hold = newwin(6, 10, 7, 2 * (tg->cols + 1) + 1);
  score = newwin(6, 10, 14, 2 * (tg->cols + 1) + 1);

  // Game loop
  while (running) {
    running = PerformTick(tg, move);
    display_board(board, tg);
    display_piece(next, tg->next);
    display_piece(hold, tg->stored);
    display_score(score, tg);
    doupdate();
    sleep_milli(10);

    switch (getch()) {
      case KEY_LEFT:
        move = TM_LEFT;
        break;
      case KEY_RIGHT:
        move = TM_RIGHT;
        break;
      case KEY_UP:
        move = TM_CLOCK;
        break;
      case KEY_DOWN:
        move = TM_DROP;
        break;
      case 'q':
        running = false;
        move = TM_NONE;
        break;
      case 'p':
        wclear(board);
        box(board, 0, 0);
        wmove(board, tg->rows / 2, (tg->cols * COLS_PER_CELL - 6) / 2);
        wprintw(board, "PAUSED");
        wrefresh(board);
        timeout(-1);
        getch();
        timeout(0);
        move = TM_NONE;
        break;
      case 's':
        save(tg, board);
        move = TM_NONE;
        break;
      case ' ':
        move = TM_HOLD;
        break;
      default:
        move = TM_NONE;
    }
  }

  // Deinitialize NCurses
  wclear(stdscr);
  endwin();

  // Output ending message.
  printf("Game over!\n");
  printf("You finished with %d points on level %d.\n", tg->points, tg->level);

  // Deinitialize Tetris
  Delete(tg);
  return 0;
}