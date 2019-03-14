#ifndef BOARDDATA_HPP
#define BOARDDATA_HPP

#include <list>
#include "../templates/pair.hpp"

class BoardData
{

public:
    BoardData();
    ~BoardData();
    void addAliveCell(int h, int w);
    int getHeight();
    void setHeight(int height);
    int getWidth();
    void setWidth(int width);
    std::list<Pair<int>*> getAliveCells();

private:
    int height, width;
    std::list<Pair<int>*> aliveCells;
};

#endif // BOARDDATA_HPP
