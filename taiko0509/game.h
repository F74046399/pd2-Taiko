#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QScrollBar>
#include <QObject>
#include "Drum.h"

class Game: public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
public slots:
   void game();

};

#endif // GAME_H
