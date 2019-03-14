#include "labelcell.h"
#include "mainwindow.h"

LabelCell::LabelCell(int h, int w, QColor color, QWidget *parent)
{
    this->h = h;
    this->w = w;
    this->parent = parent;
    setColor(this->color = color);
    setFixedSize(9, 9);
}

void LabelCell::setColor(QColor c) {
    color = c;
    if(color == Qt::white)
        setStyleSheet("QLabel {background-color: white;}");
    else
        setStyleSheet("QLabel {background-color: black;}");
}

void LabelCell::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    static_cast<MainWindow*> (parent)->revertField(h, w);
}
