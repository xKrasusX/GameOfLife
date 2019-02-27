#ifndef BOARD_H
#define BOARD_H

#include "Field.hpp"

class Board
{

private:
    int height, width;
    Field **fields;

    void fillWithDeadCells();
    bool getRandomBool();

public:
    Board();
    Board(int height, int width, Board currentBoard);
    void clearBoard();
    void revertBoard();
    void randomizeBoard();



    void printBoard(); //TODO delete this
};

#endif
