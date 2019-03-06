#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "../static/neighborhoodtype.hpp"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new BoardManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioVonN_released()
{
    manager->setNeighborhoodType(NeighborhoodType::VON_NEUMANN);
    manager->readBoardFromFile("P:/1Marcin/Tymczasowe/tmp.txt");
}

void MainWindow::on_radioMoore_released()
{
    manager->setNeighborhoodType(NeighborhoodType::MOORE);
}

void MainWindow::on_buttonClear_released()
{
    manager->clearBoard();
    manager->getBoard()->print();
}

void MainWindow::on_buttonRevert_released()
{
    manager->revertBoard();
    manager->getBoard()->print();
}

void MainWindow::on_buttonRandomize_released()
{
    manager->randomizeBoard();
    manager->getBoard()->print();
}

void MainWindow::on_spinBoxHeight_editingFinished()
{
    manager->changeBoardHeight(ui->spinBoxHeight->value());
    manager->getBoard()->print();
}

void MainWindow::on_spinBoxWidth_editingFinished()
{
    manager->changeBoardWidth(ui->spinBoxWidth->value());
    manager->getBoard()->print();
}
