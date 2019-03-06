#ifndef BOARDMANAGER_HPP
#define BOARDMANAGER_HPP

#include "board.hpp"
#include "../file/filemanager.hpp"

class BoardManager
{

public:
    BoardManager();
    void setNeighborhoodType(int neighborhoodType);
    void clearBoard();
    void revertBoard();
    void randomizeBoard();
    void changeBoardHeight(int height);
    void changeBoardWidth(int width);
    Board *updateBoard();
    void readBoardFromFile(std::string path);
    Board *getBoard();

private:
    Board *board;
    int neighborhoodType;
    FileManager *fileManager;
};

#endif // BOARDMANAGER_HPP
