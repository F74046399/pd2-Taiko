#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QWidget>
#include <QImage>
#include <QBrush>
#include <QtCore>
#include <QTimer>
#include <QList>
#include <QCoreApplication>
#include <stdlib.h>
#include <QApplication>
#include <QScrollBar>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QBitmap>
#include <QMediaPlayer>
#include <QSound>
#include <QMultimedia>



QTimer * timer;
QTimer * timer_m;
QMediaPlayer* bg1Sound;
QMediaPlayer * bg3Sound;
QMediaPlayer *gameSound;
QMediaPlayer * drum1;
QMediaPlayer *drum2;


int count=30;
int score=0;
int score_final=0;
int location[6]={0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set window size
    setFixedSize(1280,720);

    /*declear pictures*/

    //add exit button
    ui->ExitButton->setGeometry(QRect(QPoint(1280/2+320,50),QSize(300,130)));
    QPixmap pics2(":button/img/Rework/Finish.png");
    QIcon Exitpics(pics2);
    ui->ExitButton->setIcon(Exitpics);
    ui->ExitButton->setIconSize(pics2.rect().size());


    //add start button
    ui->StartButton->setGeometry(QRect(QPoint(1280/2,50),QSize(310,130)));
    QPixmap pics3(":button/img/Rework/Start.png");
    QIcon Startpics(pics3);
    ui->StartButton->setIcon(Startpics);
    ui->StartButton->setIconSize(pics3.rect().size());

    //add stop button
    ui->StopButton->setGeometry(QRect(QPoint(1000,75),QSize(60,60)));
    QPixmap pics14(":button/img/Rework/stop.png");
    QIcon Stoppics(pics14);
    ui->StopButton->setIcon(Stoppics);
    ui->StopButton->setIconSize(pics14.rect().size());
    ui->StopButton->hide();

    //add contiune button
    ui->GoButton->setGeometry(QRect(QPoint(900,75),QSize(60,60)));
    QPixmap pics15(":button/img/Rework/gogo.png");
    QIcon Gopics(pics15);
    ui->GoButton->setIcon(Gopics);
    ui->GoButton->setIconSize(pics15.rect().size());
    ui->GoButton->hide();

    //add return button
    ui->ReturnButton->setGeometry(QRect(QPoint(1110,75),QSize(60,60)));
    QPixmap pics16(":button/img/Rework/return.png");
    QIcon Returnpics(pics16);
    ui->ReturnButton->setIcon(Returnpics);
    ui->ReturnButton->setIconSize(pics16.rect().size());
    ui->ReturnButton->hide();

    //add r button
    ui->RButton->setGeometry(QRect(QPoint(200,360),QSize(500,100)));
    QPixmap pics17(":button/img/Rework/restart.png");
    QIcon Rpics(pics17);
    ui->RButton->setIcon(Rpics);
    ui->RButton->setIconSize(pics17.rect().size());
    ui->RButton->hide();

    //add c button
    ui->CButton->setGeometry(QRect(QPoint(600,360),QSize(500,100)));
    QPixmap pics18(":button/img/Rework/continue.png");
    QIcon Cpics(pics18);
    ui->CButton->setIcon(Cpics);
    ui->CButton->setIconSize(pics18.rect().size());
    ui->CButton->hide();

    //add restartbutton
    ui->RestartButton->setGeometry(QRect(QPoint(1280/2-70,450),QSize(310,130)));
    QPixmap pics12(":button/img/Rework/Again.png");
    QIcon ReStartpics(pics12);
    ui->RestartButton->setIcon(ReStartpics);
    ui->RestartButton->setIconSize(pics12.rect().size());
    ui->RestartButton->hide();

    //add final exit
    ui->ExitButton2->setGeometry(QRect(QPoint(1280/2+220,450),QSize(300,130)));
    QPixmap pics13(":button/img/Rework/Finish.png");
    QIcon Exitpics2(pics13);
    ui->ExitButton2->setIcon(Exitpics2);
    ui->ExitButton2->setIconSize(pics13.rect().size());
    ui->ExitButton2->hide();

    //add Ready button
    ui->ReadyButton->setGeometry(QRect(QPoint(1280/2-230,720/2),QSize(500,300)));
    QPixmap pics23(":/button/img/Rework/readyyy.png");
    QIcon Readypics(pics23);
    ui->ReadyButton->setIcon(Readypics);
    ui->ReadyButton->setIconSize(pics23.rect().size());
    ui->ReadyButton->hide();


    //add pics of checkbg
  /*  QPixmap pics19(":CheckBackground/img/Rework/background.jpg");
    ui->checkbg->setPixmap(pics19);
    ui->checkbg->setGeometry(QRect(640,360,320,180));
    ui->checkbg->setFixedSize(640,360);
    ui->checkbg->setScaledContents(true);
    ui->checkbg->hide();*/

    //add pics of startscreen
    QPixmap pics1(":StartScreen/img/startcover.jpg");
    ui->StartScreen->setPixmap(pics1);
    ui->StartScreen->setGeometry(QRect(0,0,1280,720));


    //add pics of introbg
  /*  QPixmap pics26(":/intro/img/Rework/ReadyScreen.jpeg");
    ui->introbg->setPixmap(pics26);
    ui->introbg->setGeometry(QRect(900,720-50,1000,550));
    ui->introbg->hide();*/


    //add pics of gamescreen
    QPixmap pics4(":/GameScreen/img/GameScreen.png");
    ui->GameScreen->setPixmap(pics4);
    ui->GameScreen->setGeometry(QRect(0,0,1280,720));
    ui->GameScreen->setScaledContents(true);
    ui->GameScreen->hide();

    //add RestartScreen
    QPixmap pics11(":/RestartScreen/img/restartscreen.jpg");
    ui->RestartScreen->setPixmap(pics11);
    ui->RestartScreen->setGeometry(QRect(0,0,1280,720));
    ui->RestartScreen->setScaledContents(true);
    ui->RestartScreen->hide();

    //add drum pic
    QPixmap pics5(":/drum/img/Rework/face1.png");
    ui->drum1->setPixmap(pics5);
    ui->drum1->setGeometry(QRect(1200/2+200,720/2-220,150,150));
    ui->drum1->setFocus();
    ui->drum1->hide();

    QPixmap pics6(":/drum/img/Rework/face2.png");
    ui->drum2->setPixmap(pics6);
    ui->drum2->setGeometry(QRect(1200/2+200,720/2-220,150,150));
    ui->drum2->setFocus();
    ui->drum2->hide();

    QPixmap pics7(":/drum/img/Rework/face2L.png");
    ui->drum2L->setPixmap(pics7);
    ui->drum2L->setGeometry(QRect(1200/2+200,720/2-225,150,150));
    ui->drum2L->setFocus();
    ui->drum2L->hide();

    QPixmap pics8(":/drum/img/Rework/face1L.png");
    ui->drum1L->setPixmap(pics8);
    ui->drum1L->setGeometry(QRect(1200/2+200,720/2-225,150,150));
    ui->drum1L->setFocus();
    ui->drum1L->hide();

    QPixmap pics9(":/drum/img/Rework/face1.png");
    ui->drum3L->setPixmap(pics9);
    ui->drum3L->setGeometry(QRect(1200/2+200,720/2-220,150,150));
    ui->drum3L->setFocus();
    ui->drum3L->hide();

    QPixmap pics10(":/drum/img/Rework/face2.png");
    ui->drum3->setPixmap(pics10);
    ui->drum3->setGeometry(QRect(1200/2+200,720/2-220,150,150));
    ui->drum3->setFocus();
    ui->drum3->hide();

    //add bad pic
    QPixmap pics20(":/commen/img/Rework/baddddd.png");
    ui->bad->setPixmap(pics20);
    ui->bad->setGeometry(QRect(200,107,130,85));
    ui->bad->setFocus();
    ui->bad->hide();

    //add good pic
    QPixmap pics21(":/commen/img/Rework/Gooddddd.png");
    ui->good->setPixmap(pics21);
    ui->good->setGeometry(QRect(250,107,130,85));
    ui->good->setFocus();
    ui->good->hide();

    //add intro pic
    QPixmap pics24(":/intro/img/Rework/FFFFF.png");
    ui->intro1->setPixmap(pics24);
    ui->intro1->setGeometry(QRect(500,720/2-220,250,250));
    ui->intro1->setFocus();
    ui->intro1->hide();

    QPixmap pics25(":/intro/img/Rework/HHHHH.png");
    ui->intro2->setPixmap(pics25);
    ui->intro2->setGeometry(QRect(700,720/2-220,250,250));
    ui->intro2->setFocus();
    ui->intro2->hide();


    //declear timer
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));

    timer_m = new QTimer();
    connect(timer_m,SIGNAL(timeout()),this,SLOT(move()));




 /*   //add people
    QPixmap pics22(":/commen/img/people.png");
    ui->people1->setPixmap(pics22);
    ui->people1->setGeometry(QRect(1280/2+200,720/2+300,512,203));
    ui->people1->setFocus();
    ui->people1->hide();*/


    //set bg1 music
    bg1Sound =new QMediaPlayer();
    bg1Sound->setMedia(QUrl("qrc:/sound/voice/bg1.mp3"));
    bg1Sound->play();

    //set bg3 music
    bg3Sound =new QMediaPlayer();
    bg3Sound->setMedia(QUrl("qrc:/sound/voice/bg3.mp3"));

    //set game music
    gameSound =new QMediaPlayer();
    gameSound->setMedia(QUrl("qrc:/sound/voice/game.mp3"));


    //set hit music
    drum1 =new QMediaPlayer();
    drum1->setMedia(QUrl("qrc:/sound/voice/drum1.mp3"));

    drum2 =new QMediaPlayer();
    drum2->setMedia(QUrl("qrc:/sound/voice/drum2.mp3"));




}
MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_ExitButton_clicked()
{
         this->close();
}

void MainWindow::on_StartButton_clicked()
{

    ui->StartScreen->hide();
    ui->StartButton->hide();
    ui->ExitButton->hide();
    ui->GameScreen->show();
    ui->StopButton->show();
    ui->GoButton->show();
    ui->ReturnButton->show();
    ui->clock->show();
    ui->drum1->show();
    ui->drum2->show();
    ui->drum1L->show();
    ui->drum2L->show();
    ui->drum3->show();
    ui->drum3L->show();




    bg1Sound->stop();

    /*check the record*/
    if(count!=30)
    {
        ui->CButton->show();
        ui->RButton->show();

        ui->GameScreen->show();
        ui->clock->hide();
        ui->drum1->hide();
        ui->drum2->hide();
        ui->drum1L->hide();
        ui->drum2L->hide();
        ui->drum3->hide();
        ui->drum3L->hide();
        //ui->checkbg->show();

    }
    else
    {
         ui->ReadyButton->show();
         ui->intro1->show();
         ui->intro2->show();
         //ui->introbg->show();
         ui->drum1->hide();
         ui->drum2->hide();
         ui->drum1L->hide();
         ui->drum2L->hide();
         ui->drum3->hide();
         ui->drum3L->hide();


    }

}

void MainWindow::move()
{
    //move drum left

    location[0]=location[0]-10;
    location[1]=location[1]-10;
    location[2]=location[2]-10;
    location[3]=location[3]-10;
    location[4]=location[4]-10;
    location[5]=location[5]-10;

    ui->drum1->setGeometry(location[0],720/2-220,150,150);
    ui->drum2->setGeometry(location[1],720/2-220,150,150);
    ui->drum1L->setGeometry(location[2],720/2-225,150,150);
    ui->drum2L->setGeometry(location[3],720/2-225,150,150);
    ui->drum3L->setGeometry(location[4],720/2-220,150,150);
    ui->drum3->setGeometry(location[5],720/2-220,150,150);


    //miss
    if(ui->drum1->pos().x()<190)
    {
      ui->drum1->hide();
      ui->good->hide();
      ui->bad->show();
      random_number = rand()%200+1280;
      location[0]= random_number;
      ui->drum1->setGeometry(location[0],720/2-220,150,150);
      ui->drum1->show();
    }

     if(ui->drum2->pos().x()<190)
     {
         ui->drum2->hide();
         ui->good->hide();
         ui->bad->show();
         random_number = rand()%400+1280;
         location[1]= random_number;
         ui->drum2->setGeometry(location[1],720/2-220,150,150);
         ui->drum2->show();
     }
      if(ui->drum1L->pos().x()<190)
      {
          ui->drum1L->hide();
          ui->good->hide();
          ui->bad->show();
          random_number = rand()%900+1280;
          location[2]= random_number;
          ui->drum1L->setGeometry(location[2],720/2-225,150,150);
          ui->drum1L->show();
      }
      if(ui->drum2L->pos().x()<190)
      {
       ui->drum2L->hide();
       ui->good->hide();
       ui->bad->show();
       random_number = rand()%100+1280;
       location[3]= random_number;
       ui->drum2L->setGeometry(location[3],720/2-225,150,150);
       ui->drum2L->show();
      }
     if(ui->drum3L->pos().x()<190)
     {
         ui->drum3L->hide();
         ui->good->hide();
         ui->bad->show();
         random_number = rand()%200+1280;
         location[4]= random_number;
         ui->drum3L->setGeometry(location[4],720/2-220,150,150);
         ui->drum3L->show();
    }
     if(ui->drum3->pos().x()<190)
     {
         ui->drum3->hide();
         ui->good->hide();
         ui->bad->show();
         random_number = rand()%500+1280;
         location[5]= random_number;
         ui->drum3->setGeometry( location[5],720/2-220,150,150);
         ui->drum3->show();
    }


}

void MainWindow::timer_timeout()
{

    if(count==-1)//time out
    {
        count=30;
        timer->stop();
        timer_m->stop();
        ui->bad->hide();
        ui->good->hide();
        ui->GameScreen->hide();
        ui->drum1->hide();
        ui->drum2->hide();
        ui->drum1L->hide();
        ui->drum2L->hide();
        ui->drum3->hide();
        ui->drum3L->hide();
        ui->StopButton->hide();
        ui->GoButton->hide();
        ui->ReturnButton->hide();
        ui->RestartScreen->show();
        ui->RestartButton->show();
        ui->ExitButton2->show();
        ui->score_word->setText("Score:");
        ui->final_score->setText(QString::number(score));
        score_final=score;
        ui->score_word->setGeometry(320,180,200,200);
        ui->final_score->setGeometry(500,180,200,200);
        ui->score_word->show();
        ui->final_score->show();
       // ui->people1->hide();
        gameSound->stop();
        bg3Sound->play();

    }
    ui->clock->setText(QString::number(count));
    count--;

}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
   switch(event->key()){
   case Qt::Key_F:
        if(ui->drum1->pos().x()<=350 && ui->drum1->pos().x()>=220)
        {
             ui->bad->hide();
             ui->good->show();
             drum1->play();
            ui->drum1->hide();
            random_number = rand()%200+1280;
            location[0]= random_number;
            ui->drum1->setGeometry(location[0],720/2-220,150,150);
            ui->drum1->show();
            IncreaseScore();
        }
        else if(ui->drum1L->pos().x()<350 && ui->drum1L->pos().x()>=220)
        {
            ui->bad->hide();
            ui->good->show();
            drum1->play();
            ui->drum1L->hide();
            random_number = rand()%900+1280;
            location[2]= random_number;
            ui->drum1L->setGeometry(location[2],720/2-225,150,150);
            ui->drum1L->show();
             IncreaseScore();
        }
        else if(ui->drum3L->pos().x()<350 && ui->drum3L->pos().x()>=220)
        {
            ui->bad->hide();
            ui->good->show();
            drum1->play();
            ui->drum3L->hide();
            random_number = rand()%200+1280;
            location[4]= random_number;
            ui->drum3L->setGeometry(location[4],720/2-220,150,150);
            ui->drum3L->show();
              IncreaseScore();
        }
        else
        {
            ui->bad->show();
              ui->good->hide();

        }
        break;
   case Qt::Key_H:
        if((ui->drum2->pos().x())<350 && ui->drum2->pos().x()>=220)
        {
            ui->bad->hide();
            ui->good->show();
            drum2->play();
            ui->drum2->hide();
            random_number = rand()%400+1280;
            location[1]= random_number;
            ui->drum2->setGeometry(location[1],720/2-220,150,150);
            ui->drum2->show();
              IncreaseScore();
        }
        else if((ui->drum2L->pos().x())<350 && ui->drum2L->pos().x()>=220)
        {
           ui->bad->hide();
           ui->good->show();
           drum2->play();
            ui->drum2L->hide();
            random_number = rand()%100+1280;
            location[3]= random_number;
            ui->drum2L->setGeometry(location[3],720/2-225,150,150);
            ui->drum2L->show();
              IncreaseScore();
        }
        else if((ui->drum3->pos().x())<350 && ui->drum3->pos().x()>=220)
        {
            ui->bad->hide();
            ui->good->show();
            drum2->play();
            ui->drum3->hide();
            random_number = rand()%500+1280;
            location[5]= random_number;
            ui->drum3->setGeometry( location[5],720/2-220,150,150);
            ui->drum3->show();
              IncreaseScore();
        }
        else
        {
            ui->bad->show();
              ui->good->hide();

        }
            break;

}

}
void MainWindow::Score()
{

    //drew the text
    ui->score->setText(QString::number(score));
    ui->score->setGeometry(30,150,150,150);
}

void MainWindow::IncreaseScore()
{
    ++score;
    ui->score->setText(QString::number(score));
    score_final=score;
   /* if(score>10)
        ui->people1->show();*/
}

void MainWindow::Game()
{
    ui->RestartScreen->hide();
    ui->RestartButton->hide();
    ui->ExitButton2->hide();
    ui->score_word->hide();
    ui->final_score->hide();
    ui->GameScreen->show();
    ui->StopButton->show();
    ui->GoButton->show();
    ui->ReturnButton->show();
    ui->clock->show();
    ui->score->show();
    ui->drum1->show();
    ui->drum2->show();
    ui->drum1L->show();
    ui->drum2L->show();
    ui->drum3->show();
    ui->drum3L->show();
    /* start the game*/

    //clock
    ui->clock->setGeometry(700,35,150,150);
    timer->start(1000);



    //set score
    Score();

    //set randon position
    int srand();
    random_number = rand()%200+1280;
    location[0]=random_number;

    random_number = rand()%600+1280;
    location[1]=random_number;

    random_number =rand()%1500+1280;
    location[2]=random_number ;

    random_number = rand()%100+1280;
    location[3]=random_number;

    random_number = rand()%800+1280;
    location[4]=random_number;

    random_number = rand()%300+1280;
    location[5]=random_number;

    ui->drum1->setGeometry(location[0],720/2-220,150,150);
    ui->drum2->setGeometry(location[1],720/2-220,150,150);
    ui->drum1L->setGeometry(location[2],720/2-225,130,85);
    ui->drum2L->setGeometry(location[3],720/2-225,130,85);
    ui->drum3L->setGeometry(location[4],720/2-220,150,150);
    ui->drum3->setGeometry(location[5],720/2-220,150,150);


    //set time(each drum)
    timer_m->start(30);



}





void MainWindow::on_RestartButton_clicked()
{
    score=0;
    Game();
    bg3Sound->stop();
    gameSound->play();
}

void MainWindow::on_ExitButton2_clicked()
{
    this->close();
}

void MainWindow::on_StopButton_clicked()
{
    timer->stop();
    timer_m->stop();
    gameSound->stop();
}

void MainWindow::on_GoButton_clicked()
{
    timer->start(1000);
    timer_m->start(30);
    gameSound->play();

}

void MainWindow::on_ReturnButton_clicked()
{
    timer->stop();
    timer_m->stop();
    bg1Sound->play();
    gameSound->stop();
    ui->StartScreen->show();
    ui->StartButton->show();
    ui->ExitButton->show();
    ui->GameScreen->hide();
    ui->StopButton->hide();
    ui->GoButton->hide();
    ui->ReturnButton->hide();
    ui->clock->hide();
    ui->drum1->hide();
    ui->drum2->hide();
    ui->drum1L->hide();
    ui->drum2L->hide();
    ui->drum3->hide();
    ui->drum3L->hide();
    ui->score->hide();
    ui->test->hide();
    ui->bad->hide();
    ui->good->hide();
    ui->CButton->hide();
    ui->RButton->hide();
}

void MainWindow::on_RButton_clicked()//restart
{
    count=30;
    ui->CButton->hide();
    ui->RButton->hide();
  //  ui->checkbg->hide();
    /*start the game*/
    score=0;
    gameSound->play();
    ui->clock->setText(QString::number(count));
    Game();

}

void MainWindow::on_CButton_clicked()//contiune the last time
{

    ui->CButton->hide();
    ui->RButton->hide();
   // ui->checkbg->hide();
    /*start the game*/
    score=score_final;
    gameSound->play();
    Game();
}



void MainWindow::on_ReadyButton_clicked()
{
    ui->ReadyButton->hide();
    ui->intro1->hide();
    ui->intro2->hide();
   // ui->introbg->hide();
    gameSound->play();
    /*start the game*/
     score=0;
     Game();
}
