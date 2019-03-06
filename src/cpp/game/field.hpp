#ifndef FIELD_H
#define FIELD_H

class Field
{

public:
    Field(bool isAlive = false);
    bool getIsAlive();
    void setIsAlive(bool isAlive);

private:
    bool isAlive;
};

#endif


