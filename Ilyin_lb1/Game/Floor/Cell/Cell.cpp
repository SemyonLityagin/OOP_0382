#include "Cell.h"

Cell::Cell(const std::string& filename, sf::Vector2i position, Elem* elem, Type type): _position(position), _elem(elem), _type(type){
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

void Cell::setElem(Elem* elem){
    _elem = elem;
};

Elem* Cell::getElem(){
    return _elem;
};

void Cell::setType(Type type){
    _type = type;
};

Type Cell::getType(){
    return _type;
}

Cell &Cell::operator=(const Cell &other) {
    /*if(this->_elem){
        this->_elem = new Elem;
    }
    *(this->_elem) = *(other._elem);
    // TODO: копирование элемента клетки
     */

    if(this->_texture){
        this->_texture = new sf::Texture;
    }
    *(this->_texture) = *(other._texture);

    if(this->_sprite){
        this->_sprite = new sf::Sprite;
    }
    *(this->_sprite) = *(other._sprite);

    this->_type = other._type;
    this->_position = other._position;
    return *this;
}

Cell &Cell::operator=(Cell &&other) {

    //*(this->_elem) = *((Elem*)other._elem);
    if(this->_texture){
        this->_texture = new sf::Texture;
    }
    *(this->_texture) = *(other._texture);
    delete other._texture;

    if(this->_sprite){
        this->_sprite = new sf::Sprite;
    }
    *(this->_sprite) = *(other._sprite);
    delete other._sprite;

    this->_type = other._type;
    this->_position = other._position;
    return *this;
};