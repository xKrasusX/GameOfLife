#ifndef BOARD_HPP
#define BOARD_HPP

#include "field.hpp"

class Board
{

public:
    static const int MAX_HEIGHT = 99;
    static const int MAX_WIDTH = 99;

    Board();
    void changeSize(int height, int width);
    void makeEmpty();
    void revert();
    void revertField(int h, int w);
    void randomize();
    void updateNextStep(int neighborhoodType);
    int getHeight();
    int getWidth();

    void print();

private:
    int height, width;
    Field **fields;

    void fillWithDeadCells();
    bool getRandomBool();
    bool **calculateStateChanges(int neighborhoodType);
    int countAliveNeighbors(int h, int w, int neighborhoodType);
};

#endif
