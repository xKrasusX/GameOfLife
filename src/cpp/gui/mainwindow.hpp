#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "../game/boardmanager.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioVonN_released();
    void on_radioMoore_released();
    void on_buttonClear_released();
    void on_buttonRevert_released();
    void on_buttonRandomize_released();
    void on_spinBoxHeight_editingFinished();
    void on_spinBoxWidth_editingFinished();
    void on_buttonLoad_released();
    void on_buttonSave_released();
    void on_buttonPlusOne_released();
    void on_buttonStartStop_released();

private:
    class GameThread : public QThread {
    public:
        GameThread(MainWindow *w);
    protected:
        void run();
    private:
        MainWindow *w;
    };

    BoardManager *manager;
    Ui::MainWindow *ui;
    bool isRunning;
    GameThread *gameThread;

    void setComponentsEnabled(bool enabled);
};

#endif // MAINWINDOW_H
