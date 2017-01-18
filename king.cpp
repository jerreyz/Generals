#include "king.h"
#include <QBrush>





King::King(qreal posX,qreal posY)
{
    setPixmap(QPixmap("/Users/jeroenderyck/Desktop/king1.png"));



    QImage image("/Users/jeroenderyck/Desktop/king1.png");

    setX(posX);
    setY(posY);
}
