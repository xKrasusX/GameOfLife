#ifndef GAMETHREAD_HPP
#define GAMETHREAD_HPP

#include <QThread>

class GameThread : public QThread
{
    Q_OBJECT

public:
    explicit GameThread(QObject *parent = nullptr);

protected:
    void run();

signals:
    void update();
};

#endif // GAMETHREAD_HPP
