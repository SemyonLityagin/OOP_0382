#include "Cell.h"

Cell::Cell(int PosX, int PosY, const std::string &filename) {
    x = PosX;
    y = PosY;
    texture = new Texture;
    texture->loadFromFile(filename);
    sprite = new Sprite(*texture);
    sprite->setPosition(x * 40, y * 40);
}
Cell::~Cell(){
    delete texture;
    delete sprite;
};
