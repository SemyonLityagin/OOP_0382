#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <iostream>
#include "Cell/Cell.h"

#define Size 11

class Field{
private:
    Cell** cells;
public:
    Field();
    Field(const Field& other);
    Field& operator = (const Field& other);
    Field(Field&& other);
    Field& operator = (Field&& other);
    Cell** GetCells();
    ~Field();
};
#endif //GAME_FIELD_H
