#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
#include <square.h>
#include <gameboard.h>

//put virtual member functions for kings and towers


class Game: public QGraphicsView
{Q_OBJECT
public:
    // Public Attributes: public because so many classes use it
     QGraphicsScene *scene;


     Gameboard * gameboard;



    // constructors

    Game(QWidget *parent=NULL);
    //member functions:
    void displaymenu();

    //mouse events



//link click event with start by using a slot
public slots:
    void start();
private :
    //gui purposes
    void drawpanel(int x,int y,int width,int height ,QColor color,double opacity);   //input=coordinates location panel
    void drawgui();  // draws panels and texts


};


#endif // GAME_H
