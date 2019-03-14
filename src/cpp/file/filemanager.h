#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

#include "boarddata.h"

/** \brief Class managing saving/reading board from file.
 */
class FileManager
{

public:
    /** \brief Standard constructor returning new FileManager object.
     */
    FileManager();

    /** \brief Reads board from .txt file if in appropriate format.
     * \param path std::string Path to the source file.
     * \return BoardData* Board in a convenient format. Return NULL if error while reading from file.
     */
    BoardData *readFromFile(std::string path);

    /** \brief Saves board to .txt file.
     * \param boardData BoardData* Board in a convenient format.
     * \param path std::string Path to the .txt file.
     * \return void
     */
    void saveToFile(BoardData *boardData, std::string path);
};

#endif // FILEMANAGER_H
