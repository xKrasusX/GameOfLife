#ifndef BOARD_H
#define BOARD_H

/** \brief Class representing the board.
 */
class Board
{

public:
    /** \brief Standard constructor returning new Board object with predefined size.
     */
    Board();

    /** \brief Standard destructor deleting the Board object.
     */
    ~Board();

    /** \brief Changes size of the board.
     * \param height int New height of the board.
     * \param width int New width of the board.
     * \return void
     */
    void changeSize(int height, int width);

    /** \brief Makes all the fields of the board dead.
     * \return void
     */
    void makeEmpty();

    /** \brief Reverts dead fields to alive and vice-versa.
     * \return void
     */
    void revert();

    /** \brief Reverts single field to alive and vice-versa.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \return void
     */
    void revertField(int h, int w);

    /** \brief Sets random dead/alive value to every field of the board.
     * \return void
     */
    void randomize();

    /** \brief Updates the board based on the current state.
     * \param neighborhoodType int Type of neighborhood (Moore/von Neumann) based on a static dictionary.
     * \return void
     */
    void updateNextStep(int neighborhoodType);

    /** \brief Checks if field is alive.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \return bool True if alive, false if dead.
     */
    bool isFieldAlive(int h, int w);

    /** \brief Returns height of the board.
     * \return int Height of the board.
     */
    int getHeight();

    /** \brief Returns width of the board.
     * \return int Width of the board.
     */
    int getWidth();

private:
    int height, width;
    bool **fields;

    /** \brief Fills board with dead fields.
     * \return void
     */
    void fillWithDeadCells();

    /** \brief Returns true/false boolean in a 50/50 chance.
     * \return bool The generated value.
     */
    bool getRandomBool();

    /** \brief Returns the board-sized table of boolean tables. If the field's value is true,
     * the corresponding field on board has to be reverted.
     * \param neighborhoodType int Type of neighborhood (Moore/von Neumann) based on a static dictionary.
     * \return bool** The board-sized table of boolean tables.
     */
    bool **calculateStateChanges(int neighborhoodType);

    /** \brief Calculates the number of alive neighbors of a given cell.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \param neighborhoodType int Type of neighborhood (Moore/von Neumann) based on a static dictionary.
     * \return int The number of alive neighbors.
     */
    int countAliveNeighbors(int h, int w, int neighborhoodType);

    /** \brief Deletes the internal table of field tables.
     * \return void
     */
    void deleteFields();
};

#endif // BOARD_H
