
#include "consoleView.h"

int main() {
    Model model;
    SnakeController controller(&model, controller.get_score());
    ConsoleView view(&controller);

    view.StartView();
    while(!controller.isGameOver()) {
        view.board();
        view.NcursesInput();
        view.Input();
        controller.EatingAndCollision();
        controller.Update();
        refresh();
    }

    view.NcursesEnd();
    return 0;
}