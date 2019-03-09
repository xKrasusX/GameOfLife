#include <list>
#include <utility>

#include "boardmanager.hpp"
#include "../static/neighborhoodtype.hpp"

BoardManager::BoardManager()
{
    board = new Board();
    neighborhoodType = NeighborhoodType::MOORE;
    fileManager = new FileManager();
}

void BoardManager::clearBoard() {
    board->makeEmpty();
}

void BoardManager::revertBoard() {
    board->revert();
}

void BoardManager::revertField(int h, int w) {
    board->revertField(h, w);
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

bool BoardManager::readBoardFromFile(std::string path) {
    BoardData *boardData = fileManager->readFromFile(path);
    if(boardData != NULL) {
        setBoardWithBoardData(boardData);
        return true;
    }
    return false;
}

void BoardManager::saveBoardToFile(std::string path) {
    BoardData *boardData = setBoardDataWithBoard();
    fileManager->saveToFile(boardData, path);
}

int BoardManager::getHeight() {
    return board->getHeight();
}

int BoardManager::getWidth() {
    return board->getWidth();
}

bool BoardManager::getIsFieldAlive(int h, int w) {
    return board->isFieldAlive(h, w);
}

Board *BoardManager::getBoard() {
    return board;
}

void BoardManager::setNeighborhoodType(int neighborhoodType) {
    this->neighborhoodType = neighborhoodType;
}

void BoardManager::setBoardWithBoardData(BoardData *boardData) {
    board = new Board();
    board->changeSize(boardData->getHeight(), boardData->getWidth());
    for(const auto& p : boardData->getAliveCells())
        board->revertField(p.first, p.second);
}

BoardData *BoardManager::setBoardDataWithBoard() {
    BoardData *boardData = new BoardData();
    boardData->setHeight(board->getHeight());
    boardData->setWidth(board->getWidth());

    for(int i=0; i<board->getHeight(); i++)
        for(int j=0; j<board->getWidth(); j++)
            if(board->isFieldAlive(i, j))
                boardData->addAliveCell(i, j);

    return boardData;
}
