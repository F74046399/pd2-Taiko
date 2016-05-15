#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>
#include <QObject>

class Rect: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

public slots:
   void spawn();

};


#endif // RECT_H
