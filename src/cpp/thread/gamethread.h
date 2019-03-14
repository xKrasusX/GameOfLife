#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>

/** \brief Class representing thread of a running game.
 */
class GameThread : public QThread
{
    Q_OBJECT

public:
    /** \brief Constructor returning new GameThread object.
     * \param QObject *parent Parent QObject.
     */
    explicit GameThread(QObject *parent = nullptr);

protected:
    /** \brief Inherited from QThread class.
     * \return void
     */
    void run();

signals:
    /** \brief Signal sent in a regular measures of time while thread running.
     * \return void
     */
    void update();
};

#endif // GAMETHREAD_H
