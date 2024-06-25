# Define the target name
TARGET = snake_ncurses
TARGET2 = tetris_ncurses
# Define the source files
SRCS = brick_game/snake/main1.cpp gui/desktop/consoleView.cpp brick_game/snake/model.cpp brick_game/snake/controller.cpp brick_game/snake/fsm.cpp
SRCS2 = brick_game/tetris/s21_backend.c brick_game/tetris/s21_tetris.c brick_game/tetris/s21_util.c gui/cli/s21_frontend.c
# Define the object files
OBJS = $(SRCS:.cpp=.o)
OBJS2 = $(SRCS2:.c=.o)
# Define the compiler flags
CFLAGS = -std=c11 -g -Wall -Werror -Wextra
QT_PATH = /usr/local
CFLAGS2 = -std=c11 -g -Wall -Wno-unused-function -Wextra
# Define the link flags
LDFLAGS = -Iinclude -lncurses
LDFLAGS2 = -Iinclude -lncurses
CXX = g++
CC = gcc

# The default target is to build the snake game
ncurses_1: $(TARGET)
ncurses_2: $(TARGET2)
# Build the snake game
$(TARGET) : $(OBJS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TARGET2) : $(OBJS2)
		$(CC) $(CFLAGS2) $(LDFLAGS2) -o $@ $^
# Clean the build files
clean1:
		rm -f $(OBJS) $(TARGET)
clean2:
		rm -f $(OBJS2) $(TARGET2)