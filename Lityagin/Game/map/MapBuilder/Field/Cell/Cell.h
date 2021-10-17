#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <cstring>
#include "IntObj.h"
/*
 * Cell type:
 *      Exit - 3
 *      Wall - 2
 *      Floor - 1
 *      Enter - 0
 */
enum CellTypes {Enter, Floor, Wall, Exit};

class Cell{
private:
    int type;
    IntObj* object;
public:
    Cell();
    Cell(const Cell& other);
    Cell& operator = (const Cell& other);
    void SetType(CellTypes value);
    int GetType();
    bool IsMovable();
    ~Cell();
};

#endif //GAME_CELL_H
