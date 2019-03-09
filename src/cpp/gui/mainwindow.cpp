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
    createView();
    ui->labelError->setStyleSheet("QLabel {color: red;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::revertField(int h, int w) {
    ui->labelError->clear();
    manager->revertField(h, w);
    updateView();
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
    updateView();
}

void MainWindow::on_buttonRevert_released()
{
    ui->labelError->clear();
    manager->revertBoard();
    updateView();
}

void MainWindow::on_buttonRandomize_released()
{
    ui->labelError->clear();
    manager->randomizeBoard();
    updateView();
}

void MainWindow::on_spinBoxHeight_editingFinished()
{
    ui->labelError->clear();
    manager->changeBoardHeight(ui->spinBoxHeight->value());
    createView();
}

void MainWindow::on_spinBoxWidth_editingFinished()
{
    ui->labelError->clear();
    manager->changeBoardWidth(ui->spinBoxWidth->value());
    createView();
}

void MainWindow::on_buttonLoad_released()
{
    std::string path = QFileDialog::getOpenFileName(this, "Load from file", "C:/", "*.txt").toStdString();
    if(!path.empty()) {
        bool readSuccess = manager->readBoardFromFile(path);
        if(readSuccess) {
            ui->labelError->clear();
            ui->spinBoxHeight->setValue(manager->getHeight());
            ui->spinBoxWidth->setValue(manager->getWidth());
            createView();
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
    updateView();
}

void MainWindow::on_buttonStartStop_released()
{
    ui->labelError->clear();
    if(ui->buttonStartStop->text() == "Start") {
        ui->buttonStartStop->setText("Stop");
        setComponentsEnabled(false);
        gameThread = new GameThread();
        connect(gameThread, SIGNAL(update()), this, SLOT(onUpdate()));
        gameThread->start();
    } else {
        gameThread->terminate();
        gameThread->~GameThread();
        ui->buttonStartStop->setText("Start");
        setComponentsEnabled(true);
        repaint();
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

void MainWindow::createView() {
    for(const auto label: cells){
        delete label;
    }
    cells.clear();

    for(int i=0; i<manager->getHeight(); i++) {
        for(int j=0; j<manager->getWidth(); j++) {
            LabelCell *cell= new LabelCell(i, j, manager->getIsFieldAlive(i, j) ? Qt::black : Qt::white, this);
            cells.push_back(cell);
            ui->gridLayout->addWidget(cell, i, j);
        }
    }
}

void MainWindow::updateView() {
    for(int i=0; i<manager->getHeight(); i++)
        for(int j=0; j<manager->getWidth(); j++)
            static_cast<LabelCell*> (ui->gridLayout->itemAtPosition(i, j)->widget())->setColor(manager->getIsFieldAlive(i, j) ? Qt::black : Qt::white);
}

void MainWindow::onUpdate() {
    manager->updateBoard();
    updateView();
}
