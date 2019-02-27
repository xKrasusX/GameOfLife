//TODO implement foreach
#include <cstdlib>
#include <iostream> //TODO delete this
#include <new>

#include "Board.hpp"

using namespace std; //TODO delete this

Board::Board()
{
    this->height = 20;
    this->width = 20;
    fillWithDeadCells();
}

Board::Board(int height, int width, Board currentBoard)
{
    this->height = height;
    this->width = width;
    fillWithDeadCells();

    for(int i=0; i<height; i++) {
        if(i >= currentBoard.height)
            break;

        for(int j=0; j<width; j++)
            if(j < currentBoard.width)
                fields[i][j].setIsAlive(currentBoard.fields[i][j].getIsAlive());
    }
}

void Board::clearBoard() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j].setIsAlive(false);
}

void Board::revertBoard() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j].setIsAlive(!fields[i][j].getIsAlive());
}

void Board::randomizeBoard() {
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            fields[i][j].setIsAlive(getRandomBool());
}

void Board::fillWithDeadCells() {
    fields = new Field*[height];
    for(int i=0; i<height; i++)
        fields[i] = new Field[width];
}

bool Board::getRandomBool() {
    return rand()%2;
}






void Board::printBoard() { //TODO delete this
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            string str = fields[i][j].getIsAlive() ? "X" : ".";
            cout << str;
        }
        cout << endl;
    }
}
