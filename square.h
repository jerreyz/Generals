#ifndef SQUARE_H
#define SQUARE_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>



class Square : public QGraphicsRectItem{

public:
    //constructor
    Square(QGraphicsItem * parent=NULL);

    //getters
    int getAttack();


    QString getOwner();
    bool getisKing();
    QList<Square *> getneighbors();


    //setters
    void setAttack(int value);
    void updateAttack(int value);
    void setOwner(QString Player);
    void setKing(bool b);
    void setXcoordinate(int x);
    void setYcoordinate(int y);


    // Mouse events
     void mousePressEvent(QGraphicsSceneMouseEvent *event); //this is a virtual void function in Qgraphicsscene
     void keyPressEvent(QKeyEvent * event);
    //member functions:
     void createLines();
     void findNeighbors();
     void Attacksquare (Square *defender);






    //attributes/member variables

private:
    bool isking;
    QString owner;
    int Attack;
    int width=50;
    int height=50;
    QGraphicsTextItem *text;
    QList<Square*> neighbors;
    QList<QGraphicsLineItem*> lines;
    int Xcoordinate;
    int Ycoordinate;
    bool isclicked;




};





#endif // SQUARE_H
