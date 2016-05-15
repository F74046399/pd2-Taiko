#include "game.h"
#include "Drum.h"
#include <QTimer>
#include <QObject>




void Game::game()
{
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(2000);
}
