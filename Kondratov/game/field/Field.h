#ifndef SFMLPROJ_FIELD_H
#define SFMLPROJ_FIELD_H

#include <SFML/Graphics.hpp>
#include "../cell/Cell.h"

#define SIZE 20



class Field {
private:
    Cell** grid;
public:
    Field();
    Field(const Field& source);
    Field& operator= (const Field &other);
    Field(Field&& other);
    Field& operator= (Field&& other);
    void setCell(int i, int j, Cell& cell);
    Cell& getCell(int i, int j);
    ~Field();
};


#endif
