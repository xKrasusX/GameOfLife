#ifndef LABELCELL_H
#define LABELCELL_H

#include <QLabel>

#include "../game/boardmanager.h"

/** \brief Class representing the graphic representation of a field.
 */
class LabelCell : public QLabel
{
    Q_OBJECT

public:

    /** \brief Constructor returning new LabelCell object with predefined properties.
     * \param h int Vertical position of cell.
     * \param w int Horizontal position of cell.
     * \param color QColor Initial color a cell (black/white).
     * \param parent QWidget* Parent QWidget of a cell.
     */
    LabelCell(int h, int w, QColor color, QWidget *parent);

    /** \brief Sets the color of a cell.
     * \param c QColor The new color of a cell.
     * \return void
     */
    void setColor(QColor c);

protected:
    /** \brief Inherited from QWidget class.
     * \param event QMouseEvent* Mouse event invoking the method.
     * \return void
     */
    void mouseReleaseEvent(QMouseEvent* event);

private:
    int h, w;
    QWidget *parent;
    QColor color;
};

#endif // LABELCELL_H
