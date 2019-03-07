#ifndef BOARDDATA_HPP
#define BOARDDATA_HPP

#include <list>
#include <utility>

class BoardData
{

public:
    BoardData();
    void addAliveCell(int h, int w);
    int getHeight();
    void setHeight(int height);
    int getWidth();
    void setWidth(int width);
    std::list<std::pair<int, int>> getAliveCells();

private:
    int height, width;
    std::list<std::pair<int, int>> aliveCells;
};

#endif // BOARDDATA_HPP
