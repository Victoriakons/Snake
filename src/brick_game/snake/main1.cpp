
#include "../../gui/desktop/consoleView.h"
#include "fsm.h"

int main() {
    Model model;
    SnakeController controller(&model, controller.get_score());
    ConsoleView view(&controller);

    FSM fsm(&controller);

    view.StartView();
    while(!controller.isGameOver()) {
        view.board();
        view.NcursesInput();
        view.Input();
        controller.EatingAndCollision();
        controller.Update();
        refresh();
    }

        fsm.update();


    view.NcursesEnd();
    return 0;
}