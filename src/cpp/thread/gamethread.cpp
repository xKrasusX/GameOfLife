#include "gamethread.h"

GameThread::GameThread(QObject *parent) :
    QThread (parent)
{

}

void GameThread::run() {
    while(true) {
        emit update();
        msleep(500);
    }
}
