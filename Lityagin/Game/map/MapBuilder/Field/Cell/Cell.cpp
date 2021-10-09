#include "Cell.h"

Cell::Cell() {};

Cell::Cell(const Cell &other){
    texture = other.texture;
    sprite = other.sprite;
}
Cell& Cell::operator = (const Cell& other){
    if(this != &other){
        this->texture = other.texture;
        this->sprite = other.sprite;
    }
    return *this;
}

void Cell::SetTexture(const std::string &filename) {
    texture.loadFromFile(filename);
}

void Cell::SetPosition(int PosX, int PosY) {
    sprite = Sprite(texture);
    sprite.setPosition(PosX * 40, PosY * 40);
}

Sprite Cell::GetSprite() {
    return sprite;
}
void Cell::SetType(int value){
        type = value;
}
bool Cell::IsMovable() {
    if(type != 2){
        return true;
    }
    return false;
}
Cell::~Cell(){};
