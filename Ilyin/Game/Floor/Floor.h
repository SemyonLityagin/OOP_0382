#ifndef GAME_FLOOR_H
#define GAME_FLOOR_H

#define WIDTH_OF_FLOOR 25
#define HEIGTH_OF_FLOOR 15
#define MIN_SIZE_OF_FLOOR 9


#include "Cell/Cell.h"

class Floor {
public:
    Cell*** cells;
    sf::Vector2i entry, exit;
    int width, height;


    Floor(int width, int height);
    Floor(const Floor& other);
    Floor& operator=(const Floor& other);
    Floor& operator=(Floor&& other);
    void Draw_Floor(sf::RenderWindow* window);
    ~Floor();
};


#endif //GAME_FLOOR_H
