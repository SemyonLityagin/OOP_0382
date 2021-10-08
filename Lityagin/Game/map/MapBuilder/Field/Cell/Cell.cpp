#include "Cell.h"

Cell::Cell() {};

Cell::Cell(const Cell &other){
    //texture = new Texture;
    texture = other.texture;
    //sprite = new Sprite;
    sprite = other.sprite;
}
Cell& Cell::operator = (const Cell& other){
    if(this != &other){
        //*this = Cell();
        //this->texture = new Texture;
        this->texture = other.texture;
        //this->sprite = new Sprite;
        this->sprite = other.sprite;
    }
    return *this;
}

void Cell::SetTexture(const std::string &filename) {
    texture.loadFromFile(filename);
}

void Cell::SetPosition(int PosX, int PosY) {
    sprite = new Sprite(texture);
    sprite->setPosition(PosX * 40, PosY * 40);
}

Sprite* Cell::GetSprite() {
    return sprite;
}

Cell::~Cell(){
    delete sprite;
};
