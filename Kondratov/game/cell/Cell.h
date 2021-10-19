#ifndef SFMLPROJ_CELL_H
#define SFMLPROJ_CELL_H

#include "../objects/CellObject.h"

#define WIDTH 32

enum Types {
    WALL = 0,
    FOUNDATION = 1,
    EXIT = 2,
    ENTRY = 3
};

class Cell {
private:
    CellObject* object;
    Types type;
public:
    explicit Cell(Types t = FOUNDATION, CellObject* object = nullptr);
    bool is_passable();
    void set_type(Types t);
    Types get_type();
    CellObject* get_obj();
    void set_obj(CellObject* obj);
    Cell& operator= (const Cell& other);
};


#endif
