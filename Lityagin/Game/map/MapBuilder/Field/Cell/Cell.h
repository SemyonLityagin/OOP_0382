#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <SFML/Graphics.hpp>
#include <cstring>

using namespace sf;
/*
 * Cell type:
 *      Exit - 3
 *      Wall - 2
 *      Floor - 1
 *      Enter - 0
 */
class Cell{
private:
    Texture texture;
    Sprite sprite;
    int type;
public:
    Cell();
    Cell(const Cell& other);
    Cell& operator = (const Cell& other);
    void SetTexture(const std::string& filename);
    void SetPosition(int x, int y);
    void SetType(int value);
    bool IsMovable();
    Sprite GetSprite();
    ~Cell();
};

#endif //GAME_CELL_H
