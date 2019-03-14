#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "../game/boardmanager.h"
#include "labelcell.h"
#include "../thread/gamethread.h"

/** \brief Class representing the main UI window.
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /** \brief Constructor returning new MainWindow object with predefined parameters.
     * \param QWidget *parent Parent QWidget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /** \brief Standard destructor deleting the MainWindow object.
     */
    ~MainWindow();

    /** \brief Reverts single field to alive and vice-versa.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \return void
     */
    void revertField(int h, int w);

private slots:
    /** \brief Changes neighborhood type to Von Neumann when appropriate button released.
     */
    void on_radioVonN_released();

    /** \brief Changes neighborhood type to Moore when appropriate button released.
     */
    void on_radioMoore_released();

    /** \brief Sets all the fields to dead when appropriate button released.
     */
    void on_buttonClear_released();

    /** \brief Reverts dead fields of the board to alive and vice-versa when appropriate button released.
     */
    void on_buttonRevert_released();

    /** \brief Sets random dead/alive value to every field of the board when appropriate button released.
     * \return void
     */
    void on_buttonRandomize_released();

    /** \brief Changes height of the board when value in appropriate box edited.
     * \return void
     */
    void on_spinBoxHeight_editingFinished();

    /** \brief Changes width of the board when value in appropriate box edited.
     * \return void
     */
    void on_spinBoxWidth_editingFinished();

    /** \brief Loads board from file when appropriate button released and proper file selected.
     * \return void
     */
    void on_buttonLoad_released();

    /** \brief Saves board to file when appropriate button released and proper file path selected.
     * \return void
     */
    void on_buttonSave_released();

    /** \brief Updates board once when appropriate button released.
     * \return void
     */
    void on_buttonPlusOne_released();

    /** \brief Updates board in a regular measures of time when appropriate button released
     * and until same button pressed again.
     * \return void
     */
    void on_buttonStartStop_released();

private:
    BoardManager *manager;
    Ui::MainWindow *ui;
    GameThread *gameThread;
    QVector<LabelCell*> cells;

    void setComponentsEnabled(bool enabled);
    void createView();
    void updateView();
    void setCellsEnabled(bool enabled);
    void deleteCells();

public slots:
    void onUpdate();
};

#endif // MAINWINDOW_H
