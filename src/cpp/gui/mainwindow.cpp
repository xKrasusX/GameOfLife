#include <QFileDialog>
#include <string>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "../static/neighborhoodtype.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new BoardManager();
    isRunning = false;
    ui->labelError->setStyleSheet("QLabel {color: red;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioVonN_released()
{
    ui->labelError->clear();
    manager->setNeighborhoodType(NeighborhoodType::VON_NEUMANN);
}

void MainWindow::on_radioMoore_released()
{
    ui->labelError->clear();
    manager->setNeighborhoodType(NeighborhoodType::MOORE);
}

void MainWindow::on_buttonClear_released()
{
    ui->labelError->clear();
    manager->clearBoard();
    manager->getBoard()->print();
}

void MainWindow::on_buttonRevert_released()
{
    ui->labelError->clear();
    manager->revertBoard();
    manager->getBoard()->print();
}

void MainWindow::on_buttonRandomize_released()
{
    ui->labelError->clear();
    manager->randomizeBoard();
    manager->getBoard()->print();
}

void MainWindow::on_spinBoxHeight_editingFinished()
{
    ui->labelError->clear();
    manager->changeBoardHeight(ui->spinBoxHeight->value());
    manager->getBoard()->print();
}

void MainWindow::on_spinBoxWidth_editingFinished()
{
    ui->labelError->clear();
    manager->changeBoardWidth(ui->spinBoxWidth->value());
    manager->getBoard()->print();
}

void MainWindow::on_buttonLoad_released()
{
    std::string path = QFileDialog::getOpenFileName(this, "Load from file", "C:/", "*.txt").toStdString();
    if(!path.empty()) {
        bool readSuccess = manager->readBoardFromFile(path);
        if(readSuccess) {
            ui->labelError->clear();
            ui->spinBoxHeight->setValue(manager->getBoard()->getHeight());
            ui->spinBoxWidth->setValue(manager->getBoard()->getWidth());
            manager->getBoard()->print();
        } else {
            ui->labelError->setText("Invalid input file");
        }
    }
}

void MainWindow::on_buttonSave_released()
{
    ui->labelError->clear();
    std::string path = QFileDialog::getSaveFileName(this, "Save to file", "C:/", "*.txt").toStdString();
    if(!path.empty()) {
        manager->saveBoardToFile(path);
    }
}

void MainWindow::on_buttonPlusOne_released()
{
    ui->labelError->clear();
    manager->updateBoard();
    manager->getBoard()->print();
}

void MainWindow::on_buttonStartStop_released()
{
    ui->labelError->clear();
    if(!isRunning) {
        ui->buttonStartStop->setText("Stop");
        setComponentsEnabled(false);
        isRunning = true;
        repaint();
        gameThread = new MainWindow::GameThread(this);
        gameThread->start();
    } else {
        isRunning = false;
        gameThread->terminate();
        gameThread->~GameThread();
        ui->buttonStartStop->setText("Start");
        setComponentsEnabled(true);
        repaint();
    }
}

MainWindow::GameThread::GameThread(MainWindow *w) {
    this->w = w;
}

void MainWindow::GameThread::run() {
    while(w->isRunning) {
        w->manager->updateBoard();
        w->manager->getBoard()->print();
        msleep(500);
    }
}

void MainWindow::setComponentsEnabled(bool enabled) {
    ui->radioVonN->setEnabled(enabled);
    ui->radioMoore->setEnabled(enabled);
    ui->buttonLoad->setEnabled(enabled);
    ui->buttonSave->setEnabled(enabled);
    ui->buttonClear->setEnabled(enabled);
    ui->buttonRevert->setEnabled(enabled);
    ui->buttonPlusOne->setEnabled(enabled);
    ui->buttonRandomize->setEnabled(enabled);
    ui->spinBoxHeight->setEnabled(enabled);
    ui->spinBoxWidth->setEnabled(enabled);
}
