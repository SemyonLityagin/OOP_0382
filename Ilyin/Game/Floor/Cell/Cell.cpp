#include "Cell.h"

Cell::Cell(const std::string& filename, sf::Vector2i position, Elem elem, Type type): _position(position), _elem(elem), _type(type){
    _texture = new sf::Texture;
    _texture->loadFromFile(filename);
    _sprite = new sf::Sprite(*_texture);
    _sprite->setPosition(WIDTH*position.x, WIDTH*position.y);
}

void Cell::setTexture(const std::string& filename){
    _texture = new sf::Texture;
    _texture->loadFromFile(filename);
    _sprite = new sf::Sprite(*_texture);
    _sprite->setPosition(WIDTH*_position.x, WIDTH*_position.y);
};

sf::Sprite* Cell::getSprite(){
    return _sprite;
};

Cell::~Cell() {
    delete _texture;
    delete _sprite;
}

void Cell::setElem(Elem elem){
    _elem = elem;
};

Elem Cell::getElem(){
    return _elem;
};

void Cell::setType(Type type){
    _type = type;
};

Type Cell::getType(){
    return _type;
};