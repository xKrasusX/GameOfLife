#include <iostream> //TODO delete this

#include "Field.hpp"

using namespace std; //TODO delete this

Field::Field(bool isAlive)
{
    this->isAlive = isAlive;
}

bool Field::getIsAlive() {
    return isAlive;
}

void Field::setIsAlive(bool isAlive) {
    this->isAlive = isAlive;
}
