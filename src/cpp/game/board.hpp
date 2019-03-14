#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{

public:
    Board();
    void changeSize(int height, int width);
    void makeEmpty();
    void revert();
    void revertField(int h, int w);
    void randomize();
    void updateNextStep(int neighborhoodType);
    bool isFieldAlive(int h, int w);
    int getHeight();
    int getWidth();

private:
    int height, width;
    bool **fields;

    void fillWithDeadCells();
    bool getRandomBool();
    bool **calculateStateChanges(int neighborhoodType);
    int countAliveNeighbors(int h, int w, int neighborhoodType);
};

#endif
