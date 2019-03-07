#include <fstream>

#include "filemanager.hpp"
#include "../static/boardsize.hpp"

#include <iostream> //TODO delete this
using namespace std; //TODO delete this

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
        cout << h << " " << w << endl;
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

}
