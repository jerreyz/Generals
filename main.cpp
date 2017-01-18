#include <QApplication>
#include "game.h"


Game * game;
//how can I avoid having to make the game global??
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game= new Game();

    game->show();
    game->displaymenu();



    return a.exec();
}
