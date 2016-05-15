#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsRectItem>
#include <QObject>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>


namespace Ui {
class Drum;
}


class Drum: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    //Drum();
        explicit Drum(QWidget *parent = 0);
public slots:
    void move();
};

#endif // DRUM_H
