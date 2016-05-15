#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem
{
public:
    void KeyPressEvent(QKeyEvent * event);
};



#endif // MYRECT_H
