#include <iostream>
#include <game.h>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game game;
    game.show();
    return app.exec();


    return 0;
}
