#include "square.h"
#include <QPointF>
#include <QBrush>
#include <QVector>
#include <QDebug>
#include <QFont>
#include <QKeyEvent>


Square:: Square (QGraphicsItem *parent)
{


    //draw square
    this->setRect(0,0,width,height);
    // set attack to 1
    Attack=1;





   //create textitem to visualize attack
    // need a string for textitem so convert with number function
    //parent is the square such that when we destroy the square so does the textitem
    text=new QGraphicsTextItem(QString::number(Attack),this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //change color to white for better contrast
    text->setDefaultTextColor(Qt::white);
    //bigger font
    QFont titlefont("Helvetica",20);
    text->setFont(titlefont);
    // draw detecting lines











}

int Square::getAttack()
{
    return Attack;
}





QString Square::getOwner()
{
    // getter function that returns private attribute owner which is a Qstring
    return owner;
}

bool Square::getisKing()
{
    return isking;
}

QList<Square *> Square::getneighbors()
{
    return neighbors;
}

void Square::setAttack(int value)
{
    Attack=value;
    text->setPlainText(QString::number(Attack));


}

void Square::updateAttack(int value)
{
    Attack+=value;
    text->setPlainText(QString::number(Attack));
}

void Square::setOwner(QString Player)
{
    owner=Player;
    if (Player==QString("Neutral"))
    {
            QBrush brush;
            brush.setStyle(Qt::SolidPattern);
            brush.setColor(Qt::lightGray);
            setBrush(brush);
    }

            if (Player==QString("Player1"))
            {
                    QBrush brush;
                    brush.setStyle(Qt::SolidPattern);
                    brush.setColor(Qt::blue);
                    setBrush(brush);
            }
            if (Player==QString("Bot"))
            {
                    QBrush brush;
                    brush.setStyle(Qt::SolidPattern);
                    brush.setColor(Qt::red);
                    setBrush(brush);
            }

}

void Square::setKing(bool b)
{
    isking=b;
}

void Square::setXcoordinate(int x)
{
    Xcoordinate=x;
}

void Square::setYcoordinate(int y)
{
    Ycoordinate=y;
}


 void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    //get position of event

    if (this->getOwner()=="Player1")
    {
        this->setFlag(QGraphicsItem::ItemIsFocusable);
        qDebug()<<"I can move this square";
        this->setFocus();
        isclicked=true;

    }
    else {qDebug()<<"I can't move this square";}


 }

 void Square::keyPressEvent(QKeyEvent *event)
 {
     if (event->key() == Qt::Key_Left){
         qDebug()<<"I'm clicking left";
         QPointF Squarecenter(x()+25,y()+25);
         QPointF finalPt(Squarecenter.x()-30,Squarecenter.y());
         QLineF ln(Squarecenter,finalPt);
         QGraphicsLineItem* line = new QGraphicsLineItem(ln,this);
         line->setVisible(true);





        }
        else if (event->key() == Qt::Key_Right)
     {

         qDebug()<<"I'm clicking right";
         QPointF Squarecenter(x()+25,y()+25);
         qDebug()<<x();
         QPointF finalPt(Squarecenter.x()+30,Squarecenter.y());
         QLineF ln(Squarecenter,finalPt);


         QGraphicsLineItem* line = new QGraphicsLineItem(ln,this);
        // qDebug()<<line->collidingItems();


        QList<QGraphicsItem*> colitems = line->collidingItems();
        for (size_t j = 0; j < colitems.size(); j++)
        {
            Square* item = dynamic_cast<Square*>(colitems[j]);
            if (colitems[j]!= this && item)
            {
            qDebug()<<colitems[j];
            this->Attacksquare(item);
            }
            else
            {continue;}
        }
     }


        else if (event->key() == Qt::Key_Up)
        {
         QPointF Squarecenter(x()+25,y()+25);
         QPointF finalPt(Squarecenter.x(),Squarecenter.y()-30);
         QLineF ln(Squarecenter,finalPt);
         ln.setAngle(90);
         QGraphicsLineItem* line = new QGraphicsLineItem(ln,this);
         line->setVisible(true);

        }
        else if (event->key() == Qt::Key_Down)
        {

        }
     //this->clearFocus();
 }

 void Square::createLines(){
     QPointF Squarecenter(x()+25,y()+25);
     QPointF finalPt(Squarecenter.x(),Squarecenter.y()-30);
     QLineF ln(Squarecenter,finalPt);

     for (size_t i = 0, n = 4; i < n; ++i){
         QLineF lnCopy(ln);
         lnCopy.setAngle(90+90*i);
         QGraphicsLineItem* line = new QGraphicsLineItem(lnCopy,this);
         lines.append(line);


     }
 }

 void Square::findNeighbors(){
     for (size_t i = 0, n = lines.size(); i < n; i++){
         // if the line collides with an item of type Square, add it to neighbors
         QList<QGraphicsItem*> cItems = lines[i]->collidingItems();
         for (size_t j = 0; j < cItems.size(); j++){
             Square* item = dynamic_cast<Square*>(cItems[j]);
             if (cItems[j] != this && item){
                 neighbors.append(item);
             }
         }
     }
 }

 void Square::Attacksquare(Square * defender)
 {

     if(this->getAttack() > defender->getAttack())
     {
         if(defender->getisKing()==true)
         {qDebug()<<"Game over";}

         else
         {
         // store original attack from attacker
         int temp=defender->getAttack();
         //the defending square gets the remaining attackers
         defender->setAttack(abs(this->getAttack()-defender->getAttack()));
         //attacker loses it's strength
         this->setAttack(this->getAttack()-temp);
         //we set a new owner
         }


     }
     else
     {
         int temp=this->Attack;
         this->setAttack(this->getAttack()-defender->getAttack());
         defender->setAttack(temp-defender->getAttack());
     }
 }



