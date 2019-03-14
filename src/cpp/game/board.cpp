#include <cstdlib>

#include "board.hpp"
#include "../static/neighborhoodtype.hpp"

Board::Board()
{
    this->height = 20;
    this->width = 20;
    fillWithDeadCells();
}

void Board::changeSize(int height, int width)
{
    bool **currentFields = fields;
    int currentH = this->height;
    int currentW = this->width;

    this->height = height;
    this->width = width;
    fillWithDeadCells();

    for(int i=0; i<height; i++) {
        if(i >= currentH)
            break;
        for(int j=0; j<width; j++)
            if(j < currentW)
                fields[i][j] = currentFields[i][j];
    }
}

void Board::makeEmpty() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j] = false;
}

void Board::revert() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            revertField(i, j);
}

void Board::revertField(int h, int w) {
    fields[h][w] = !fields[h][w];
}

void Board::randomize() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j] = getRandomBool();
}

void Board::updateNextStep(int neighborhoodType) {
    bool **stateChanges = calculateStateChanges(neighborhoodType);
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(stateChanges[i][j])
                revertField(i, j);
}

bool Board::isFieldAlive(int h, int w) {
    return fields[h][w];
}

int Board::getHeight() {
    return height;
}

int Board::getWidth() {
    return width;
}

void Board::fillWithDeadCells() {
    fields = new bool*[height];
    for(int i=0; i<height; i++) {
        fields[i] = new bool[width];
        for(int j=0; j<width; j++)
            fields[i][j] = false;
    }
}

bool Board::getRandomBool() {
    return rand()%2;
}

bool **Board::calculateStateChanges(int neighborhoodType) {
    bool **stateChanges = new bool*[height];
    for(int i=0; i<height; i++) {
        stateChanges[i] = new bool[width];
        for(int j=0; j<width; j++)
            stateChanges[i][j] = false;
    }

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int aliveN = countAliveNeighbors(i, j, neighborhoodType);
            if((!fields[i][j] && aliveN==3) || (fields[i][j] && aliveN!=3 && aliveN!=2))
                stateChanges[i][j] = true;
        }
    }
    return stateChanges;
}

int Board::countAliveNeighbors(int h, int w, int neighborhoodType) {
    int hBefore = h==0 ? height-1 : h-1;
    int hAfter = h==height-1 ? 0 : h+1;
    int wBefore = w==0 ? width-1 : w-1;
    int wAfter = w==width-1 ? 0 : w+1;

    int aliveNeighbors = 0;
    if(fields[hBefore][w])        aliveNeighbors++;
    if(fields[h][wBefore])        aliveNeighbors++;
    if(fields[h][wAfter])         aliveNeighbors++;
    if(fields[hAfter][w])         aliveNeighbors++;

    if(neighborhoodType == NeighborhoodType::MOORE) {
        if(fields[hBefore][wBefore])  aliveNeighbors++;
        if(fields[hBefore][wAfter])   aliveNeighbors++;
        if(fields[hAfter][wBefore])   aliveNeighbors++;
        if(fields[hAfter][wAfter])    aliveNeighbors++;
    }
    return aliveNeighbors;
}
