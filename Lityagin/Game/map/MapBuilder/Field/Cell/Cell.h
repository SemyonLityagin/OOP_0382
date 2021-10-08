#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <SFML/Graphics.hpp>
#include <cstring>
using namespace sf;

class Cell {
private:
    Texture texture;
    Sprite* sprite;
public:
    Cell();
    Cell(const Cell& other);
    Cell& operator = (const Cell& other);
    void SetTexture(const std::string& filename);
    void SetPosition(int x, int y);
    Sprite* GetSprite();
    ~Cell();
};

#endif //GAME_CELL_H
