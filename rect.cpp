#include <QGraphicsScene>
#include "Drum.h"
#include "rect.h"


void Rect::spawn()
{
    //creat a drum
    Drum * drum = new Drum();
    scene()->addItem(drum);

}
