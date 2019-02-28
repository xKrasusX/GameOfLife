//TODO implement foreach
#include <cstdlib>
#include <iostream> //TODO delete this
#include <new>

#include "Board.hpp"
#include "../static/NeighborhoodType.hpp"

using namespace std; //TODO delete this

Board::Board()
{
    this->height = 20;
    this->width = 20;
    fillWithDeadCells();
}

void Board::changeSize(int height, int width)
{
    Field **currentFields = fields;
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
                fields[i][j].setIsAlive(currentFields[i][j].getIsAlive());
    }
}

void Board::makeEmpty() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j].setIsAlive(false);
}

void Board::revert() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            revertField(i, j);
}

void Board::revertField(int h, int w) {
    fields[h][w].setIsAlive(!fields[h][w].getIsAlive());
}

void Board::randomize() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j].setIsAlive(getRandomBool());
}

void Board::updateNextStep(int neighborhoodType) {
    bool **stateChanges = calculateStateChanges(neighborhoodType);
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(stateChanges[i][j])
                revertField(i, j);
}

void Board::fillWithDeadCells() {
    fields = new Field*[height];
    for(int i=0; i<height; i++)
        fields[i] = new Field[width];
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
            if((!fields[i][j].getIsAlive() && aliveN==3) || (fields[i][j].getIsAlive() && aliveN!=3 && aliveN!=2))
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
    if(fields[hBefore][w].getIsAlive())        aliveNeighbors++;
    if(fields[h][wBefore].getIsAlive())        aliveNeighbors++;
    if(fields[h][wAfter].getIsAlive())         aliveNeighbors++;
    if(fields[hAfter][w].getIsAlive())         aliveNeighbors++;

    if(neighborhoodType == NeighborhoodType::MOORE) {
        if(fields[hBefore][wBefore].getIsAlive())  aliveNeighbors++;
        if(fields[hBefore][wAfter].getIsAlive())   aliveNeighbors++;
        if(fields[hAfter][wBefore].getIsAlive())   aliveNeighbors++;
        if(fields[hAfter][wAfter].getIsAlive())    aliveNeighbors++;
    }
    return aliveNeighbors;
}






void Board::printAll() { //TODO delete this
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            string str = fields[i][j].getIsAlive() ? "X" : ".";
            cout << str;
        }
        cout << endl;
    }
}
