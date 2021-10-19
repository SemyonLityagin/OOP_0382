#ifndef GAME_CELL_H
#define GAME_CELL_H
#define WIDTH 32

#include "iostream"
#include "stdlib.h"
#include <SFML/Graphics.hpp>
#include "Elem/Elem.h"


enum class Type : unsigned short {
    NORMAL,
    WALL,
    ENTRY,
    EXIT,
    PLACE_OF_POWER
};

class Cell {
private:
    Elem* _elem = nullptr;
    Type _type;
    sf::Vector2i _position;
    sf::Sprite* _sprite;
    sf::Texture* _texture;

public:
    Cell(const std::string& filename, sf::Vector2i position, Elem* elem , Type type);
    Cell(const Cell&) = default;
    Cell(Cell&&) = default;
    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other);
    ~Cell();

    void setTexture(const std::string& filename);
    sf::Sprite* getSprite();
    void setElem(Elem* elem);
    Elem* getElem();
    void setType(Type type);
    Type getType();
};


#endif //GAME_CELL_H
