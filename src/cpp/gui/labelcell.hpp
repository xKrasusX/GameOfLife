#ifndef LABELCELL_HPP
#define LABELCELL_HPP

#include <QLabel>

#include "../game/boardmanager.hpp"

class LabelCell : public QLabel
{
    Q_OBJECT

public:
    LabelCell(int h, int w, QColor color, QWidget *parent);
    void setColor(QColor c);

protected:
    void mouseReleaseEvent(QMouseEvent* event);

private:
    int h, w;
    QWidget *parent;
    QColor color;
};

#endif // LABELCELL_HPP
