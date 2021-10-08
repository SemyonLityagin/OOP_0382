#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Cell {
public:
    Texture* texture;
    Sprite* sprite;
    int x,y;
    Cell(int PosX, int PosY, const std::string& filename);
    ~Cell();
};

#endif //GAME_CELL_H
