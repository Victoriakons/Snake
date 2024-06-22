# Define the target name
TARGET = snake_ncurses
TARGET2 = snake_qt
# Define the source files
SRCS = main1.cpp consoleView.cpp model.cpp controller.cpp
SRCS2 = main.cpp model.cpp QtView.cpp mainwindow.cpp helpfield.cpp
# Define the object files
OBJS = $(SRCS:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)
# Define the compiler flags
CFLAGS = -std=c11 -g -Wall -Werror -Wextra
QT_PATH = /usr/local
CFLAGS2 = -Iinclude -I$(QT_PATH)/include -L$(QT_PATH)/lib
# Define the link flags
LDFLAGS = -Iinclude -lncurses
LDFLAGS2 = -lQt5Widgets -lQt5Core
CXX = g++
# The default target is to build the snake game
ncurses: $(TARGET)
qt: $(TARGET2)
# Build the snake game
$(TARGET) : $(OBJS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TARGET2) : $(OBJS2)
		$(CXX) $(CFLAGS2) $(LDFLAGS2) -o $@ $^
# Clean the build files
clean1:
		rm -f $(OBJS) $(TARGET)
clean2:
		rm -f $(OBJS2) $(TARGET2)