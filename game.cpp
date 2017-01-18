#include "game.h"
#include "gameboard.h"
#include <QGraphicsTextItem>
#include "button.h"



Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
    //initalisation


}

void Game::displaymenu()
{
    //1. Create Title text
    QGraphicsTextItem*titletext=new QGraphicsTextItem(QString("CaptureTheKing"));
    QFont titlefont("Helvetica",50);
    titletext->setFont(titlefont);

    //title text position needs to be in center:
    int txPos = this->width()/2 - titletext->boundingRect().width()/2;
    int tyPos = 150;
    titletext->setPos(txPos,tyPos);
    scene->addItem(titletext);

    //2.Create button to play
    Button * playbutton=new Button(QString("Click here to start a new game"));
    int bxPos = this->width()/2 - playbutton->boundingRect().width()/2;
    int byPos = 275;
    playbutton->setPos(bxPos,byPos);
    // when the playbutton is clicked we invoke the start member function of our game class
    connect(playbutton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playbutton);

    //3. button to quit
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));//window's close function linked with clicked signal
    scene->addItem(quitButton);


}



void Game::start()
{
    //When we start the game we wanna clear welcome screen first
    scene->clear();
    //next we make a new gameboard
    // use gameboard pointer we declared in header
    gameboard =new Gameboard();

    //use it's member function to get the desired size
    gameboard->placesquares(240,100,10,10);

    gameboard->createkings();



    //we will also draw a gui which should display game events
    drawgui();

}

void Game::drawpanel(int x, int y, int width, int height, QColor color, double opacity)
{    //drawpanel at specified location

    QGraphicsRectItem *panel=new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);//value between 0 and 1
    scene->addItem(panel);


}

void Game::drawgui()
{
    //1.draw panel with information
    drawpanel(0,500,200,200,Qt::gray,0.50);

    //2. draw text above panel
    QGraphicsTextItem *text1=new QGraphicsTextItem("Game log");
    text1->setPos(0,500);
    scene-> addItem(text1);
}
