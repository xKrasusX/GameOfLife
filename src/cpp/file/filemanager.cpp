#include "filemanager.hpp"

#include <iostream> //TODO delete this
using namespace std; //TODO delete this

#include <fstream>

FileManager::FileManager()
{

}

void FileManager::testRead(std::string path) {
    int h, w;
    std::ifstream file(path);
    while(file >> h >> w) {
        cout << h << " " << w << endl;
    }
}
