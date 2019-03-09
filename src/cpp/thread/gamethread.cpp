#include "gamethread.hpp"

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
