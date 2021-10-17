#include "Cell.h"

Cell::Cell() {};

Cell::Cell(const Cell &other){
    type = other.type;
}
Cell& Cell::operator = (const Cell& other){
    if(this != &other){
        this->type = other.type;
    }
    return *this;
}

void Cell::SetType(CellTypes value){
        type = value;
}

int Cell::GetType() {
    return type;
}

bool Cell::IsMovable() {
    if(type != 2){
        return true;
    }
    return false;
}
Cell::~Cell(){};
