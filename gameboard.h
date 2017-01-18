#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QList>
#include "square.h"
//cant include game because then I got circular dependency



class Gameboard:public QObject{
Q_OBJECT
private:
    //list of pointers to  rectangles:
    QList <Square *> squares;

public:
    //constructor
    Gameboard();
    //getter
     QList <Square*> getSquares();


     //member functions
     void placesquares(int x, int y, int rows,int cols);
     void createkings();

     //Helper functions
    void createSquareColumn(int x,int y,int numRows);
public slots:
    void Reinforce();




};

#endif // GAMEBOARD_H
