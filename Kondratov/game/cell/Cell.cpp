#include "Cell.h"

Cell::Cell(Types t, CellObject *o) : type(t), object(o) {}

void Cell::set_type(Types t) {
    this->type = t;
}

Types Cell::get_type() {
    return this->type;
}

bool Cell::is_passable() {
    return this->type;
}

CellObject *Cell::get_obj() {
    return this->object;
}

void Cell::set_obj(CellObject *obj) {
    this->object = obj;
}

Cell &Cell::operator=(const Cell &other) {
    if (this != &other) {
        *this->object = *other.object;
        this->type = other.type;
    }
    return *this;
}

