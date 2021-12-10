#include "Cell.h"

Cell::Cell() {};
Cell::Cell(const Cell& other){
    this->type = other.type;
}
Cell& Cell::operator = (const Cell& other){
    if(this != &other){
        this->type = other.type;
    }
    return *this;
}
Cell::Cell(Cell &&other) {
    std::swap(this->type, other.type);
}
Cell& Cell::operator = (Cell&& other){
    if(this != &other){
        std::swap(this->type, other.type);
    }
    return *this;
}
void Cell::SetType(CellTypes value){
    type = value;
}
CellTypes Cell::GetType() {
    return type;
}
bool Cell::IsMovable() {
    if(type != Wall){
        return true;
    }
    return false;
}
void Cell::SetObject(Object* obj) {
    this->object = obj;
}
ObjectType Cell::GetObjectType() {
    if(this->object != nullptr){
        return this->object->GetType();
    }
    return empty;
}
Object* Cell::GetObject() {
    return this->object;
};
Cell::~Cell(){}