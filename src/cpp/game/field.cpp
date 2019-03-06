#include "field.hpp"

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
