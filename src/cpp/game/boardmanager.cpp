#include "boardmanager.hpp"
#include "../static/neighborhoodtype.hpp"

BoardManager::BoardManager()
{
    board = new Board();
    neighborhoodType = NeighborhoodType::MOORE;
    fileManager = new FileManager();
}

void BoardManager::setNeighborhoodType(int neighborhoodType) {
    this->neighborhoodType = neighborhoodType;
}

void BoardManager::clearBoard() {
    board->makeEmpty();
}

void BoardManager::revertBoard() {
    board->revert();
}

void BoardManager::randomizeBoard() {
    board->randomize();
}

void BoardManager::changeBoardHeight(int height) {
    board->changeSize(height, board->getWidth());
}

void BoardManager::changeBoardWidth(int width) {
    board->changeSize(board->getHeight(), width);
}

Board *BoardManager::updateBoard() {
    board->updateNextStep(neighborhoodType);
    return board;
}

void BoardManager::readBoardFromFile(std::string path) {
    fileManager->testRead(path);
}

Board *BoardManager::getBoard() {
    return board;
}
