#ifndef SQUARE_H
#define SQUARE_H
#include <QGraphicsRectItem>

class Square1 :public QGraphicsRectItem{

public:
    //constructor
    Square1(QGraphicsItem * parent=NULL);

    //getters
    int getAttack();


    //setters
    void setAttack(int value);



    //attributes/member variables
private:
    QString owner;
    int Attack;
    int width;
    int height;


};





#endif // SQUARE_H
