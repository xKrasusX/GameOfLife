#include "boarddata.hpp"

BoardData::BoardData()
{

}

void BoardData::addAliveCell(int h, int w) {
    aliveCells.push_back(std::make_pair(h, w));
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

std::list<std::pair<int, int>> BoardData::getAliveCells() {
    return aliveCells;
}
