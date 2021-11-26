#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <cstring>
#include <iostream>
#include "../../../Units/Object.h"
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
    CellTypes type;
    Object* object = nullptr;
public:
    Cell();
    Cell(const Cell& other);
    Cell& operator = (const Cell& other);
    Cell(Cell&& other);
    Cell& operator = (Cell&& other);
    void SetType(CellTypes value);
    void SetObject(Object* obj);
    Object* GetObject();
    ObjectType GetObjectType();
    CellTypes GetType();
    bool IsMovable();
    ~Cell();
};

#endif //GAME_CELL_H
