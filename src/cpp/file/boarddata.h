#ifndef BOARDDATA_H
#define BOARDDATA_H

#include <list>
#include "../templates/pair.h"

/** \brief Class representing the board in a convenient way to save/read from .txt file.
 */
class BoardData
{

public:
    /** \brief Standard constructor returning new BoardData object.
     */
    BoardData();

    /** \brief Standard destructor deleting the BoardData object.
     */
    ~BoardData();

    /** \brief Adds new cell to the list of alive fields.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \return void
     */
    void addAliveCell(int h, int w);

    /** \brief Returns height of the board.
     * \return int Height of the board.
     */
    int getHeight();


    /** \brief Sets height of the board.
     * \param height int Height of the board.
     * \return void
     */
    void setHeight(int height);

    /** \brief Returns width of the board.
     * \return int Width of the board.
     */
    int getWidth();

    /** \brief Sets width of the board.
     * \param width int Width of the board.
     * \return void
     */
    void setWidth(int width);

    /** \brief Gets list of coordinates of alive fields.
     * \return std::list<Pair<int>*> List of coordinates of alive fields.
     */
    std::list<Pair<int>*> getAliveCells();

private:

    int height, width;
    std::list<Pair<int>*> aliveCells;
};

#endif // BOARDDATA_H
