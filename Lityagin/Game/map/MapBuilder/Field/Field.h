#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <SFML/Graphics.hpp>
#include "Cell/Cell.h"

#define Size 10

class Field{
public:
    Cell*** cells;
    Field();
    ~Field();
    void DrawCells(sf::RenderWindow* window);
};
#endif //GAME_FIELD_H
