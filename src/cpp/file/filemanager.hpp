#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>

#include "boarddata.hpp"

class FileManager
{

public:
    FileManager();
    BoardData *readFromFile(std::string path);
    void saveToFile(BoardData *boardData, std::string path);
};

#endif // FILEMANAGER_HPP
