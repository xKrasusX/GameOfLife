#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    BoardManager *manager;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
