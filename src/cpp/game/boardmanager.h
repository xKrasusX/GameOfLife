#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include "board.h"
#include "../file/filemanager.h"
#include "../file/boarddata.h"

/** \brief Class managing the board and communicating with UI.
 */
class BoardManager
{

public:

    /** \brief Standard constructor returning new BoardManager object.
     */
    BoardManager();

    /** \brief Standard destructor deleting the BoardManager object.
     */
    ~BoardManager();

    /** \brief Makes all the fields of the board dead.
     * \return void
     */
    void clearBoard();

    /** \brief Reverts dead fields of the board to alive and vice-versa.
     * \return void
     */
    void revertBoard();

    /** \brief Reverts single field of the board to alive and vice-versa.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \return void
     */
    void revertField(int h, int w);

    /** \brief Sets random dead/alive value to every field of the board.
     * \return void
     */
    void randomizeBoard();

    /** \brief Changes height of the board.
     * \param height int New height of the board.
     * \return void
     */
    void changeBoardHeight(int height);

    /** \brief Changes width of the board.
     * \param width int New width of the board.
     * \return void
     */
    void changeBoardWidth(int width);

    /** \brief Updates the board based on the current state.
     * \return void
     */
    void updateBoard();

    /** \brief Reads board from .txt file (if in appropriate format) and updates the board.
     * \param path std::string Path to the source file.
     * \return bool True if read successfully, false if not.
     */
    bool readBoardFromFile(std::string path);

    /** \brief Saves board to .txt file.
     * \param path std::string Path to the .txt file.
     * \return void
     */
    void saveBoardToFile(std::string path);

    /** \brief Returns height of the board.
     * \return int Height of the board.
     */
    int getHeight();

    /** \brief Returns width of the board.
     * \return int Width of the board.
     */
    int getWidth();

    /** \brief Checks if field is alive.
     * \param h int Vertical position of field.
     * \param w int Horizontal position of field.
     * \return bool True if alive, false if dead.
     */
    bool getIsFieldAlive(int h, int w);

    /** \brief Sets neighborhood type of the game.
     * \param neighborhoodType int Type of neighborhood (Moore/von Neumann) based on a static dictionary.
     * \return void
     */
    void setNeighborhoodType(int neighborhoodType);

private:
    Board *board;
    int neighborhoodType;
    FileManager *fileManager;

    /** \brief Converts BoardData object and saves it as the internal Board object.
     * \param boardData BoardData* Object to be converted.
     * \return void
     */
    void setBoardWithBoardData(BoardData *boardData);

    /** \brief Converts internal Board object to BoardData object.
     * \return BoardData* Board in a convenient format to save/read from .txt file.
     */
    BoardData *setBoardDataWithBoard();
};

#endif // BOARDMANAGER_H
