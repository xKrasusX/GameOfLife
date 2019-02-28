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
    bool **calculateStateChanges(int neighborhoodType);
    int countAliveNeighbors(int h, int w, int neighborhoodType);

public:
    Board();
    void changeSize(int height, int width);
    void makeEmpty();
    void revert();
    void revertField(int h, int w);
    void randomize();
    void updateNextStep(int neighborhoodType);




    void printAll(); //TODO delete this
};

#endif
