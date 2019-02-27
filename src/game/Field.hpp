#ifndef FIELD_H
#define FIELD_H

class Field
{

private:
    bool isAlive;

public:
    Field(bool isAlive = false);
    bool getIsAlive();
    void setIsAlive(bool isAlive);
};

#endif


