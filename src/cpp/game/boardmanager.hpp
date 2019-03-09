#ifndef BOARDMANAGER_HPP
#define BOARDMANAGER_HPP

#include "board.hpp"
#include "../file/filemanager.hpp"
#include "../file/boarddata.hpp"

class BoardManager
{

public:
    BoardManager();
    void clearBoard();
    void revertBoard();
    void revertField(int h, int w);
    void randomizeBoard();
    void changeBoardHeight(int height);
    void changeBoardWidth(int width);
    Board *updateBoard();
    bool readBoardFromFile(std::string path);
    void saveBoardToFile(std::string path);
    int getHeight();
    int getWidth();
    bool getIsFieldAlive(int h, int w);
    Board *getBoard();
    void setNeighborhoodType(int neighborhoodType);

private:
    Board *board;
    int neighborhoodType;
    FileManager *fileManager;

    void setBoardWithBoardData(BoardData *boardData);
    BoardData *setBoardDataWithBoard();
};

#endif // BOARDMANAGER_HPP
