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
#include <QCoreApplication>
#include <stdlib.h>
#include <QApplication>
#include <QScrollBar>
#include <QWidget>
#include "drum.h"


    /*
    //drew a rect
    setRect(800,200,30,30);*/

    //add drum pic
    QPixmap pics5(":/drum/img/drumr.png");
    ui->drum1->setPixmap(pics5);
    ui->drum1->setGeometry(QRect(1200/2+200,720/2-180,130,85));
    ui->drum1->hide();

    QPixmap pics6(":/drum/img/drumb.png");
    ui->drum2->setPixmap(pics6);
    ui->drum2->setGeometry(QRect(1200/2+200,720/2-180,130,85));
    ui->drum2->hide();

    //connect action to signal
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


void Drum::move()
{
    //move drum left
    setPos(x()-10,y());

    if(pos().x()<150)
    {
        scene() -> removeItem(this);
        delete this;
    }
}
