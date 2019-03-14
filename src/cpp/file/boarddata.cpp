#include "boarddata.hpp"

BoardData::BoardData() {
}

BoardData::~BoardData() {
    for(const auto p: aliveCells)
        delete p;
}

void BoardData::addAliveCell(int h, int w) {
    aliveCells.push_back(new Pair<int>(h, w));
}

int BoardData::getHeight() {
    return height;
}

void BoardData::setHeight(int height) {
    this->height = height;
}

int BoardData::getWidth() {
    return width;
}

void BoardData::setWidth(int width) {
    this->width = width;
}

std::list<Pair<int>*> BoardData::getAliveCells() {
    return aliveCells;
}
