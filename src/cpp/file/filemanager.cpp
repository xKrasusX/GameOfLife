#include <fstream>

#include "filemanager.hpp"
#include "../game/board.hpp"

#include <iostream> //TODO delete this
using namespace std; //TODO delete this

FileManager::FileManager()
{

}

void FileManager::testRead(std::string path) {
    int height = 0, width = 0;
    int h, w;
    int line = 0;
    bool isCorrect = true;

    std::ifstream file(path);
    while(isCorrect && file >> h >> w) {
        if(line == 0) {
            if(h<1 || h>Board::MAX_HEIGHT || w<1 || w>Board::MAX_WIDTH) {
                isCorrect = false;
                break;
            }
            height = h;
            width = w;
        } else {
            if(h<0 || h>=height || w<0 || w>=width) {
                isCorrect = false;
                break;
            }
            cout << h << " " << w << endl;
        }
        line++;
    }

    if(line == 0 || !file.eof())
        isCorrect = false;

    cout << "correct" << isCorrect << endl;
    cout << "line" << line << endl;
    cout << "eof" << file.eof() <<endl << endl;
}
