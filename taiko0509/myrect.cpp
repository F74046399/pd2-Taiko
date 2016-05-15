#include "myrect.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void MyRect::KeyPressEvent(QKeyEvent *event)
{
   switch(event->key()){
   case Qt::Key_Left:

        if(ui->drum1->pos().x()<=350 && ui->drum1->pos().x()>=220)
        {
            ui->drum1->hide();
            IncreaseScore();
        }
        if(ui->drum1L->pos().x()<350 && ui->drum1L->pos().x()>=220)
        {
            ui->drum1L->hide();
             IncreaseScore();
        }
        if(ui->drum3L->pos().x()<350 && ui->drum3L->pos().x()>=220)
        {
            ui->drum3L->hide();
              IncreaseScore();
        }
        break;
   case Qt::Key_Right:
        if((ui->drum2->pos().x())<350 && ui->drum2->pos().x()>=220)
        {
            ui->drum2->hide();
              IncreaseScore();
        }
        if((ui->drum2L->pos().x())<350 && ui->drum2L->pos().x()>=220)
        {
            ui->drum2L->hide();
              IncreaseScore();
        }
        if((ui->drum3->pos().x())<350 && ui->drum3->pos().x()>=220)
        {
            ui->drum3->hide();
              IncreaseScore();
        }
            break;
  /*  }else if(event->key()==Qt::Key_Space){

    }*/
    }
}
