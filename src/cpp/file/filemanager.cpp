#include <fstream>

#include "filemanager.hpp"
#include "../static/boardsize.hpp"

FileManager::FileManager()
{

}

BoardData *FileManager::readFromFile(std::string path) {
    BoardData *boardData = new BoardData();
    int height = 0, width = 0;
    int h, w;
    int line = 0;
    bool isCorrect = true;

    std::ifstream file(path);
    while(isCorrect && file >> h >> w) {
        if(line == 0) {
            if(h<1 || h>BoardSize::MAX_HEIGHT || w<1 || w>BoardSize::MAX_WIDTH) {
                isCorrect = false;
            }
            boardData->setHeight(height = h);
            boardData->setWidth(width = w);
        } else {
            if(h<0 || h>=height || w<0 || w>=width) {
                isCorrect = false;
            }
            boardData->addAliveCell(h, w);
        }
        line++;
    }

    if(line == 0 || !file.eof())
        isCorrect = false;

    return isCorrect ? boardData : NULL;
}

void FileManager::saveToFile(BoardData *boardData, std::string path) {
    std::ofstream file(path);
    file << boardData->getHeight() << " " << boardData->getWidth() << std::endl;
    for(const auto& p : boardData->getAliveCells())
        file << p->getX() << " " << p->getY() << std::endl;
}
