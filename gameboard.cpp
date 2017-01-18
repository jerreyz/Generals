#include "gameboard.h"
#include "game.h"
#include <QList>
#include <square.h>
#include <QDebug>
#include "king.h"
#include <QTimer>

// I want the gameboard to have access to the game -->bad?

extern Game* game;




Gameboard::Gameboard()
{
    QTimer *reinforcements_timer= new QTimer(this);
    connect(reinforcements_timer,SIGNAL(timeout()),this,SLOT(Reinforce()));
    reinforcements_timer->start(10000);
}

QList <Square *> Gameboard::getSquares()
{
    return squares;
}

void Gameboard::placesquares(int x, int y, int rows, int cols)
{
    // to place the squares we create n columns in an iteration
    int X_scale=50;
    for(size_t i=0,n=cols;i<n;i++)
    {
        //length column = number of rows
        createSquareColumn(x+X_scale*i,y,rows);
    }

}


void Gameboard::createkings()

{   //count how many squares we have
    int squareslength= squares.size();

    //take a random pointer in the list of squares

    int posKingPlayer1= qrand() % squareslength;

    //same for the bot try to get a bit farther
    int posKingBot= qrand() % squareslength;

    while(qAbs(posKingPlayer1-posKingBot)<80)
    {
        posKingBot= qrand() % squareslength;
        qDebug()<< posKingPlayer1;
        qDebug()<<qAbs(posKingPlayer1-posKingBot);


    }

    //set owners of that square to player s
    squares[posKingPlayer1]->setOwner("Player1");
    squares[posKingBot]->setOwner("Bot");

    // set the attribute isking to true to indicate these are kings

     squares[posKingPlayer1]->setKing(true);
     squares[posKingBot]->setKing(true);

     // Kings start with attack of 5 so we need to adjust attack
     squares[posKingPlayer1]->setAttack(5);
     squares[posKingBot]->setAttack(5);


     King *kingplayer1 = new King(squares[posKingPlayer1]->x(),squares[posKingPlayer1]->y());
     King *kingbot =new King(squares[posKingBot]->x(),squares[posKingBot]->y());

     squares[posKingBot]->findNeighbors();
     qDebug()<<squares[posKingBot]->getneighbors();

     game->scene->addItem(kingplayer1);
     game->scene->addItem(kingbot);
}





void Gameboard::createSquareColumn(int x, int y, int numRows)
{
    //create a column of squares at specified place and length numsquares
    for(size_t i=0, n=numRows;i<n;i++)
    {
        Square *square =new Square();
        square->setX(x);
        square->setY(y+50*i);
        //list of squares
        squares.append(square);
        //add squares to the scene
        game->scene->addItem(square);

        //initialize everyone no owner
        square->setOwner(QString("Neutral"));
    }
}

void Gameboard::Reinforce()
{
    for (size_t i=0,n=squares.size();i<n;i++)
    {
        if (squares[i]->getOwner()!=QString("Neutral"))
        {
            if (squares[i]->getisKing()==true)
            {
                squares[i]->updateAttack(5);
            }

            else
            {
               squares[i]->updateAttack(1);
            }
        }
       else{continue;}

    }
}
