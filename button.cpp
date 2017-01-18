#include "button.h"
#include <QBrush>
#include<QGraphicsTextItem>


//parent manages children
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();     //emits that we have a clicked event
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color to gray when hovered
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

}
