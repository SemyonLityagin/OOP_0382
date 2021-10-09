#ifndef GAME_CELL_H
#define GAME_CELL_H
#define WIDTH 32

#include "iostream"
#include "stdlib.h"
#include <SFML/Graphics.hpp>

enum class Elem : unsigned short {
    EMPTY,
    FULL,
    PLAYER,
    EMENY,
    ITEM
};

enum class Type : unsigned short {
    NORMAL,
    WALL,
    ENTRY,
    EXIT
};

class Cell {
protected:
    Elem _elem;
    Type _type;
    sf::Vector2i _position;
    sf::Sprite* _sprite;
    sf::Texture* _texture;

public:
    Cell(const std::string& filename, sf::Vector2i position, Elem elem , Type type);
    Cell(const Cell&) = default;
    Cell(Cell&&) = default;
    ~Cell();

    void setTexture(const std::string& filename);
    sf::Sprite* getSprite();
    void setElem(Elem elem);
    Elem getElem();
    void setType(Type type);
    Type getType();
};


#endif //GAME_CELL_H
